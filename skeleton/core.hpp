#ifndef __CORE_HPP__
#define __CORE_HPP__

#include "../common/Common/Print.h"
#include "../common/Common/PVD.h"
#include "../common/Utils/Utils.h"

#include "Render/Render.h"
#include "Render/Camera.h"

#include <vector>

using namespace Snippets;

typedef physx::PxVec3 Vector3;
typedef physx::PxVec4 Vector4;

// New: Special Pointer
#include "Utilities/SpPtr.h"
// New: Window Name
#define WINDOW_NAME "Simulacion Fisica Videojuegos"
// New: Log
#include "Utilities/Log.h"

#endif