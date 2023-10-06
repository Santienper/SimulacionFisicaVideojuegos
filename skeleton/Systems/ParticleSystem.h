#pragma once
#include "Structure/System.h"
#include "Objects/Particle.h"

class ParticleSystem : public System {
public:
	ParticleSystem() : System("particles") { }
	~ParticleSystem();

	void addParticle(Particle* part, double maxTime);

	void update(double t);
protected:
	struct PartManaging {
		Particle* part;
		double time, maxTime;
	};

	std::vector<PartManaging> particles;
};
