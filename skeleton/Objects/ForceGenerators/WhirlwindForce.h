#pragma once
#include "WindForce.h"

class WhirlwindForce : public WindForce {
public:
	WhirlwindForce(const Vector3& pos = Vector3(0), float windConst = 1, float whirlConst = 5);

	void getWindVel(Particle* p, double t);
private:
	float forceConst;
};