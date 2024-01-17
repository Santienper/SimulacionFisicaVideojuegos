#include "GaussianPartGen.h"

GaussianPartGen::GaussianPartGen(const Vector3& pos, double rate, const Vector3& rndVel, const Vector3& startVel)
	: ParticleGen(pos, rate), rnd(0, 1), startVel(startVel), rndVel(rndVel) {

	std::random_device rd;
	gen = std::mt19937(rd());
}

void GaussianPartGen::createParticle(ParticleData& data) {
	const Vector3 aux(rndVel.x * rnd(gen), rndVel.y * rnd(gen), rndVel.z * rnd(gen));
	const Vector3 vel = startVel + aux;
	data.particle = new Particle(trans.p, vel, Vector3(0, -10, 0), 3, 0.998f, 1 + rnd(gen));
	data.maxTime = 5; data.disappear = true;
}
