#pragma once
#include "Object.h"

class PhysicsObject : public Object {
	// type: physics
public:
	PhysicsObject(const Vector3& pos = Vector3(0)) : Object(pos) { type = "physics"; }

	virtual void addForce(const Vector3&) = 0;
	virtual void clearAcum() = 0;
	virtual Vector3 getVel() const = 0;
	virtual float getMass() const = 0;
};