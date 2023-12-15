#pragma once
#include "Structure/PhysicsObject.h"

class RDObject : public PhysicsObject {
public:
	RDObject(physx::PxGeometry* geo, const Vector3& vel = Vector3(0), float damp = 0.8f, float mass = 0.15, const Vector4& color = Vector4(1, 0.5, 1, 1));
	RDObject(const Vector3& pos, physx::PxGeometry* geo, const Vector3& vel = Vector3(0), float damp = 0.8f, float mass = 0.15, const Vector4& color = Vector4(1, 0.5, 1, 1));
	~RDObject();

	void update(double t) override;

	void addForce(const Vector3&) override;
	void clearAcum() override;
	Vector3 getVel() const override;
	float getMass() const override;

	void disappear();
private:
	physx::PxRigidDynamic* rigid;
	bool disappearing;
	physx::PxShape* shape;
};