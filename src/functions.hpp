#pragma once

#include "../include/openxr/loader_interfaces.h"

#include <string>
#include <unordered_map>

namespace StardustXR {
namespace OpenXR {

extern std::unordered_map<std::string, PFN_xrVoidFunction> xrFunctions;
extern std::unordered_map<std::string, PFN_xrVoidFunction> xrFunctionsNoInstance;

}
}
