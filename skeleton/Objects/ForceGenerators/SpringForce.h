#pragma once
#include "ForceGenerator.h"

class ForceSystem;

class SpringForce : public ForceGenerator {
public:
	SpringForce(float k = 1, float restingLength = 10);
	~SpringForce();

	void updateForce(MovingObject*, double t) override;
	bool addObject(Object*);
	bool addMovingObject(MovingObject*);
private:
	Object* obj1,* obj2;
	float k, restingLength;
};