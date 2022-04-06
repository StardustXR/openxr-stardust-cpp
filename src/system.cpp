#include "system.hpp"
#include "instance.hpp"

#include "include/openxr/openxr.h"
#include <cstdio>
#include <cstring>
#include <map>

namespace StardustXR {
namespace OpenXR {

XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo* getInfo, XrSystemId* systemId) {
	if(getInfo->type != XR_TYPE_SYSTEM_GET_INFO)                   return XR_ERROR_VALIDATION_FAILURE;
	if(getInfo->formFactor != XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY) return XR_ERROR_FORM_FACTOR_UNSUPPORTED;

	*systemId = getInfo->formFactor;
	return XR_SUCCESS;
}

XrResult xrGetSystemProperties(XrInstance instance, XrSystemId systemId, XrSystemProperties *properties) {
	properties->systemId = systemId;
	properties->vendorId = 0; // Edit this when we have a proper vendor ID
	strncpy(properties->systemName, "Stardust XR", XR_MAX_SYSTEM_NAME_SIZE);

	properties->graphicsProperties.maxLayerCount = XR_MIN_COMPOSITION_LAYERS_SUPPORTED;
	properties->graphicsProperties.maxSwapchainImageWidth = 1024 * 16;
	properties->graphicsProperties.maxSwapchainImageHeight = 1024 * 16;
	properties->trackingProperties.positionTracking = true;
	properties->trackingProperties.orientationTracking = true;

	return XR_SUCCESS;
}

}
}
