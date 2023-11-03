#include "ParticleSystem.h"
#include "Objects/ForceGenerators/ForceGenerator.h"

ParticleSystem::~ParticleSystem() {
	for(auto& data : particles) {
		data.particle->alive = false;
	}
	for(auto force : forces) {
		force->alive = false;
	}
}

void ParticleSystem::addParticle(Particle* part, double maxTime, bool disappear) {
	PartManaging data = { part, 0, maxTime, disappear };
	particles.push_back(data);
}

void ParticleSystem::addParticle(PartManaging data) {
	data.time = 0;
	particles.push_back(data);
}

void ParticleSystem::update(double t) {
	auto it = particles.begin();
	while(it != particles.end()) {
		it->time += t;
		if(it->time > it->maxTime) {
			it->disappear ? it->particle->disappear() : it->particle->alive = false;
			it = particles.erase(it);
		} else ++it;
	}
}