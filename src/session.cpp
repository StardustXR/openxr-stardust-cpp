#include "session.hpp"
#include "instance.hpp"
#include "src/extensions/opengl.hpp"
#include "util.hpp"
#include "include/openxr/openxr.h"
#include "extensions/platformincludes.hpp"
#include <flatbuffers/flexbuffers.h>
#include <stardustxr/common/flex.hpp>
#include <vector>

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



Session::Session(Instance *instance, XrSessionCreateInfo info) :
instance(instance) {
	std::vector<uint8_t> serverStatus = instance->getMessenger()->executeRemoteMethodSync(
		"/openxr/instance",
		"createSession",
		FLEX_ARGS(
			FLEX_UINT(info.createFlags)
		)
	);
	createResult = (XrResult) flexbuffers::GetRoot(serverStatus).AsInt32();

	if(createResult == XR_SUCCESS) {
	
	#ifdef XR_USE_GRAPHICS_API_OPENGL
		#ifdef XR_USE_PLATFORM_XLIB

		if(!graphicsAPI.get() && instance->hasExtension(XR_KHR_OPENGL_ENABLE_EXTENSION_NAME)) {
			XrGraphicsBindingOpenGLXlibKHR *binding = getStructFromChain<XrGraphicsBindingOpenGLXlibKHR>(info.next, XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR);
			if(binding)
				graphicsAPI.reset(new OpenGLXLibGraphicsAPI(binding));
		}

		#endif
	#endif

		if(!graphicsAPI.get())
			createResult = XR_ERROR_GRAPHICS_DEVICE_INVALID;
	}
}
Session::~Session() {
	instance->getMessenger()->sendSignal(
		"/openxr/instance/session",
		"destroy",
		FLEX_ARG(FLEX_NULL)
	);
}

std::vector<XrReferenceSpaceType> Session::getSupportedReferenceSpaces() {
	std::vector<uint8_t> referenceSpacesData = instance->getMessenger()->executeRemoteMethodSync(
		"/openxr/instance/session",
		"getReferenceSpaces",
		FLEX_ARG(FLEX_NULL)
	);
	flexbuffers::TypedVector flexVec = flexbuffers::GetRoot(referenceSpacesData).AsTypedVector();
	std::vector<XrReferenceSpaceType> supportedReferenceSpaces;
	for(uint i=0; i<flexVec.size(); ++i) {
		supportedReferenceSpaces.push_back((XrReferenceSpaceType) flexVec[i].AsUInt32());
	}
	return supportedReferenceSpaces;
}
bool Session::referenceSpaceTypeSupported(XrReferenceSpaceType type) {
	std::vector<XrReferenceSpaceType> supportedReferenceSpaces = getSupportedReferenceSpaces();
	return std::find(supportedReferenceSpaces.begin(), supportedReferenceSpaces.end(), type) != supportedReferenceSpaces.end();
}

}
}
