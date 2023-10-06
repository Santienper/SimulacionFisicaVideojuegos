#pragma once
#include <PxPhysics.h>
#include "Structure/Object.h"

class Particle : public Object {
public:
	Particle(Vector3 pos = Vector3(0), Vector3 vel = Vector3(0), Vector3 acc = Vector3(0), float damp = 0.998f, float mass = 1, float grav = -2);
	~Particle();

	void update(double t);
protected:
	Vector3 vel, acc;
	float damp, mass;

	double time;
};