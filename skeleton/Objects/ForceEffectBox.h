#pragma once
#include "Trigger.h"

class Particle;
class ForceGenerator;
class ForceSystem;

class ForceEffectBox : public Trigger {
public:
	ForceEffectBox(ForceGenerator*, const Vector3& pos = Vector3(0), const Vector3& halfExtents = Vector3(20));
protected:
	virtual bool isInside(Object*);
private:
	std::vector<Particle*> particles;
	ForceGenerator* force;
	Vector3 halfExtents;
	SpPtr<ForceSystem> sys;
};