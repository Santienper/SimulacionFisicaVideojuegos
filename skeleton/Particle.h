#pragma once
#include <PxPhysics.h>
#include "RenderUtils.hpp"

class Particle {
public:
	Particle(Vector3 pos = Vector3(0), Vector3 vel = Vector3(0));
	~Particle();

	void update(double t);
protected:
	physx::PxTransform trans;
	RenderItem* render;

	Vector3 vel;
};