#include "../extension.hpp"

#include "opengl.hpp"

namespace StardustXR {
namespace OpenXR {

std::vector<Extension> Extension::clientExtensions = {
#ifdef XR_USE_GRAPHICS_API_OPENGL
	OpenGLExtension
#endif
};

}
}