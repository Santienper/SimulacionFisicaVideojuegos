#pragma once
#include "Structure/System.h"
#include "Objects/Particle.h" // Movable Object
#include <unordered_map>
#include <unordered_set>

class ForceGenerator;

class ForceSystem : public System {
public:
	setID("forces");

	ForceSystem();
	~ForceSystem();

	void addConnection(Particle*, ForceGenerator*);
	void deleteConnection(Particle*, ForceGenerator*);
	void deleteParticle(Particle*);
	void deleteForce(ForceGenerator*);

	void update(double t);

private:
	std::vector<ForceGenerator*> toDelete;
	std::unordered_map<ForceGenerator*, std::unordered_set<Particle*>> mapForce;
	std::unordered_map<Particle*, std::unordered_set<ForceGenerator*>> mapPart;
};