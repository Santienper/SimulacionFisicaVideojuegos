#pragma once
#include "Structure/System.h"
#include "Structure/PhysicsObject.h"
#include <unordered_map>
#include <unordered_set>

class ForceGenerator;

class ForceSystem : public System {
public:
	setID("forces");

	ForceSystem();
	~ForceSystem();

	void addConnection(PhysicsObject*, ForceGenerator*);
	void deleteConnection(PhysicsObject*, ForceGenerator*);
	void deleteParticle(PhysicsObject*);
	void deleteForce(ForceGenerator*);

	void update(double t);

	void clear() override;
private:
	std::vector<ForceGenerator*> toDelete;
	std::unordered_map<ForceGenerator*, std::unordered_set<PhysicsObject*>> mapForce;
	std::unordered_map<PhysicsObject*, std::unordered_set<ForceGenerator*>> mapObj;
};