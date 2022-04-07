#include "opengl.hpp"
#include "include/openxr/openxr.h"
#include <openxr/openxr.h>

namespace StardustXR {
namespace OpenXR {

XrResult xrGetOpenGLGraphicsRequirementsKHR(XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR* graphicsRequirements) {
	graphicsRequirements->minApiVersionSupported = XR_MAKE_VERSION(4, 5, 0);
	graphicsRequirements->maxApiVersionSupported = XR_MAKE_VERSION(4, 6, (1024-1));
	return XR_SUCCESS;
}

}
}