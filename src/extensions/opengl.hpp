#ifdef XR_USE_GRAPHICS_API_OPENGL

#pragma once

#include "include/openxr/openxr.h"
#include "include/openxr/openxr_platform.h"
#include "../extension.hpp"

namespace StardustXR {
namespace OpenXR {

XrResult xrGetOpenGLGraphicsRequirementsKHR(XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR* graphicsRequirements);

static Extension OpenGLExtension = {
	.name = "XR_KHR_opengl_enable",
	.version = 10,
	.functions = {
		{"xrGetOpenGLGraphicsRequirementsKHR", (PFN_xrVoidFunction) xrGetOpenGLGraphicsRequirementsKHR},
	},
};

}
}

#endif
