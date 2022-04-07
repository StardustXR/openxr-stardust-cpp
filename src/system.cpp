#include "system.hpp"
#include "instance.hpp"

#include "include/openxr/openxr.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <flatbuffers/flexbuffers.h>
#include <map>
#include <stardustxr/common/flex.hpp>

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

XrResult xrEnumerateViewConfigurationViews(XrInstance instance, XrSystemId systemId, XrViewConfigurationType viewConfigurationType, uint32_t viewCapacityInput, uint32_t *viewCountOutput, XrViewConfigurationView *views) {
	if(!viewCountOutput) return XR_ERROR_VALIDATION_FAILURE;


	Instance *instancePtr = reinterpret_cast<Instance *>(instance);
	const std::vector<uint8_t> serverViewConfigsData = instancePtr->getMessenger()->executeRemoteMethodSync(
		"/openxr/instance/system",
		"getViewConfigurations",
		FLEX_ARG(FLEX_NULL)
	);
	const flexbuffers::Vector serverViewConfigs = flexbuffers::GetRoot(serverViewConfigsData).AsVector();
	if(serverViewConfigs.IsTheEmptyVector())
		return XR_ERROR_RUNTIME_FAILURE;

	if(viewConfigurationType != serverViewConfigs.size()) return XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED;

	if(viewCapacityInput == 0) {
		*viewCountOutput = serverViewConfigs.size();
		return XR_SUCCESS;
	}

	if(viewCapacityInput < serverViewConfigs.size()) return XR_ERROR_SIZE_INSUFFICIENT;

	for(uint i=0; i<2; ++i) {
		views[i].type = XR_TYPE_VIEW_CONFIGURATION_VIEW;
		views[i].next = nullptr;

		flexbuffers::Vector serverViewConfig = serverViewConfigs[i].AsVector();
		views[i].recommendedImageRectWidth  = serverViewConfig[0].AsUInt32();
		views[i].maxImageRectWidth          = serverViewConfig[1].AsUInt32();
		views[i].recommendedImageRectHeight = serverViewConfig[2].AsUInt32();
		views[i].maxImageRectHeight         = serverViewConfig[3].AsUInt32();

		views[i].maxSwapchainSampleCount = 1;
		views[i].recommendedSwapchainSampleCount = 1;
	}

	return XR_SUCCESS;
}

}
}
