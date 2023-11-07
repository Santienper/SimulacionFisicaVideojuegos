#pragma once
#include "Structure/System.h"
#include "Objects/Particle.h"
#include <unordered_map>
#include <unordered_set>

class ForceGenerator;

class ParticleSystem : public System {
public:
	ParticleSystem() : System("particles") { }
	~ParticleSystem();

	void addParticle(Particle* part, double maxTime, bool disappear);

	struct PartManaging {
		Particle* particle;
		double time, maxTime;
		bool disappear;
	};
	void addParticle(PartManaging data);

	void update(double t);

protected:
	std::vector<PartManaging> particles;
};
