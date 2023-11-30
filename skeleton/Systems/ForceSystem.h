#pragma once
#include "Structure/System.h"
#include "Objects/MovingObject.h"
#include <unordered_map>
#include <unordered_set>

class ForceGenerator;

class ForceSystem : public System {
public:
	setID("forces");

	ForceSystem();
	~ForceSystem();

	void addConnection(MovingObject*, ForceGenerator*);
	void deleteConnection(MovingObject*, ForceGenerator*);
	void deleteParticle(MovingObject*);
	void deleteForce(ForceGenerator*);

	void update(double t);

private:
	std::vector<ForceGenerator*> toDelete;
	std::unordered_map<ForceGenerator*, std::unordered_set<MovingObject*>> mapForce;
	std::unordered_map<MovingObject*, std::unordered_set<ForceGenerator*>> mapObj;
};