#pragma once
#include "ForceGenerator.h"

class GravityForce : public ForceGenerator {
public:
	GravityForce();
	~GravityForce();

	void updateForce(Particle*);

	inline Vector3 getGravity() const { return gravity; }
	inline void setGravity(const Vector3& gravity) { this->gravity = gravity; }
protected:

private:
	Vector3 gravity;
};