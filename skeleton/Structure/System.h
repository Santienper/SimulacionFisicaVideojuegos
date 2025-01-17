#pragma once
#include <string>
#include "Object.h"

class System {
public:
	System(std::string id);
	virtual ~System() { }

	virtual void update(double t) { }
	virtual void keyPressed(unsigned char key) { }
	virtual void keyReleased(unsigned char key) { }
	virtual void specialKeyPressed(int key) { }
	virtual void specialKeyReleased(int key) { }
	virtual void mousePressed(int button, int state, int x, int y) { }
	virtual void mouseMoved(int x, int y) { }
	virtual void clear() { }

	// Para definir este m�todo es mejor usar el macro "setID(id)"
	virtual std::string getID() const = 0;

	bool alive;

	// Para debug
	virtual std::string toString() const { return getID(); }
};

#define setID(id) inline static std::string getStaticID() { return id; } virtual inline std::string getID() const override { return id; }
#define SystemConstr System(getStaticID())