#include "Fireworks.h"
#include "ParticleGenerators/BasicFireworkGen.h"
#include "ParticleGenerators/CircleFWGen.h"

#define FIREWORK_ARGS const Vector3& pos, const Vector3& vel, const Vector3& acc, float damp, float mass

Firework1::Firework1(FIREWORK_ARGS) : Particle(pos, vel, acc, 2, damp, mass) {
	render->color.y = 0.5;
}

void Firework1::callbackDelete() {
	new BasicFireworkGen<Firework2>(trans.p, 0, Vector3(15), 1, 3, Vector3(0), true);
}

Firework2::Firework2(FIREWORK_ARGS) : Particle(pos, vel, acc, 2, damp, mass) {
	render->color.z = 0.5;
}

Firework3::Firework3(FIREWORK_ARGS) : Particle(pos, vel, acc, 2, damp, mass) {
	render->color.x = 0.5;
	render->color.y = 0.5;
	render->color.z = 0.5;
}

void Firework3::callbackDelete() {
	new BasicFireworkGen<Firework1>(trans.p, 0, Vector3(15), 1.5, 5, Vector3(0));
}

Firework4::Firework4(FIREWORK_ARGS) : Particle(pos, vel, acc, 2, damp, mass) {
	render->color.x = 1;
	render->color.y = 0.5;
	render->color.z = 0.5;
}

void Firework4::callbackDelete() {
	new BasicFireworkGen<Firework3>(trans.p, 0, Vector3(15), 1, 7);
	new BasicFireworkGen<Firework5>(trans.p, 0, Vector3(15), 1, 2);
}

Firework5::Firework5(FIREWORK_ARGS) : Particle(pos, vel, acc, 2, damp, mass) {
	render->color.x = 1;
	render->color.y = 0.5;
	render->color.z = 1;
}

void Firework5::callbackDelete() {
	new CircleFWGen<Firework6>(trans.p, 0, Vector3(0.5), 1.5, 10, 10, Vector3(0), true);
}

Firework6::Firework6(FIREWORK_ARGS) : Particle(pos, vel, acc, 2, damp, mass) {

}

#undef FIREWORK_ARGS