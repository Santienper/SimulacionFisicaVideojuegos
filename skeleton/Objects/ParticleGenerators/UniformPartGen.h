#pragma once
#include "ParticleGen.h"

class UniformPartGen : public ParticleGen {
public:
	UniformPartGen(const Vector3& pos, double rate);
protected:
	void createParticle(ParticleData& data);
	std::uniform_real_distribution<float> rnd;
	std::mt19937 gen;
};