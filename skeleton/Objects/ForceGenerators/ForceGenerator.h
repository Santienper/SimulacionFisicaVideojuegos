#pragma once
#include "Structure/Object.h"
#include "../Particle.h"

class ForceGenerator : public Object {
public:
	ForceGenerator();
	~ForceGenerator();

	virtual void updateForce(Particle* p) = 0;
protected:

private:

};