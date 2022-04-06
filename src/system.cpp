#include "system.hpp"
#include "instance.hpp"

#include "include/openxr/openxr.h"
#include <map>

namespace StardustXR {
namespace OpenXR {

std::map<XrFormFactor, System *> systems = {
	// {XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY, }
};

XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo* getInfo, XrSystemId* systemId) {
	if(getInfo->type != XR_TYPE_SYSTEM_GET_INFO)                   return XR_ERROR_VALIDATION_FAILURE;
	if(getInfo->formFactor != XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY) return XR_ERROR_FORM_FACTOR_UNSUPPORTED;
	Instance *instancePtr = reinterpret_cast<Instance *>(instance);
	*systemId = (intptr_t) systems[getInfo->formFactor];
	return XR_SUCCESS;
}

System::System(const XrFormFactor formFactor) :
formFactor(formFactor) {}

}
}
