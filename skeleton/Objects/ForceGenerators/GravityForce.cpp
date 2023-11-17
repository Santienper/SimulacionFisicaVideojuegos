#include "GravityForce.h"

GravityForce::GravityForce(const Vector3& gravity) : gravity(gravity) {

}

GravityForce::~GravityForce() {

}

void GravityForce::updateForce(Particle* particle, double t) {
	particle->addForce(gravity * particle->getMass());
}
