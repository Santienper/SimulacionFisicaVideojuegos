#pragma once
#include <PxPhysics.h>
#include "Core/RenderUtils.hpp"

class Scene;

class Object {
public:
	Object(const Vector3& pos = Vector3(0));
	virtual ~Object();

	virtual void update(double t) { }
	virtual void keyPressed(unsigned char key) { }

	bool alive;

	const physx::PxTransform& getTransform() const { return trans; }
	std::string getType() const { return type; }
protected:
	physx::PxTransform trans;
	RenderItem* render;
	std::string type;
};
