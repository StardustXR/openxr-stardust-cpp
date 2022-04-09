#pragma once

#include "include/openxr/openxr.h"

namespace StardustXR {
namespace OpenXR {

struct XrStructureBase {
    XrStructureType       type;
    void* XR_MAY_ALIAS    next;
};

template<class T>
static T *getStructFromChain(const void *next, XrStructureType type) {
	XrStructureBase *current = (XrStructureBase *) next;
	while(current != NULL) {
		if(current->type == type)
			return (T *) current;
		current = (XrStructureBase *) current->next;
	}
	return nullptr;
}

}
}