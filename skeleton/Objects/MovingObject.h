#pragma once
#include "Structure/Object.h"

class MovingObject : public Object {
	// type: moving
public:
	MovingObject(const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float damp = 0.998f, float mass = 1);
	~MovingObject();

	void update(double t);

	void addForce(const Vector3&);
	void clearAcum();

	float getMass() const { return mass; }
	Vector3 getVel() const { return vel; }
protected:
	Vector3 vel, acc, force;
	float damp, mass, inv_mass;

	bool affectedByForce;
};