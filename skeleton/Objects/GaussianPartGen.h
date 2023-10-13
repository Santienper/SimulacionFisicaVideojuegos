#pragma once
#include "ParticleGen.h"

class GaussianPartGen : public ParticleGen {
public:
	GaussianPartGen(const Vector3& pos, double rate, double sigma, const Vector3& startVel = Vector3(0, 20, 0), const Vector3& rndVel = Vector3(1, 0, 1));
protected:
	void createParticle(Particle*& particle, double& maxTime);
	std::normal_distribution<float> rnd;
	std::mt19937 gen;
	Vector3 startVel, rndVel;
};