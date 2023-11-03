#pragma once
#include "Structure/System.h"
#include "Objects/Particle.h" // Movable Object
#include <unordered_map>
#include <unordered_set>

class ForceGenerator;

class ForceSystem : public System {
public:
	ForceSystem() : System("forces") { }
	~ForceSystem();

	void addParticle(Particle* part, double maxTime, bool disappear);

	struct PartManaging {
		Particle* particle;
		double time, maxTime;
		bool disappear;
	};
	void addParticle(PartManaging data);

	void update(double t);

private:
	std::vector<ForceGenerator*> forces;
	std::unordered_map<ForceGenerator*, std::unordered_set<Particle*>> map;
};