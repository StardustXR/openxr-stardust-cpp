#include "instance.hpp"
#include "functions.hpp"
#include "extension.hpp"
#include "include/openxr/openxr.h"
#include "include/openxr/openxr_reflection.h"
#include "src/extension.hpp"
#include "src/scenegraph.hpp"

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <flatbuffers/flexbuffers.h>
#include <stardustxr/common/flex.hpp>
#include <stardustxr/common/messenger.hpp>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>


namespace StardustXR {
namespace OpenXR {

// https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProcAddr
XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name, PFN_xrVoidFunction *function) {
	*function = nullptr;

	const std::string nameStr = std::string(name);
	printf("Trying to get address \"%s\" from instance %p\n", name, instance);
	fflush(stdout);

	std::unordered_map<std::string, PFN_xrVoidFunction> *functions;
	if(instance != XR_NULL_HANDLE) {
		Instance *instancePtr = reinterpret_cast<Instance *>(instance);
		functions = &instancePtr->functions;
	} else
		functions = &xrFunctionsNoInstance;

	auto mapIt = functions->find(nameStr);
	if(mapIt != functions->end()) {
		*function = mapIt->second;
		return XR_SUCCESS;
	}
	return XR_ERROR_FUNCTION_UNSUPPORTED;
}

// https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrEnumerateInstanceExtensionProperties
XrResult xrEnumerateInstanceExtensionProperties(const char* layerName, uint32_t propertyCapacityInput, uint32_t* propertyCountOutput, XrExtensionProperties* properties) {
	if(propertyCountOutput == NULL)
		return XR_ERROR_VALIDATION_FAILURE;
	// if(propertyCapacityInput == 0)
		// return XR_SUCCESS;

	std::vector<Extension> extensions;
	extensions.insert(extensions.end(), Extension::clientExtensions.begin(), Extension::clientExtensions.end());
	// Connect to Stardust server to get valid extensions
	
	if(properties == nullptr)
		*propertyCountOutput = extensions.size();
	if(propertyCapacityInput < *propertyCountOutput)
		return XR_ERROR_SIZE_INSUFFICIENT;
	if(properties != nullptr) {
		uint32_t i = 0;
		for(Extension &extension : extensions) {
			properties[i] = XrExtensionProperties {
				.type = XR_TYPE_EXTENSION_PROPERTIES,
				.next = NULL,
				.extensionVersion = extension.version,
			};
			extension.name.copy(properties[i].extensionName, XR_MAX_EXTENSION_NAME_SIZE);
			i++;
		}
	}
	return XR_SUCCESS;
}

// https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrCreateInstance
XrResult xrCreateInstance(const XrInstanceCreateInfo* createInfo, XrInstance* instance) {
	if(createInfo->type != XR_TYPE_INSTANCE_CREATE_INFO) return XR_ERROR_VALIDATION_FAILURE;

	XrResult createResult;
	Instance *stardustInstance = new Instance(*createInfo);
	createResult = stardustInstance->createResult;
	if(createResult != XR_SUCCESS) {
		delete stardustInstance;
		return createResult;
	}

	*instance = (XrInstance)(uintptr_t)(stardustInstance);
	return XR_SUCCESS;
}
// https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrGetInstanceProperties
XrResult xrGetInstanceProperties(XrInstance instance, XrInstanceProperties *instanceProperties) {
	instanceProperties->type = XR_TYPE_INSTANCE_PROPERTIES;
	instanceProperties->runtimeVersion = 1;
	strncpy(instanceProperties->runtimeName, "Stardust XR", XR_MAX_RUNTIME_NAME_SIZE);
	return XR_SUCCESS;
}
// https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#xrDestroyInstance
XrResult xrDestroyInstance(XrInstance xrInstance) {
	Instance *instance = reinterpret_cast<Instance *>(xrInstance);
	if(instance == nullptr)
		return XR_ERROR_HANDLE_INVALID;
	delete instance;
	return XR_SUCCESS;
}

Instance::Instance(XrInstanceCreateInfo info) {
	printf("Client starting...\n");
	int fd = StardustXR::ConnectClient();
	if (!fd) {
		perror("Client failed to connect to server");
		createResult = XR_ERROR_INITIALIZATION_FAILED;
	} else {
		messenger.reset(new Messenger(fd, &scenegraph));
		messenger->startHandler();

		// TODO: check extensions

		{
			std::vector<uint8_t> serverStatus = messenger->executeRemoteMethodSync(
				"/openxr",
				"createInstance",
				FLEX_ARGS(
					FLEX_UINT(info.createFlags)
					FLEX_STRING(info.applicationInfo.applicationName)
					FLEX_UINT(info.applicationInfo.applicationVersion)
					FLEX_STRING(info.applicationInfo.engineName)
					FLEX_UINT(info.applicationInfo.engineVersion)
					FLEX_UINT(info.applicationInfo.apiVersion)
				)
			);
			createResult = (XrResult) flexbuffers::GetRoot(serverStatus).AsInt32();
		}

		if(createResult == XR_SUCCESS) {
			functions.insert(xrFunctions.begin(), xrFunctions.end());
			for(Extension &extension : Extension::clientExtensions) {
				functions.insert(extension.functions.begin(), extension.functions.end());
			}
		}
	}
}

Instance::~Instance() {
	messenger->sendSignal("/", "disconnect", FLEX_ARG(FLEX_NULL));
}

Messenger *Instance::getMessenger() {
	return messenger.get();
}

}
}
