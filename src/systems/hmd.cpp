#include "hmd.hpp"
#include "include/openxr/openxr.h"
#include "src/system.hpp"

namespace StardustXR {
namespace OpenXR {

HMDSystem::HMDSystem() :
System(XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY) {}

}
}
