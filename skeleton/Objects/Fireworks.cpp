#include "Fireworks.h"
#include "FireworkGen.h"

#define FIREWORK_ARGS const Vector3& pos, const Vector3& vel, const Vector3& acc, float damp, float mass

Firework1::Firework1(FIREWORK_ARGS)
	: Particle(pos, vel, acc, damp, mass) {
	render->color.y = 0.5;
}

Firework1::~Firework1() {
	new FireworkGen<Firework2>(trans.p, 0, 3, 1, 3, vel, Vector3(1, 1, 1), true);
}

Firework2::Firework2(FIREWORK_ARGS)
	: Particle(pos, vel, acc, damp, mass) {
	render->color.z = 0.5;
}

Firework2::~Firework2() {

}

Firework3::Firework3(FIREWORK_ARGS)
	: Particle(pos, vel, acc, damp, mass) {
	render->color.x = 0.5;
	render->color.y = 0.5;
	render->color.z = 0.5;
}

Firework3::~Firework3() {
	new FireworkGen<Firework1>(trans.p, 0, 3, 1.5, 5, vel, Vector3(1, 1, 1));
}
