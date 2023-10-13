#pragma once
#include "GaussianPartGen.h"

template<typename Firework>
class FireworkGen : public GaussianPartGen {
public:
	FireworkGen(const Vector3& pos, double rate, double sigma, int maxFireworks = -1, const Vector3& startVel = Vector3(0, 30, 0), const Vector3& rndVel = Vector3(1, 0, 1))
		: GaussianPartGen(pos, rate, sigma, startVel, rndVel), maxFireworks(maxFireworks) {

	}
protected:
	void createParticle(Particle*& particle, double& maxTime) {
		const Vector3 aux(rndVel.x * rnd(gen), rndVel.y * rnd(gen), rndVel.z * rnd(gen));
		const Vector3 vel = startVel + aux;
		particle = new Firework(trans.p, vel, Vector3(0, -10, 0), 0.998f, 1);
		maxTime = 1.5;
		if(maxFireworks != -1) {
			maxFireworks--;
			alive = maxFireworks != 0;
		}
	}
private:
	int maxFireworks;
};