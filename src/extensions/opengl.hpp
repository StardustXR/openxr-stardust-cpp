#ifdef XR_USE_GRAPHICS_API_OPENGL

#pragma once

#include "include/openxr/openxr.h"
#include "include/openxr/openxr_platform.h"
#include "../extension.hpp"

namespace StardustXR {
namespace OpenXR {

XrResult xrGetOpenGLGraphicsRequirementsKHR(XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR* graphicsRequirements);


#define XR_FUNCTION(fn) {#fn, (PFN_xrVoidFunction) fn},

static Extension OpenGLExtension = {
	.name = "XR_KHR_opengl_enable",
	.version = 10,
	.functions = {
		XR_FUNCTION(xrGetOpenGLGraphicsRequirementsKHR)
	},
};

#undef XR_FUNCTION

}
}

#endif
