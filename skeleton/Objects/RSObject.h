#pragma once
#include "Structure/Object.h"

class RSObject : public Object {
public:
	RSObject(physx::PxGeometry* geo);
	RSObject(const Vector3& pos, physx::PxGeometry* geo);
	~RSObject();
private:
	physx::PxRigidStatic* rigid;
};