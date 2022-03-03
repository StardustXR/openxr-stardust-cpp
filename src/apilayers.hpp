#pragma once

#include "include/openxr/openxr.h"

namespace StardustXR {
namespace OpenXR {

XrResult xrEnumerateApiLayerProperties(uint32_t propertyCapacityInput, uint32_t* propertyCountOutput, XrApiLayerProperties* properties) {
	if (propertyCountOutput != nullptr)
		*propertyCountOutput = 0;
	
	return XR_SUCCESS;
}

}
}