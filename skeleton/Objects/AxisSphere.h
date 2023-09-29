#pragma once
#include "Structure/Object.h"

class AxisSphere : public Object {
public:
	AxisSphere(Vector3 pos = Vector3(0), Vector4 color = Vector4(1, 1, 1, 1)) : Object(pos) {
		physx::PxSphereGeometry a; a.radius = 3;
		physx::PxShape* shape = CreateShape(a);
		render = new RenderItem(shape, &trans, color);
	}
};