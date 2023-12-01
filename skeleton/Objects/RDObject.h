#pragma once
#include "Structure/Object.h"

class RDObject : public Object {
public:
	RDObject(physx::PxGeometry* geo);
	RDObject(const Vector3& pos, physx::PxGeometry* geo);
	~RDObject();
private:
	physx::PxRigidDynamic* rigid;
};