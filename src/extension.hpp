#pragma once

#include "include/openxr/openxr.h"
#include <map>
#include <string>
#include <vector>

namespace StardustXR {
namespace OpenXR {

struct Extension {
	std::string name;
	uint32_t version;
	std::map<std::string, PFN_xrVoidFunction> functions;

	static std::vector<Extension> clientExtensions; // Extensions that don't depend on the server's capabilities such as graphics extensions
};

}
}
