#pragma once
#include "Structure/Object.h"

class RSObject : public Object {
public:
	RSObject(physx::PxGeometry* geo, const Vector4& color = { 1, 0.5, 1, 1 });
	RSObject(const Vector3& pos, physx::PxGeometry* geo, const Vector4& color = { 1, 0.5, 1, 1 });

	~RSObject();
protected:
	void createShape(physx::PxGeometry* geo, const Vector4& color = { 1, 0.5, 1, 1 });
private:
	physx::PxRigidStatic* rigid;
};