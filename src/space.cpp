#include "space.hpp"
#include "include/openxr/openxr.h"
#include "instance.hpp"
#include "session.hpp"
#include "stringify.hpp"
#include <stardustxr/common/flex.hpp>
#include <string>

namespace StardustXR {
namespace OpenXR {

static uint spaceNumber = 0;

XrResult xrCreateReferenceSpace(XrSession xrSession, const XrReferenceSpaceCreateInfo *createInfo, XrSpace *xrSpace) {
	Session *session = reinterpret_cast<Session *>(xrSession);
	if(!session->referenceSpaceTypeSupported(createInfo->referenceSpaceType)) return XR_ERROR_REFERENCE_SPACE_UNSUPPORTED;
	Space *space = new Space(
		session, 
		std::string("/openxr/instance/session/referenceSpace")+std::to_string((uint)createInfo->referenceSpaceType),
		createInfo->poseInReferenceSpace
	);
	*xrSpace = (XrSpace) space;
	return XR_SUCCESS;
}
XrResult xrDestroySpace(XrSpace xrSpace) {
	Space *space = reinterpret_cast<Space *>(xrSpace);
	delete space;
	return XR_SUCCESS;
}

Space::Space(Session *session, std::string parent, XrPosef pose) :
spaceName(std::string("space")+std::to_string(spaceNumber)),
session(session) {
	session->instance->getMessenger()->sendSignal(
		"/spatial",
		"createSpatial",
		FLEX_ARGS(
			FLEX_STRING(spaceName)
			FLEX_STRING(parent)
			FLEX_VEC3(pose.position)
			FLEX_QUAT(pose.orientation)
			FLEX_TYPED_VEC(
				FLEX_FLOAT(1)
				FLEX_FLOAT(1)
				FLEX_FLOAT(1)
			)
			FLEX_BOOL(false)
			FLEX_BOOL(false)
			FLEX_BOOL(false)
			FLEX_BOOL(false)
		)
	);
	spaceNumber++;
}
Space::~Space() {
	session->instance->getMessenger()->sendSignal(
		std::string("/spatial/spatial/")+spaceName,
		"destroy",
		FLEX_ARG(FLEX_NULL)
	);
}

}
}