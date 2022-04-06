#pragma once

#include "include/openxr/openxr.h"

namespace StardustXR {
namespace OpenXR {

static XrResult xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput, uint32_t* propertyCountOutput, XrApiLayerProperties* properties) {
	if (propertyCountOutput != nullptr)
		*propertyCountOutput = 1;
	
	return XR_SUCCESS;
}

}
}