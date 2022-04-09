#pragma once

#include "../include/openxr/loader_interfaces.h"
#include "include/openxr/openxr.h"
#include <algorithm>
#include <memory>
#include <string>

#include "session.hpp"

namespace StardustXR {
namespace OpenXR {

XrResult xrCreateReferenceSpace(XrSession session, const XrReferenceSpaceCreateInfo *createInfo, XrSpace *space);
XrResult xrDestroySpace(XrSpace space);

// class Session;
class Space {
public:
	Space(Session *session, std::string parent, XrPosef pose);
	XrResult createResult = XR_SUCCESS;
	~Space();

	const std::string spaceName;

private:
	Session *const session;
};

}
}
