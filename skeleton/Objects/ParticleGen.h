#pragma once
#include "Structure/Object.h"
#include "Systems/ParticleSystem.h"
#include <random>

class ParticleGen : public Object {
public:
	ParticleGen(const Vector3& pos, double rate = 1);

	void update(double t);
protected:
	virtual void createParticle(Particle*& particle, double& maxTime) = 0;
private:
	double time, rate;
	ParticleSystem* sys;
};
