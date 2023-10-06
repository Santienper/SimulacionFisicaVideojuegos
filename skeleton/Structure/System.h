#pragma once
#include <string>
#include "Object.h"

class System {
public:
	System(std::string id);
	virtual ~System() { }

	virtual void update(double t) { }
	virtual void keyPressed(unsigned char key) { }

	bool alive;
};