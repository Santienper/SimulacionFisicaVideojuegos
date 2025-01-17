#include "ForceSystem.h"
#include "Objects/ForceGenerators/ForceGenerator.h"

ForceSystem::ForceSystem() : SystemConstr, mapForce(), mapObj() {

}

ForceSystem::~ForceSystem() {
	
}

void ForceSystem::addConnection(PhysicsObject* obj, ForceGenerator* force) {
	mapForce[force].insert(obj);
	mapObj[obj].insert(force);
}

void ForceSystem::deleteConnection(PhysicsObject* obj, ForceGenerator* force) {
	if(mapObj.find(obj) == mapObj.end()) return;
	mapForce[force].erase(obj);
	mapObj[obj].erase(force);
}

void ForceSystem::deleteParticle(PhysicsObject* obj) {
	if(mapObj.find(obj) == mapObj.end()) return;
	for(auto force : mapObj[obj]) {
		mapForce[force].erase(obj);
	}
	mapObj.erase(obj);
}

void ForceSystem::deleteForce(ForceGenerator* force) {
	toDelete.push_back(force);
}

void ForceSystem::update(double t) {
	auto it = toDelete.begin();
	while(it != toDelete.end()) {
		auto force = *it;
		for(auto part : mapForce[force]) {
			mapObj[part].erase(force);
		}
		mapForce.erase(force);
		force->alive = false;
		it = toDelete.erase(it);
	}

	for(auto& data : mapObj) {
		data.first->clearAcum();
		for(auto& force : data.second) {
			force->updateForce(data.first, t);
		}
	}
}

void ForceSystem::clear() {
	for(auto it = toDelete.begin(); it != toDelete.end();) {
		auto force = *it;
		for(auto part : mapForce[force]) {
			mapObj[part].erase(force);
		}
		mapForce.erase(force);
		force->alive = false;
		it = toDelete.erase(it);
	}

	mapObj.clear();
	mapForce.clear();
}
