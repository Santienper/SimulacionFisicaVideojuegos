#pragma once
#include "Structure/Object.h"
#include "Particle.h"
#include <random>

class ParticleGen : public Object {
	const double maxTime = 5;
public:
	ParticleGen(const Vector3& pos, double rate = 1);
	~ParticleGen();

	void update(double t);
private:
	struct PartManaging {
		Particle* part;
		double time;
	};

	std::vector<PartManaging> particles;
	double time, rate;

	std::normal_distribution<float> rnd;
};
