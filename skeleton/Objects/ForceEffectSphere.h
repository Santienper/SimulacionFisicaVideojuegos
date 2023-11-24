#pragma once
#include "Trigger.h"

class Particle;
class ForceGenerator;
class ForceSystem;

class ForceEffectSphere : public Trigger {
public:
	ForceEffectSphere(ForceGenerator*, const Vector3& pos = Vector3(0), float radius = 100);
protected:
	virtual bool isInside(Object*);
private:
	std::vector<Particle*> particles;
	ForceGenerator* force;
	float radius;
	SpPtr<ForceSystem> sys;
};