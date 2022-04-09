#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "include/openxr/openxr.h"
#include <algorithm>
#include <memory>
#include <vector>

#include "extensions/graphics.hpp"

namespace StardustXR {
namespace OpenXR {

XrResult xrCreateSession(XrInstance instance, const XrSessionCreateInfo *createInfo, XrSession *session);
XrResult xrDestroySession(XrSession session);

class Instance;
class Session {
public:
	Session(Instance *instance, XrSessionCreateInfo info);
	XrResult createResult = XR_SUCCESS;
	~Session();

	std::vector<XrReferenceSpaceType> getSupportedReferenceSpaces();
	bool referenceSpaceTypeSupported(XrReferenceSpaceType type);

	std::unique_ptr<GraphicsAPI> graphicsAPI;
	Instance *const instance;
};

}
}
