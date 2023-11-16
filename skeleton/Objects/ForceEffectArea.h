#pragma once
#include "Structure/Object.h"

class Particle;
class ForceGenerator;

class ForceEffectArea : public Object {
public:
	ForceEffectArea();
	~ForceEffectArea();
protected:

private:
	std::vector<Particle*> particles;
	ForceGenerator* force;
};