#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "include/openxr/openxr.h"
#include <memory>
#include <openxr/openxr.h>

#include <stardustxr/client/connector.hpp>
#include <stardustxr/common/messenger.hpp>
#include "scenegraph.hpp"

namespace StardustXR {
namespace OpenXR {

extern "C" {
	XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name, PFN_xrVoidFunction *function);
	XrResult xrEnumerateInstanceExtensionProperties(const char* layerName, uint32_t propertyCapacityInput, uint32_t* propertyCountOutput, XrExtensionProperties* properties);
}

class Instance {
public:
	static XrResult xrCreateInstance(const XrInstanceCreateInfo* createInfo, XrInstance* instance);
	XrResult result = XR_SUCCESS;
private:
	Instance(XrInstanceCreateInfo info);
	std::unique_ptr<Messenger> messenger;
	Scenegraph scenegraph;
};

}
}
