#pragma once
#include "ForceGenerator.h"

class WindForce : public ForceGenerator {
public:
	WindForce(const Vector3& wind = Vector3(0), float k = 1, const Vector3& pos = Vector3(0));

	void updateForce(Particle* p, double t);
	virtual void getWindVel(Particle* p, double t) { };
protected:
	float k;
	Vector3 wind;
};