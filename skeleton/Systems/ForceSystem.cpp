#include "ForceSystem.h"
#include "Objects/ForceGenerators/ForceGenerator.h"

ForceSystem::ForceSystem() : System("forces"), mapForce(), mapPart() {

}

ForceSystem::~ForceSystem() {
	
}

void ForceSystem::addConnection(Particle* part, ForceGenerator* force) {
	mapForce[force].insert(part);
	mapPart[part].insert(force);
}

void ForceSystem::deleteConnection(Particle* part, ForceGenerator* force) {
	mapForce[force].erase(part);
	mapPart[part].erase(force);
}

void ForceSystem::deleteParticle(Particle* part) {
	if(mapPart.find(part) == mapPart.end()) return;
	for(auto force : mapPart[part]) {
		mapForce[force].erase(part);
	}
	mapPart.erase(part);
}

void ForceSystem::deleteForce(ForceGenerator* force) {
	toDelete.push_back(force);
}

void ForceSystem::update(double t) {
	auto it = toDelete.begin();
	while(it != toDelete.end()) {
		auto force = *it;
		for(auto part : mapForce[force]) {
			mapPart[part].erase(force);
		}
		mapForce.erase(force);
		force->alive = false;
		it = toDelete.erase(it);
	}

	for(auto& data : mapPart) {
		data.first->clearAcum();
		for(auto& force : data.second) {
			force->updateForce(data.first, t);
		}
	}
}
