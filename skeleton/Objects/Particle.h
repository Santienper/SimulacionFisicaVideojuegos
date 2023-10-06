#pragma once
#include <PxPhysics.h>
#include "Structure/Object.h"

class Particle : public Object {
public:
	Particle(const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float damp = 0.998f, float mass = 1, float grav = -5);
	~Particle();

	void update(double t);
protected:
	Vector3 vel, acc;
	float damp, mass;
};