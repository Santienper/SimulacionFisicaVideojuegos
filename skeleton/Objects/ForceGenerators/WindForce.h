#pragma once
#include "ForceGenerator.h"

class WindForce : public ForceGenerator {
public:
	WindForce(const Vector3& wind = Vector3(0), float k = 1);

	void updateForce(Particle* p);
private:
	float k;
	Vector3 wind;
};