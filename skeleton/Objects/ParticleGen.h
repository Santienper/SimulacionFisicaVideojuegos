#pragma once
#include "Structure/Object.h"
#include "Systems/ParticleSystem.h"
#include <random>

class ParticleGen : public Object {
public:
	ParticleGen(const Vector3& pos, double rate = 1);

	void update(double t);
protected:
	using ParticleData = ParticleSystem::PartManaging;
	virtual void createParticle(ParticleData& data) = 0;
private:
	double time, rate;
	ParticleSystem* sys;
};
