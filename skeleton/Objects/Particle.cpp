#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float radius, float damp, float mass)
	: MovingObject(pos, vel, acc, damp, mass), disappearing(false) {

	physx::PxSphereGeometry a; a.radius = radius;
	shape = CreateShape(a);
	render = new RenderItem(shape, &trans, Vector4{0.5, 1, 1, 1});
	//type = "particle";
}

Particle::~Particle() {
	
}

void Particle::update(double t) {
	MovingObject::update(t);

	if(disappearing) {
		physx::PxSphereGeometry a;
		shape->getSphereGeometry(a);
		a.radius -= 0.05;
		if(a.radius <= 0) {
			alive = false;
			callbackDelete();
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