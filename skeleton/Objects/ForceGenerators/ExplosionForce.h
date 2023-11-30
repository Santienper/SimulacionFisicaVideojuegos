#pragma once
#include "ForceGenerator.h"

class ForceEffectSphere;

class ExplosionForce : public ForceGenerator {
public:
	ExplosionForce(const Vector3& pos = Vector3(0), const float radius = 100, float intensity = 500000, float timeConst = 1);
	~ExplosionForce();

	void updateForce(MovingObject*, double t) override;
private:
	Vector3 radius;
	float intensity, timeConst, time;
	ForceEffectSphere* area;
};