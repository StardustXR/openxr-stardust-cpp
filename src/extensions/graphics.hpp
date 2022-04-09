#pragma once

namespace StardustXR {
namespace OpenXR {

class GraphicsAPI {
public:
	virtual ~GraphicsAPI() {}
	virtual void makeContextCurrent() = 0;
	virtual void restoreContext() = 0;
};

}
}