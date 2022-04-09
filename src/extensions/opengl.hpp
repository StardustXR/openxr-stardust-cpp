#include "src/extensions/graphics.hpp"
#ifdef XR_USE_GRAPHICS_API_OPENGL

#pragma once

#include "include/openxr/openxr.h"
#include "platformincludes.hpp"
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

class OpenGLGraphicsAPI : public GraphicsAPI {
protected:
	OpenGLGraphicsAPI();
	virtual ~OpenGLGraphicsAPI();
public:
	virtual void makeContextCurrent() = 0;
	virtual void restoreContext() = 0;
};

#ifdef XR_USE_PLATFORM_XLIB

class OpenGLXLibGraphicsAPI : public GraphicsAPI {
public:
	OpenGLXLibGraphicsAPI(XrGraphicsBindingOpenGLXlibKHR *graphicsBinding);
	virtual ~OpenGLXLibGraphicsAPI();
	void makeContextCurrent();
	void restoreContext();
private:
	struct Context {
    	Display           *xDisplay;
    	GLXDrawable        glxDrawable;
    	GLXContext         glxContext;
	};

	Context current;
	Context stored;

    uint32_t           visualid;
    GLXFBConfig        glxFBConfig;
};

#endif

}
}

#endif
