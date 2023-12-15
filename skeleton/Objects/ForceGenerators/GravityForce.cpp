#include "GravityForce.h"

GravityForce::GravityForce(const Vector3& gravity) : gravity(gravity) {

}

GravityForce::~GravityForce() {

}

void GravityForce::updateForce(PhysicsObject* obj, double t) {
	obj->addForce(gravity * obj->getMass());
}
