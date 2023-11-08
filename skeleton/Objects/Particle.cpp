#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float radius, float damp, float mass)
	: Object(pos), vel(vel), acc(acc), damp(damp), mass(mass), inv_mass(mass == 0 ? 0 : 1 / mass), disappearing(false),
	  affectedByForce(false) {

	physx::PxSphereGeometry a; a.radius = radius;
	shape = CreateShape(a);
	render = new RenderItem(shape, &trans, Vector4{0.5, 1, 1, 1});
}

Particle::~Particle() {
	
}

void Particle::update(double t) {
	if(affectedByForce) acc = force * inv_mass;

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

void Particle::addForce(const Vector3& f) {
	force += f;
	affectedByForce = true;
}

void Particle::clearAcum() {
	force = Vector3(0);
}
