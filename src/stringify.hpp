#pragma once

#include "include/openxr/openxr.h"

namespace StardustXR {
namespace OpenXR {

XrResult xrResultToString(XrInstance instance, XrResult value, char *buffer);
XrResult xrStructureTypeToString(XrInstance instance, XrStructureType value, char *buffer);

}
}
