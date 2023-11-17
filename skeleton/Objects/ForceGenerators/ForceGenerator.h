#pragma once
#include "Structure/Object.h"
#include "../Particle.h"
#include "Systems/ForceSystem.h"

class ForceGenerator : public Object {
public:
	ForceGenerator(const Vector3& pos = Vector3(0));
	~ForceGenerator();

	virtual void updateForce(Particle* p, double t) = 0;

	void deleteForce();
protected:
	SpPtr<ForceSystem> sys;
private:

};