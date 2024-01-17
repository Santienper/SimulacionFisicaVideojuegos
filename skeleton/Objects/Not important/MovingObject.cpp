#include "MovingObject.h"

MovingObject::MovingObject(const Vector3& pos, const Vector3& vel, const Vector3& acc, float damp, float mass)
	: PhysicsObject(pos), vel(vel), acc(acc), damp(damp), mass(mass), inv_mass(mass == 0 ? 0 : 1 / mass),
	affectedByForce(false) {

	addType("moving");
}

MovingObject::~MovingObject() {
	
}

void MovingObject::update(double t) {
	if(affectedByForce) acc = force * inv_mass;

	vel += acc * t;
	vel *= powf(damp, t);
	if(vel.magnitude() <= 1e-3) vel = { 0, 0, 0 };

	trans.p += vel * t;
}

void MovingObject::addForce(const Vector3& f) {
	force += f;
	affectedByForce = true;
}

void MovingObject::clearAcum() {
	force = Vector3(0);
}
