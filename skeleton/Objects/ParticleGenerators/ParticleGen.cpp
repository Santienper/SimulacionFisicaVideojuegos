#include "ParticleGen.h"
#include "Structure/Scene.h"

ParticleGen::ParticleGen(const Vector3& pos, double rate) : Object(pos), time(0), rate(rate) {
	sys = static_cast<ParticleSystem*>(Scene::get()->getSystem(ids::sys_particle));
	if(sys == nullptr) throw std::exception("No hay sistema de partículas");
}

void ParticleGen::update(double t) {
	time += t;

	if(time > rate) {
		time -= rate;
		ParticleSystem::PartManaging data{ nullptr, 0, 0, false };
		createParticle(data);
		sys->addParticle(data);
	}
}
