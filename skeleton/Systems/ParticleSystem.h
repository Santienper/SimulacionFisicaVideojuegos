#pragma once
#include "Structure/System.h"
#include "Objects/Particle.h"
#include <unordered_map>
#include <unordered_set>

class ForceSystem;

class ParticleSystem : public System {
public:
	setID("particles");

	ParticleSystem();
	~ParticleSystem();

	void addParticle(Particle* part, double maxTime, bool disappear);

	struct PartManaging {
		Particle* particle;
		double time, maxTime;
		bool disappear;
	};
	void addParticle(PartManaging data);

	void update(double t);

	void getOtherSystems();
	void clear() override;
protected:
	std::vector<PartManaging> particles;
	SpPtr<ForceSystem> forceSys;
};
