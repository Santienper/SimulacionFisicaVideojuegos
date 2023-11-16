#include "ForceSystem.h"
#include "Objects/ForceGenerators/ForceGenerator.h"

ForceSystem::~ForceSystem() {
	for(auto force : forces) delete force;
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
	for(auto force : mapPart[part]) {
		mapForce[force].erase(part);
	}
	mapPart.erase(part);
}

void ForceSystem::deleteForce(ForceGenerator* force) {
	for(auto part : mapForce[force]) {
		mapPart[part].erase(force);
	}
	mapForce.erase(force);
}

void ForceSystem::update(double t) {
	for(auto& data : mapPart) {
		data.first->clearAcum();
		for(auto& force : data.second) {
			force->updateForce(data.first);
		}
	}
}