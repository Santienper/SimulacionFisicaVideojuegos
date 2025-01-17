#include "ParticleGen.h"
#include "Structure/Scene.h"

ParticleGen::ParticleGen(const Vector3& pos, double rate) : Object(pos), time(0), rate(rate) {
	sys = scene->getSystem<ParticleSystem>();
	if(sys == nullptr) {
		alive = false;
		Log::logError("No hay sistema de particulas, omitiendo creacion de generador de particulas");
	}
}

void ParticleGen::update(double t) {
	time += t;

	if(sys == nullptr) {
		alive = false;
		return;
	}

	if(time > rate) {
		time -= rate;
		ParticleSystem::PartManaging data{ nullptr, 0, 0, false };
		createParticle(data);
		sys->addParticle(data);
	}
}
