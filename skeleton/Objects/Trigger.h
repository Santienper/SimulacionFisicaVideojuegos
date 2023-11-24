#pragma once
#include "Structure/Object.h"
#include <functional>
#include <unordered_set>

class Trigger : public Object {
public:
	Trigger(const Vector3& pos = Vector3(0));
	~Trigger();
	void update(double t);
protected:
	virtual bool isInside(Object*) = 0;

	void setCallbackEnter(const std::function<void(Object*)>& callbackEnter);
	void setCallbackLoop(const std::function<void(Object*)>& callbackLoop);
	void setCallbackExit(const std::function<void(Object*)>& callbackExit);
private:
	std::function<void(Object*)> callbackEnter, callbackLoop, callbackExit;
	std::unordered_set<Object*> objects;
	std::vector<SpPtr<Object>>* sceneObjects;
};

class PublicTrigger : public Trigger {
public:
	PublicTrigger(const Vector3& pos = Vector3(0));

	void setCallbackEnter(const std::function<void(Object*)>& callbackEnter);
	void setCallbackLoop(const std::function<void(Object*)>& callbackLoop);
	void setCallbackExit(const std::function<void(Object*)>& callbackExit);
};