#include "system.hpp"
#include "instance.hpp"

#include "include/openxr/openxr.h"
#include <map>

namespace StardustXR {
namespace OpenXR {

XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo* getInfo, XrSystemId* systemId) {
	if(getInfo->type != XR_TYPE_SYSTEM_GET_INFO)                   return XR_ERROR_VALIDATION_FAILURE;
	if(getInfo->formFactor != XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY) return XR_ERROR_FORM_FACTOR_UNSUPPORTED;

	*systemId = getInfo->formFactor;
	return XR_SUCCESS;
}

}
}
