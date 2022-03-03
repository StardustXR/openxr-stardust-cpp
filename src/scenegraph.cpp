#include "scenegraph.hpp"
#include "include/openxr/openxr.h"
#include <cstdint>
#include <mutex>

namespace StardustXR {
namespace OpenXR {

Scenegraph::Scenegraph() {}

void Scenegraph::addMethod(std::string name, Method method) {
	std::lock_guard<std::mutex> lock(methodsMutex);
	methods[name] = method;
}

void Scenegraph::removeMethod(std::string name) {
	std::lock_guard<std::mutex> lock(methodsMutex);
	auto method = methods.find(name);
	if(method != methods.end())
		methods.erase(method);
}

void Scenegraph::sendSignal(std::string, std::string methodName, flexbuffers::Reference data) {
	std::unique_lock lock(methodsMutex);
	if(methods.find(methodName) != methods.end()) {
		Method *method = &methods[methodName];
		lock.unlock();
		(void)(*method)(data, false);
	} else {
		lock.unlock();
		fprintf(stderr, "Client method \"%s\" does not exist", methodName.c_str());
	}
}

std::vector<uint8_t> Scenegraph::executeMethod(std::string, std::string methodName, flexbuffers::Reference data) {
	std::unique_lock lock(methodsMutex);
	if(methods.find(methodName) != methods.end()) {
		Method *method = &methods[methodName];
		lock.unlock();
		return (*method)(data, false);
	} else {
		fprintf(stderr, "Client method \"%s\" does not exist", methodName.c_str());
		lock.unlock();
		return std::vector<uint8_t>();
	}
}

}
}