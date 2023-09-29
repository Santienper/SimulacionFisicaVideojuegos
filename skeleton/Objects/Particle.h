#pragma once
#include <PxPhysics.h>
#include "Structure/Object.h"

class Particle : public Object {
	const float grav = -9.81f;
public:
	Particle(Vector3 pos = Vector3(0), Vector3 vel = Vector3(0), Vector3 acc = Vector3(0), float damp = 0.998f);
	~Particle();

	void update(double t);
protected:
	Vector3 vel, acc;
	float damp;

	double time;
};