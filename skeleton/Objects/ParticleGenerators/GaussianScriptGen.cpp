#include "GaussianScriptGen.h"

GaussianScriptGen::GaussianScriptGen(const Vector3& pos, double rate, double sigma, const Vector3& startVel, const Vector3& rndVel) :
	GaussianPartGen(pos, rate, sigma, startVel, rndVel) {
	
}

void GaussianScriptGen::setCallback(std::function<void(Particle*)> callback) {
	callbacks.push_back(callback);
}

void GaussianScriptGen::createParticle(ParticleData& data) {
	const Vector3 aux(rndVel.x * rnd(gen), rndVel.y * rnd(gen), rndVel.z * rnd(gen));
	const Vector3 vel = startVel + aux;
	data.particle = new Particle(trans.p, vel, Vector3(0, -10, 0), 3, 0.998f, 1);
	data.maxTime = 5; data.disappear = true;
	for(auto callback : callbacks) {
		callback(data.particle);
	}
}
