#include "GaussianPartGen.h"

GaussianPartGen::GaussianPartGen(const Vector3& pos) : ParticleGen(pos, 1), rnd(10, 1) {

}

void GaussianPartGen::createParticle(Particle*& particle, double& maxTime) {
	Vector3 vel(10, 20, 0);
	particle = new Particle(trans.p, vel, Vector3(0, -10, 0), 0.998f, 1);
	maxTime = 5;
}
