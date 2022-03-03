#pragma once

#include "include/openxr/openxr.h"

extern "C" {
	#include "../include/openxr/loader_interfaces.h"
	XRAPI_ATTR XrResult XRAPI_CALL xrNegotiateLoaderRuntimeInterface(const XrNegotiateLoaderInfo *loaderInfo, XrNegotiateRuntimeRequest *runtimeRequest);
}
