#pragma once
#include "Structure/Object.h"

class Shooter : public Object {
public:
	Shooter();
	void keyPressed(unsigned char key);
};
