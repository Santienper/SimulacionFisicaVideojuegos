#pragma once
#include "ParticleGen.h"

class GaussianPartGen : public ParticleGen {
public:
	GaussianPartGen(const Vector3& pos);
protected:
	void createParticle(Particle*& particle, double& maxTime);
private:
	std::normal_distribution<float> rnd;
};