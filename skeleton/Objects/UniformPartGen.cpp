#include "UniformPartGen.h"

UniformPartGen::UniformPartGen(const Vector3& pos, double rate) : ParticleGen(pos, rate), rnd(-5, 5) {
	std::random_device rd;
	gen = std::mt19937(rd());
}

void UniformPartGen::createParticle(ParticleData& data) {
	Vector3 vel(rnd(gen), 20, rnd(gen));
	data.particle = new Particle(trans.p, vel, Vector3(0, -10, 0), 0.998f, 1);
	data.maxTime = 5;
}
