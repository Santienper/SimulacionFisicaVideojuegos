#include "ParticleGen.h"

ParticleGen::ParticleGen(const Vector3& pos, double rate) : Object(pos), time(0), rate(rate), rnd(10, 1) {

}

ParticleGen::~ParticleGen() {
	for(auto data : particles) {
		data.part->alive = false;
	}
}

void ParticleGen::update(double t) {
	// Almacenar partículas creadas y eliminarlas si abandonan el "espacio de acción"
	// Velocidad de partícula aleatoria (con distribución normal independiente)

	time += t;

	if(time > rate) {
		time -= rate;
		Vector3 vel(10, 20, 0);
		PartManaging part = { new Particle(trans.p, vel, Vector3(0), 0.998f, 1, -10), 0 };
		particles.push_back(part);
	}

	for(auto& data : particles) {
		data.time += t;
		if(data.time > maxTime) {
			data.part->alive = false;
		}
	}
}
