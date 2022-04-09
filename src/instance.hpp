#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "include/openxr/openxr.h"
#include <memory>

#include "extension.hpp"
#include "session.hpp"

#include <stardustxr/client/connector.hpp>
#include <stardustxr/common/messenger.hpp>
#include "scenegraph.hpp"

namespace StardustXR {
namespace OpenXR {

XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name, PFN_xrVoidFunction *function);
XrResult xrEnumerateInstanceExtensionProperties(const char* layerName, uint32_t propertyCapacityInput, uint32_t* propertyCountOutput, XrExtensionProperties* properties);

XrResult xrCreateInstance(const XrInstanceCreateInfo* createInfo, XrInstance* instance);
XrResult xrGetInstanceProperties(XrInstance instance, XrInstanceProperties *instanceProperties);
XrResult xrDestroyInstance(XrInstance instance);

class Instance {
public:
	Instance(XrInstanceCreateInfo info);
	XrResult createResult = XR_SUCCESS;
	~Instance();

	Messenger *getMessenger();

	bool hasExtension(std::string extensionName);

	std::unordered_map<std::string, PFN_xrVoidFunction> functions;
	std::unordered_map<std::string, std::unique_ptr<Extension>> extensions;
private:
	std::unique_ptr<Messenger> messenger;
	Scenegraph scenegraph;
};

}
}
