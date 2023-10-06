#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 vel, Vector3 acc, float damp, float mass, float grav) : Object(pos), vel(vel), acc(acc + Vector3(0, grav, 0)), damp(damp), time(0), mass(0) {
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

	time += t;
	alive = time < 5;
}