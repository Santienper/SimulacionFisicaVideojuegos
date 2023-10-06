#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float damp, float mass, float grav)
	: Object(pos), vel(vel), acc(acc + Vector3(0, grav, 0)), damp(damp), mass(0) {

	physx::PxSphereGeometry a; a.radius = 3;
	physx::PxShape* shape = CreateShape(a);
	render = new RenderItem(shape, &trans, Vector4{0.5, 1, 1, 1});
}

Particle::~Particle() {
	
}

void Particle::update(double t) {
	vel += acc * t;
	vel *= powf(damp, t);

	trans.p += vel * t;
}