#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 vel) : trans(pos), vel(vel) {
	physx::PxSphereGeometry a; a.radius = 3;
	physx::PxShape* shape = CreateShape(a);
	render = new RenderItem(shape, &trans, Vector4{0.5, 1, 1, 1});
}

Particle::~Particle() {
	render->release();
}

void Particle::update(double t) {
	trans.p += vel * t;
}