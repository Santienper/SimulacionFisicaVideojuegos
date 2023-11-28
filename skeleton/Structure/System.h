#pragma once
#include <string>
#include "Object.h"

class System {
public:
	System(std::string id);
	virtual ~System() { }

	virtual void update(double t) { }
	virtual void keyPressed(unsigned char key) { }

	// Para definir este método es mejor usar el macro "setID(id)"
	virtual std::string getID() const = 0;

	bool alive;

	// Para debug
	virtual std::string toString() const { return getID(); }
};

#define setID(id) static std::string getStaticID() { return id; } virtual std::string getID() const override { return getStaticID(); }
#define SystemConstr System(getStaticID())