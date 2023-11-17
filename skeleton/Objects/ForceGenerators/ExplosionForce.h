#pragma once
#include "ForceGenerator.h"

class ForceEffectSphere;

class ExplosionForce : public ForceGenerator {
public:
	ExplosionForce(const Vector3& pos = Vector3(0), const Vector3& radius = Vector3(100), float intensity = 500000, float timeConst = 1);

	void updateForce(Particle* p, double t);
private:
	Vector3 radius;
	float intensity, timeConst, time;
	ForceEffectSphere* area;
};