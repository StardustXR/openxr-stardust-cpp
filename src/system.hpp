#pragma once

#include "include/openxr/openxr.h"

namespace StardustXR {
namespace OpenXR {

XrResult xrGetSystem(XrInstance instance, const XrSystemGetInfo* getInfo, XrSystemId* systemId);

class System {
public:
	System(const XrFormFactor formFactor);
	const XrFormFactor formFactor;
};

}
}