#pragma once
#include <PxPhysics.h>
#include "Core/RenderUtils.hpp"

class Scene;

class Object {
public:
	Object(const Vector3& pos = Vector3(0));
	virtual ~Object();

	virtual void update(double t) { };
	virtual void callbackDelete() { };
	// Para estos métodos hace falta suscribirse a ellos
	virtual void keyPressed(unsigned char key) { };
	virtual void mousePressed(int button, int state, int x, int y) { };
	virtual void mouseMoved(int x, int y) { };

	bool alive;

	const physx::PxTransform& getTransform() const { return trans; }
	std::string getType() const { return type; }
	bool isSubbedKey() const noexcept { return subbedKey; }
	bool isSubbedMousePress() const noexcept { return subbedMousePress; }
	bool isSubbedMouseMove() const noexcept { return subbedMouseMove; }
protected:
	// Suscripciones (para añadir la suscripción poner a true, para quitar a false)
	void subKey(bool add);
	void subMousePress(bool add);
	void subMouseMove(bool add);

	SpPtr<Scene> scene;

	physx::PxTransform trans;
	RenderItem* render;
	std::string type;
private:
	bool subbedKey, subbedMousePress, subbedMouseMove;
};
