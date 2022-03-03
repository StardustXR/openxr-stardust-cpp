#pragma once

#include "include/openxr/openxr.h"


namespace StardustXR {
namespace OpenXR {

XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name, PFN_xrVoidFunction *function);

}
}