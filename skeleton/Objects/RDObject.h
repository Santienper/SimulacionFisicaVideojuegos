#pragma once
#include "Structure/PhysicsObject.h"

class RDObject : public PhysicsObject {
public:
	RDObject(physx::PxGeometry* geo, float damp = 0.8f, float mass = 0.15);
	RDObject(const Vector3& pos, physx::PxGeometry* geo, float damp = 0.8f, float mass = 0.15);
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