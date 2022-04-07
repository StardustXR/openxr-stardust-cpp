#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "include/openxr/openxr.h"
#include <memory>

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

private:
	Instance *instance;
};

}
}
