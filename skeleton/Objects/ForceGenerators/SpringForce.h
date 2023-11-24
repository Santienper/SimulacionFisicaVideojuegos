#pragma once
#include "ForceGenerator.h"

class ForceSystem;

class SpringForce : public ForceGenerator {
public:
	SpringForce(float k = 1, float restingLength = 10);
	~SpringForce();

	void updateForce(Particle*, double t);
	bool addObject(Object*);
	bool addParticle(Particle*);
private:
	Object* obj1,* obj2;
	float k, restingLength;
};