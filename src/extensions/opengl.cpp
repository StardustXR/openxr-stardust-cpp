#include "opengl.hpp"
#include "include/openxr/openxr.h"
#include <GL/glx.h>
#include <openxr/openxr.h>

namespace StardustXR {
namespace OpenXR {

XrResult xrGetOpenGLGraphicsRequirementsKHR(XrInstance instance, XrSystemId systemId, XrGraphicsRequirementsOpenGLKHR* graphicsRequirements) {
	graphicsRequirements->minApiVersionSupported = XR_MAKE_VERSION(4, 5, 0);
	graphicsRequirements->maxApiVersionSupported = XR_MAKE_VERSION(4, 6, (1024-1));
	return XR_SUCCESS;
}

OpenGLGraphicsAPI::OpenGLGraphicsAPI() {}
OpenGLGraphicsAPI::~OpenGLGraphicsAPI() {}

#ifdef XR_USE_PLATFORM_XLIB

OpenGLXLibGraphicsAPI::OpenGLXLibGraphicsAPI(XrGraphicsBindingOpenGLXlibKHR *graphicsBinding) :
current({
	graphicsBinding->xDisplay,
	graphicsBinding->glxDrawable,
	graphicsBinding->glxContext
}),
visualid(graphicsBinding->visualid),
glxFBConfig(graphicsBinding->glxFBConfig) {}
OpenGLXLibGraphicsAPI::~OpenGLXLibGraphicsAPI() {}

void OpenGLXLibGraphicsAPI::makeContextCurrent() {
	stored.xDisplay = glXGetCurrentDisplay();
	stored.glxDrawable = glXGetCurrentDrawable();
	stored.glxContext = glXGetCurrentContext();
	glXMakeCurrent(current.xDisplay, current.glxDrawable, current.glxContext);
}
void OpenGLXLibGraphicsAPI::restoreContext() {
	glXMakeCurrent(stored.xDisplay, stored.glxDrawable, stored.glxContext);
}

#endif

}
}