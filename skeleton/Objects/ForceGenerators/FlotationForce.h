#pragma once
#include "ForceGenerator.h"

class FlotationForce : public ForceGenerator {
public:
	FlotationForce(const Vector3& pos = Vector3(0));

	virtual void updateForce(Particle* p, double t);
};