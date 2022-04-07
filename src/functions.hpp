#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "functions.hpp"
#include "include/openxr/openxr.h"

#include "apilayers.hpp"
#include "runtimeinterface.hpp"
#include "instance.hpp"
#include "stringify.hpp"
#include "system.hpp"

#include <string>
#include <unordered_map>

namespace StardustXR {
namespace OpenXR {

#define XR_FUNCTION(fn) {#fn, (PFN_xrVoidFunction) fn},

static std::unordered_map<std::string, PFN_xrVoidFunction> xrFunctionsNoInstance = {
	XR_FUNCTION(xrEnumerateApiLayerProperties)

	XR_FUNCTION(xrEnumerateInstanceExtensionProperties)
	XR_FUNCTION(xrGetInstanceProcAddr)
	XR_FUNCTION(xrCreateInstance)
};

static std::unordered_map<std::string, PFN_xrVoidFunction> xrFunctions = {
	XR_FUNCTION(xrEnumerateApiLayerProperties)
	XR_FUNCTION(xrEnumerateInstanceExtensionProperties)
	XR_FUNCTION(xrGetInstanceProcAddr)
	XR_FUNCTION(xrCreateInstance)
	XR_FUNCTION(xrGetInstanceProperties)
	XR_FUNCTION(xrDestroyInstance)

	XR_FUNCTION(xrResultToString)
	XR_FUNCTION(xrStructureTypeToString)

	XR_FUNCTION(xrGetSystem)
	XR_FUNCTION(xrGetSystemProperties)

	XR_FUNCTION(xrEnumerateViewConfigurationViews)

	XR_FUNCTION(xrCreateSession)
};

}
}
