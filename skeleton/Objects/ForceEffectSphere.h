#pragma once
#include "Trigger.h"

class Particle;
class ForceGenerator;
class ForceSystem;

class ForceEffectSphere : public Trigger {
public:
	ForceEffectSphere(ForceGenerator*, const Vector3& pos = Vector3(0), Vector3 radius = Vector3(100));
	~ForceEffectSphere();
protected:
	virtual bool isInside(Object*);
private:
	std::vector<Particle*> particles;
	ForceGenerator* force;
	Vector3 radius;
	SpPtr<ForceSystem> sys;
};