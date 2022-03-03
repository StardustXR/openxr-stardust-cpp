#include "instance.hpp"
#include "include/openxr/openxr.h"
#include "src/scenegraph.hpp"

#include <stardustxr/common/messenger.hpp>
#include <stdint.h>

namespace StardustXR {
namespace OpenXR {


XrResult Instance::xrCreateInstance(const XrInstanceCreateInfo* createInfo, XrInstance* instance) {
	if(createInfo->type != XR_TYPE_INSTANCE_CREATE_INFO) return XR_ERROR_VALIDATION_FAILURE;
	
	// TODO: check extensions

	Instance *stardustInstance = new Instance(*createInfo);
	*instance = (XrInstance)(uint64_t)(uintptr_t)(stardustInstance);
	return XR_SUCCESS;
}

Instance::Instance(XrInstanceCreateInfo info) {
	printf("Client starting...\n");
	int fd;
	if (!(fd = StardustXR::ConnectClient())) {
		perror("Client failed to connect to server");
	}

	messenger.reset(new Messenger(fd, &scenegraph));
	messenger->startHandler();

	// messenger->sendSignal(
	// 	"/",
	// 	"subscribeLogicStep",
	// 	FLEX_ARGS(
	// 		FLEX_STRING(std::string(""))
	// 		FLEX_STRING(std::string("logicStep"))
	// 	)
	// );
	// scenegraph.addMethod("logicStep", &FlexDummy);
}

}
}