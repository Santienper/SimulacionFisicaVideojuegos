#pragma once
#include "Structure/Object.h"

class RSObject : public Object {
	// type: rigid
public:
	RSObject(physx::PxGeometry* geo, const Vector4& color = { 1, 0.5, 1, 1 });
	RSObject(const Vector3& pos, physx::PxGeometry* geo, const Vector4& color = { 1, 0.5, 1, 1 });

	Vector3 getPos() const override;

	~RSObject();
protected:
	void createShape(physx::PxGeometry* geo, const Vector4& color = { 1, 0.5, 1, 1 });
	physx::PxRigidStatic* rigid;
private:
};