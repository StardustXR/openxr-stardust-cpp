#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "functions.hpp"
#include "include/openxr/openxr.h"

#include "apilayers.hpp"
#include "runtimeinterface.hpp"
#include "instance.hpp"

#include <string>
#include <unordered_map>

namespace StardustXR {
namespace OpenXR {

static std::unordered_map<std::string, PFN_xrVoidFunction> xrFunctionsNoInstance = {
	{"xrEnumerateApiLayerProperties", (PFN_xrVoidFunction) xrEnumerateApiLayerProperties},

	{"xrEnumerateInstanceExtensionProperties", (PFN_xrVoidFunction) xrEnumerateInstanceExtensionProperties},
	{"xrCreateInstance", (PFN_xrVoidFunction) xrCreateInstance},
};

static std::unordered_map<std::string, PFN_xrVoidFunction> xrFunctions = {
	{"xrEnumerateApiLayerProperties", (PFN_xrVoidFunction) xrEnumerateApiLayerProperties},

	{"xrEnumerateInstanceExtensionProperties", (PFN_xrVoidFunction) xrEnumerateInstanceExtensionProperties},
	{"xrGetInstanceProcAddr", (PFN_xrVoidFunction) xrGetInstanceProcAddr},
	{"xrCreateInstance", (PFN_xrVoidFunction) xrCreateInstance},
};

}
}
