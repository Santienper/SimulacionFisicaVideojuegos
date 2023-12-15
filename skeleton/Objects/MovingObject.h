#pragma once
#include "Structure/PhysicsObject.h"

class MovingObject : public PhysicsObject {
	// type: moving
public:
	MovingObject(const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float damp = 0.998f, float mass = 1);
	~MovingObject();

	void update(double t);

	void addForce(const Vector3&) override;
	void clearAcum() override;

	float getMass() const override { return mass; }
	Vector3 getVel() const override { return vel; }
protected:
	Vector3 vel, acc, force;
	float damp, mass, inv_mass;

	bool affectedByForce;
};