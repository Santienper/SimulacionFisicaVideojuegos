#pragma once
#include "ForceGenerator.h"

class GravityForce : public ForceGenerator {
public:
	GravityForce(const Vector3& gravity = Vector3(0));
	~GravityForce();

	void updateForce(PhysicsObject*, double t) override;

	inline Vector3 getGravity() const { return gravity; }
	inline void setGravity(const Vector3& gravity) { this->gravity = gravity; }
protected:

private:
	Vector3 gravity;
};