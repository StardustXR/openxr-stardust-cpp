#include "functions.hpp"
#include "include/openxr/openxr.h"

#include "apilayers.hpp"
#include "runtimeinterface.hpp"
#include "instance.hpp"

std::unordered_map<std::string, PFN_xrVoidFunction> StardustXR::OpenXR::xrFunctionsNoInstance = {
	{"xrEnumerateApiLayerProperties", (PFN_xrVoidFunction) StardustXR::OpenXR::xrEnumerateApiLayerProperties},

	{"xrEnumerateInstanceExtensionProperties", (PFN_xrVoidFunction) StardustXR::OpenXR::xrEnumerateInstanceExtensionProperties},
	{"xrCreateInstance", (PFN_xrVoidFunction) StardustXR::OpenXR::Instance::xrCreateInstance},
};

std::unordered_map<std::string, PFN_xrVoidFunction> StardustXR::OpenXR::xrFunctions = {
	{"xrEnumerateApiLayerProperties", (PFN_xrVoidFunction) StardustXR::OpenXR::xrEnumerateApiLayerProperties},

	{"xrEnumerateInstanceExtensionProperties", (PFN_xrVoidFunction) StardustXR::OpenXR::xrEnumerateInstanceExtensionProperties},
	{"xrGetInstanceProcAddr", (PFN_xrVoidFunction) StardustXR::OpenXR::xrGetInstanceProcAddr},
	{"xrCreateInstance", (PFN_xrVoidFunction) StardustXR::OpenXR::Instance::xrCreateInstance},
};
