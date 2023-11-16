#pragma once
#include "ParticleGen.h"

class GaussianPartGen : public ParticleGen {
public:
	GaussianPartGen(const Vector3& pos, double rate, const Vector3& sigma = Vector3(5, 0, 5), const Vector3& startVel = Vector3(0, 20, 0));
protected:
	void createParticle(ParticleData& data);
	std::normal_distribution<float> rnd;
	std::mt19937 gen;
	Vector3 startVel, rndVel;
};