#include "RDSystem.h"
#include "Objects/ForceGenerators/ForceGenerator.h"
#include "ForceSystem.h"
#include "Structure/Scene.h"

RDSystem::RDSystem() : SystemConstr{
	getOtherSystems();
}

RDSystem::~RDSystem() {
	for(auto& data : particles) {
		data.particle->alive = false;
	}
}

void RDSystem::addRD(RDObject* part, double maxTime, bool disappear) {
	RDManaging data = { part, 0, maxTime, disappear };
	particles.push_back(data);
}

void RDSystem::addRD(RDManaging data) {
	data.time = 0;
	particles.push_back(data);
}

void RDSystem::update(double t) {
	auto it = particles.begin();
	while(it != particles.end()) {
		it->time += t;
		if(it->time > it->maxTime) {
			if(it->disappear) {
				it->particle->disappear();
			} else {
				it->particle->alive = false;
				it->particle->callbackDelete();
			}
			if(forceSys != nullptr) forceSys->deleteParticle(it->particle);
			it = particles.erase(it);
		} else ++it;
	}
}

void RDSystem::getOtherSystems() {
	forceSys = Scene::get()->getSystem("forces").cast<ForceSystem>();
}
