#include "../include/openxr/loader_interfaces.h"
#include <stdio.h>

namespace StardustXR{
namespace OpenXR{

XrResult xrGetInstanceProcAddr(XrInstance instance, const char *name, PFN_xrVoidFunction *function) {

}

}
}

XRAPI_ATTR XrResult XRAPI_CALL xrNegotiateLoaderRuntimeInterface(const XrNegotiateLoaderInfo *loaderInfo, XrNegotiateRuntimeRequest *runtimeRequest) {
	if (loaderInfo->structType != XR_LOADER_INTERFACE_STRUCT_LOADER_INFO ||
	    loaderInfo->structVersion != XR_LOADER_INFO_STRUCT_VERSION ||
	    loaderInfo->structSize != sizeof(XrNegotiateLoaderInfo)) {
		return XR_ERROR_INITIALIZATION_FAILED;
	}
	if (runtimeRequest->structType != XR_LOADER_INTERFACE_STRUCT_RUNTIME_REQUEST ||
	    runtimeRequest->structVersion != XR_CURRENT_LOADER_RUNTIME_VERSION ||
	    runtimeRequest->structSize != sizeof(XrNegotiateRuntimeRequest)) {
		return XR_ERROR_INITIALIZATION_FAILED;
	}

	uint16_t supported_major = XR_VERSION_MAJOR(XR_CURRENT_API_VERSION);

	uint32_t requested_min_major = loaderInfo->minInterfaceVersion;
	uint32_t requested_max_major = loaderInfo->maxInterfaceVersion;

	if (supported_major > requested_max_major || supported_major < requested_min_major) {
		printf("OpenXR doesn't support version %d < %d < %d\n", requested_min_major, supported_major, requested_max_major);
		return XR_ERROR_INITIALIZATION_FAILED;
	}

	runtimeRequest->getInstanceProcAddr = StardustXR::OpenXR::xrGetInstanceProcAddr;
	runtimeRequest->runtimeInterfaceVersion = XR_CURRENT_LOADER_RUNTIME_VERSION;
	runtimeRequest->runtimeApiVersion = XR_CURRENT_API_VERSION;

	printf("Stardust OpenXR Runtime loaded!");
	return XR_SUCCESS;
};