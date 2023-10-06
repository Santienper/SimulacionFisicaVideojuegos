#include "ParticleSystem.h"

ParticleSystem::~ParticleSystem() {
	for(auto& data : particles) {
		data.part->alive = false;
	}
}

void ParticleSystem::addParticle(Particle* part, double maxTime) {
	PartManaging data = { part, 0, maxTime };
	particles.push_back(data);
}

void ParticleSystem::update(double t) {
	auto it = particles.begin();
	while(it != particles.end()) {
		it->time += t;
		if(it->time > it->maxTime) {
			it->part->alive = false;
			it = particles.erase(it);
		} else ++it;
	}
}
