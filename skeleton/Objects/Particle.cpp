#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float damp, float mass)
	: Object(pos), vel(vel), acc(acc), damp(damp), mass(0), disappearing(false) {

	physx::PxSphereGeometry a; a.radius = 3;
	shape = CreateShape(a);
	render = new RenderItem(shape, &trans, Vector4{0.5, 1, 1, 1});
}

Particle::~Particle() {
	
}

void Particle::update(double t) {
	vel += acc * t;
	vel *= powf(damp, t);

	trans.p += vel * t;

	if(disappearing) {
		physx::PxSphereGeometry a;
		shape->getSphereGeometry(a);
		a.radius -= 0.05;
		if(a.radius <= 0) {
			alive = false;
		} else {
			shape = CreateShape(a);
			auto color = render->color;
			render->release();
			render = new RenderItem(shape, &trans, color);
		}
	}
}

void Particle::disappear() {
	disappearing = true;
}
