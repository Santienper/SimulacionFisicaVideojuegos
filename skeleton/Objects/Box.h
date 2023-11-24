#pragma once
#include "Structure/Object.h"

class Box : public Object {
public:
	Box(Vector3 pos = Vector3(0), Vector3 halfExtents = Vector3(1.5f), Vector4 color = { 0.5, 1, 1, 1 });
protected:
	physx::PxShape* shape;
	Vector4 color;
};