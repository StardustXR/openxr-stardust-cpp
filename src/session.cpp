#include "session.hpp"
#include "instance.hpp"
#include "include/openxr/openxr.h"
#include <stardustxr/common/flex.hpp>

namespace StardustXR {
namespace OpenXR {


XrResult xrCreateSession(XrInstance instance, const XrSessionCreateInfo *createInfo, XrSession *session) {
	if(createInfo->type != XR_TYPE_SESSION_CREATE_INFO) return XR_ERROR_VALIDATION_FAILURE;

	XrResult createResult;
	Instance *stardustInstance = reinterpret_cast<Instance *>(instance);
	Session *stardustSession = new Session(stardustInstance, *createInfo);
	createResult = stardustSession->createResult;
	if(createResult != XR_SUCCESS) {
		delete stardustSession;
		return createResult;
	}

	*session = (XrSession)(uintptr_t)(stardustSession);
	return XR_SUCCESS;
}
XrResult xrDestroySession(XrSession xrSession) {
	Session *session = reinterpret_cast<Session *>(xrSession);
	if(session == nullptr)
		return XR_ERROR_HANDLE_INVALID;
	delete session;
	return XR_SUCCESS;
}

Session::Session(Instance *instance, XrSessionCreateInfo info) {
	std::vector<uint8_t> serverStatus = instance->getMessenger()->executeRemoteMethodSync(
		"/openxr/instance",
		"createSession",
		FLEX_ARGS(
			FLEX_UINT(info.createFlags)
		)
	);
	createResult = (XrResult) flexbuffers::GetRoot(serverStatus).AsInt32();
}
Session::~Session() {
	instance->getMessenger()->sendSignal(
		"/openxr/instance/session",
		"destroy",
		FLEX_ARG(FLEX_NULL)
	);
}

}
}
