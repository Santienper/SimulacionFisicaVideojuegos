#pragma once
#include <PxPhysics.h>
#include "Core/RenderUtils.hpp"

class Scene;

class Object {
	friend class Scene;
public:
	Object(const Vector3& pos = Vector3(0));
	virtual ~Object();

	virtual void update(double t) { };
	virtual void callbackDelete() { };
	// Para estos métodos hace falta suscribirse a ellos
	virtual void keyPressed(unsigned char key) { };
	virtual void keyReleased(unsigned char key) { };
	virtual void specialKeyPressed(int key) { };
	virtual void specialKeyReleased(int key) { };
	virtual void mousePressed(int button, int state, int x, int y) { };
	virtual void mouseMoved(int x, int y) { };

	bool alive;

	const physx::PxTransform& getTransform() const { return trans; }
	virtual Vector3 getPos() const { return trans.p; }
	bool isType(const std::string& type) const;
	std::vector<std::string> getTypes() const { return types; }
	bool isSubbedKeyPress() const noexcept { return subbedKeyPress; }
	bool isSubbedKeyRelease() const noexcept { return subbedKeyRelease; }
	bool isSubbedMousePress() const noexcept { return subbedMousePress; }
	bool isSubbedMouseMove() const noexcept { return subbedMouseMove; }
	bool isSubbedRenderReset() const noexcept { return subbedResetRender; }
protected:
	// Suscripciones (para añadir la suscripción poner a true, para quitar a false)
	void subKeyPress(bool add);
	void subKeyRelease(bool add);
	void subMousePress(bool add);
	void subMouseMove(bool add);
	void subRenderReset(bool add);

	bool addType(const std::string& type);

	SpPtr<Scene> scene;

	physx::PxTransform trans;
	RenderItem* render;
private:
	std::vector<std::string> types;
	bool subbedKeyPress, subbedKeyRelease, subbedMousePress, subbedMouseMove, subbedResetRender;
};
