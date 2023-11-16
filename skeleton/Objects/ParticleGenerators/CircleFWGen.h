#pragma once
#include "BasicFireworkGen.h"

template<typename Firework>
class CircleFWGen : public BasicFireworkGen<Firework> {
public:
	CircleFWGen(const Vector3& pos, double rate, const Vector3& rndVel = Vector3(1), double maxTime = 1.5, int maxFireworks = 10, float disperseVel = 10, const Vector3& startVel = Vector3(0), bool disappear = false)
		: BasicFireworkGen<Firework>(pos, rate, rndVel, maxTime, maxFireworks, startVel, disappear), disperseVel(disperseVel), i(0) {

	}
protected:
	void createParticle(ParticleData& data) {
		const float angle = (float)i / maxFireworks * 6.2831853071f; // 2 * PI
		const Vector3 aux(cosf(angle + rndVel.x * rnd(gen)) * disperseVel,
			sinf(angle + rndVel.y * rnd(gen)) * disperseVel, 0);
		const Vector3 vel = startVel + aux;
		data.particle = new Firework(trans.p, vel, Vector3(0, -10, 0));
		data.maxTime = maxTime;
		data.disappear = disappear;

		alive = i++ != maxFireworks;
	}

	float disperseVel;
	int i;
};