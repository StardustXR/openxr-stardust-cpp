#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "include/openxr/openxr.h"
#include <memory>

#include "extension.hpp"

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

	std::unordered_map<std::string, PFN_xrVoidFunction> functions;
private:
	std::vector<std::unique_ptr<Extension>> extensions;
	std::unique_ptr<Messenger> messenger;
	Scenegraph scenegraph;
};

}
}
