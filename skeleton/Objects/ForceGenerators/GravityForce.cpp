#include "GravityForce.h"

GravityForce::GravityForce(const Vector3& gravity) : gravity(gravity) {

}

GravityForce::~GravityForce() {

}

void GravityForce::updateForce(MovingObject* obj, double t) {
	obj->addForce(gravity * obj->getMass());
}
