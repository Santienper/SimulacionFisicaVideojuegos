#pragma once
#include "Structure/Object.h"
#include <functional>
#include <unordered_set>

class Trigger : public Object {
public:
	Trigger(const Vector3& pos = Vector3(0), physx::PxGeometryHolder area = {});
	void update(double t);

	void setCallbackEnter(const std::function<void(const Object*)>& callbackEnter);
	void setCallbackLoop(const std::function<void(const Object*)>& callbackLoop);
	void setCallbackExit(const std::function<void(const Object*)>& callbackExit);
protected:
	virtual bool isInside(const Object*) = 0;
private:
	std::function<void(const Object*)> callbackEnter, callbackLoop, callbackExit;
	physx::PxGeometryHolder area;
	std::unordered_set<const Object*> objects;
};