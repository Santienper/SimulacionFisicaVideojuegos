#include "GaussianScriptGen.h"

GaussianScriptGen::GaussianScriptGen(const Vector3& pos, double rate, const Vector3& rndVel, const Vector3& startVel, float maxTime) :
	GaussianPartGen(pos, rate, rndVel, startVel), maxTime(maxTime) {
	
}

void GaussianScriptGen::addCallback(std::function<void(Particle*)> callback) {
	callbacks.push_back(callback);
}

void GaussianScriptGen::createParticle(ParticleData& data) {
	const Vector3 aux(rndVel.x * rnd(gen), rndVel.y * rnd(gen), rndVel.z * rnd(gen));
	const Vector3 vel = startVel + aux;
	data.particle = new Particle(trans.p, vel, Vector3(0), 3, 0.998f, 1);
	data.maxTime = maxTime; data.disappear = true;
	for(auto callback : callbacks) {
		callback(data.particle);
	}
}
