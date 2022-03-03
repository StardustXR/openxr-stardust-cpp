#include "functions.hpp"
#include "include/openxr/openxr.h"
#include "runtimeinterface.hpp"
#include "instance.hpp"

std::unordered_map<std::string, PFN_xrVoidFunction> StardustXR::OpenXR::xrFunctionsNoInstance = {
	{"xrGetInstanceProcAddr", (PFN_xrVoidFunction) StardustXR::OpenXR::xrGetInstanceProcAddr},
	{"xrCreateInstance", (PFN_xrVoidFunction) StardustXR::OpenXR::Instance::xrCreateInstance},
};
std::unordered_map<std::string, PFN_xrVoidFunction> StardustXR::OpenXR::xrFunctions = {
	{"xrGetInstanceProcAddr", (PFN_xrVoidFunction) StardustXR::OpenXR::xrGetInstanceProcAddr},
	{"xrCreateInstance", (PFN_xrVoidFunction) StardustXR::OpenXR::Instance::xrCreateInstance},
};
