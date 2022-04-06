#pragma once

#include "include/openxr/openxr.h"

namespace StardustXR {
namespace OpenXR {

XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo* getInfo, XrSystemId* systemId);
XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId, XrSystemProperties *properties);

}
}