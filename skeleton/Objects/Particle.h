#pragma once
#include <PxPhysics.h>
#include "MovingObject.h"

class Particle : public MovingObject {
public:
	Particle(const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float radius = 3, float damp = 0.998f, float mass = 1);
	~Particle();

	void update(double t);
	void disappear();

	float getRadius() const noexcept { return radius; }
protected:
	float radius;
	bool disappearing;
	physx::PxShape* shape;
	Vector4 color;
};