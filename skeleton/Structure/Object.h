#pragma once
#include <PxPhysics.h>
#include "Core/RenderUtils.hpp"

class Scene;

class Object {
public:
	Object(Vector3 pos = Vector3(0));
	virtual ~Object();

	virtual void update(double t) { }
	virtual void keyPressed(unsigned char key) { }

	bool alive;
protected:
	physx::PxTransform trans;
	RenderItem* render;
};
