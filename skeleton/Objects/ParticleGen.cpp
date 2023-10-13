#include "ParticleGen.h"
#include "Structure/Scene.h"

ParticleGen::ParticleGen(const Vector3& pos, double rate) : Object(pos), time(0), rate(rate) {
	sys = static_cast<ParticleSystem*>(Scene::get()->getSystem("particles"));
	if(sys == nullptr) throw std::exception("No hay sistema de partículas");
}

void ParticleGen::update(double t) {
	time += t;

	if(time > rate) {
		time -= rate;
		Particle* part = nullptr;
		double maxTime = 0;
		createParticle(part, maxTime);
		sys->addParticle(part, maxTime);
	}
}
