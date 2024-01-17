#include "RDSystem.h"
#include "Objects/ForceGenerators/ForceGenerator.h"
#include "ForceSystem.h"
#include "Structure/Scene.h"

RDSystem::RDSystem() : SystemConstr {
	getOtherSystems();
}

RDSystem::~RDSystem() {
	for(auto& data : rigids) {
		data.rigid->alive = false;
	}
}

void RDSystem::addRD(RDObject* part, double maxTime, bool disappear) {
	RDManaging data = { part, 0, maxTime, disappear };
	rigids.push_back(data);
}

void RDSystem::addRD(RDManaging data) {
	data.time = 0;
	rigids.push_back(data);
}

void RDSystem::update(double t) {
	auto it = rigids.begin();
	while(it != rigids.end()) {
		it->time += t;
		if(it->time > it->maxTime) {
			if(it->disappear) {
				it->rigid->disappear();
			} else {
				it->rigid->alive = false;
				it->rigid->callbackDelete();
			}
			if(forceSys != nullptr) forceSys->deleteParticle(it->rigid);
			it = rigids.erase(it);
		} else ++it;
	}
}

void RDSystem::getOtherSystems() {
	forceSys = Scene::get()->getSystem<ForceSystem>();
}

void RDSystem::clear() {
	auto it = rigids.begin();
	while(it != rigids.end()) {
		it->rigid->alive = false;
		it = rigids.erase(it);
	}
}
