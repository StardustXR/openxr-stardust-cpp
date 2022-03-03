#include "instance.hpp"
#include "functions.hpp"
#include "extensions.hpp"
#include "include/openxr/openxr.h"
#include "include/openxr/openxr_reflection.h"
#include "src/scenegraph.hpp"

#include <cstddef>
#include <cstdio>
#include <stardustxr/common/flex.hpp>
#include <stdint.h>
#include <vector>


namespace StardustXR {
namespace OpenXR {

XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name, PFN_xrVoidFunction *function) {
	*function = nullptr;

	const std::string nameStr = std::string(name);
	printf("Trying to get address \"%s\" from instance %p\n", name, instance);
	fflush(stdout);
	auto mapFunction = (instance == XR_NULL_HANDLE ? xrFunctionsNoInstance : xrFunctions).find(nameStr);
	if(mapFunction != xrFunctions.end()) {
		*function = mapFunction->second;
		return XR_SUCCESS;
	}
	return XR_ERROR_FUNCTION_UNSUPPORTED;
}

XrResult xrEnumerateInstanceExtensionProperties(const char* layerName, uint32_t propertyCapacityInput, uint32_t* propertyCountOutput, XrExtensionProperties* properties) {
	if(propertyCountOutput == NULL)
		return XR_ERROR_VALIDATION_FAILURE;
	if(properties == nullptr)
		*propertyCountOutput = extensions.size();
	if(propertyCapacityInput == 0)
		return XR_SUCCESS;
	if(propertyCapacityInput < *propertyCountOutput)
		return XR_ERROR_SIZE_INSUFFICIENT;
	if(properties != nullptr) {
		uint32_t i = 0;
		for(auto extension : extensions) {
			properties[i] = XrExtensionProperties {
				.type = XR_TYPE_EXTENSION_PROPERTIES,
				.next = NULL,
				.extensionVersion = extension.second,
			};
			extension.first.copy(properties[i].extensionName, XR_MAX_EXTENSION_NAME_SIZE);
			i++;
		}
	}
	//This is a stub

	return XR_SUCCESS;
}

XrResult xrCreateInstance(const XrInstanceCreateInfo* createInfo, XrInstance* instance) {
	if(createInfo->type != XR_TYPE_INSTANCE_CREATE_INFO) return XR_ERROR_VALIDATION_FAILURE;
	
	// TODO: check extensions

	Instance *stardustInstance = new Instance(*createInfo);
	*instance = (XrInstance)(uint64_t)(uintptr_t)(stardustInstance);
	return XR_SUCCESS;
}
XrResult xrDestroyInstance(XrInstance xrInstance) {
	Instance *instance = reinterpret_cast<Instance *>(xrInstance);
	if(instance == nullptr)
		return XR_ERROR_HANDLE_INVALID;
	delete instance;
	return XR_SUCCESS;
}

Instance::Instance(XrInstanceCreateInfo info) {
	printf("Client starting...\n");
	int fd;
	if (!(fd = StardustXR::ConnectClient())) {
		perror("Client failed to connect to server");
	}

	messenger.reset(new Messenger(fd, &scenegraph));
	messenger->startHandler();

	// messenger->sendSignal(
	// 	"/",
	// 	"subscribeLogicStep",
	// 	FLEX_ARGS(
	// 		FLEX_STRING(std::string(""))
	// 		FLEX_STRING(std::string("logicStep"))
	// 	)
	// );
	// scenegraph.addMethod("logicStep", &FlexDummy);
}

Instance::~Instance() {
	messenger->sendSignal("/", "disconnect", FLEX_ARG(FLEX_NULL));
}

}
}
