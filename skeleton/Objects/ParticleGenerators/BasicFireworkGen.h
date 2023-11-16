#pragma once
#include "GaussianPartGen.h"

template<typename Firework>
class BasicFireworkGen : public GaussianPartGen {
public:
	BasicFireworkGen(const Vector3& pos, double rate, const Vector3& rndVel = Vector3(5), double maxTime = 1.5, int maxFireworks = -1, const Vector3& startVel = Vector3(0), bool disappear = false)
		: GaussianPartGen(pos, rate, rndVel, startVel), maxFireworks(maxFireworks), maxTime(maxTime), disappear(disappear) {

	}
protected:
	void createParticle(ParticleData& data) {
		const Vector3 aux(rndVel.x * rnd(gen), rndVel.y * rnd(gen), rndVel.z * rnd(gen));
		const Vector3 vel = startVel + aux;
		data.particle = new Firework(trans.p, vel, Vector3(0, -10, 0));
		data.maxTime = maxTime;
		data.disappear = disappear;
		if(maxFireworks != -1) {
			maxFireworks--;
			alive = maxFireworks != 0;
		}
	}

	int maxFireworks, maxTime;
	bool disappear;
};