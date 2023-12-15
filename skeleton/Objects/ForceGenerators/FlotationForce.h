#pragma once
#include "ForceGenerator.h"

class FlotationForce : public ForceGenerator {
public:
	FlotationForce(const Vector3& pos = Vector3(0), float liquidDensity = 1000);

	virtual void updateForce(PhysicsObject*, double t) override;
private:
	float liquidDensity;
};