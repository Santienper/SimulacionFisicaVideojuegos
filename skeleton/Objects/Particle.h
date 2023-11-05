#pragma once
#include <PxPhysics.h>
#include "Structure/Object.h"

class Particle : public Object {
public:
	Particle(const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float radius = 3, float damp = 0.998f, float mass = 1);
	~Particle();

	void update(double t);
	void disappear();
	virtual void callbackDelete() { };

	void addForce(const Vector3&);
	void clearAcum();
	float getMass() const { return mass; }
protected:
	Vector3 vel, acc, force;
	float damp, mass, inv_mass;

	bool disappearing;
	physx::PxShape* shape;
	Vector4 color;
};