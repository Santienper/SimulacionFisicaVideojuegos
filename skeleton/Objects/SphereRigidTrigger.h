#pragma once
#include "Trigger.h"

class SphereRigidTrigger : public Trigger {
public:
	SphereRigidTrigger(const Vector3& pos = Vector3(0), float radius = 10);
protected:
	virtual bool isInside(Object*);
private:
	float radius;
};

class SphereRigidPublicTrigger : public SphereRigidTrigger {
public:
	SphereRigidPublicTrigger(const Vector3& pos = Vector3(0), float radius = 10);

	void setCallbackEnter(const std::function<void(Object*)>& callbackEnter);
	void setCallbackLoop(const std::function<void(Object*)>& callbackLoop);
	void setCallbackExit(const std::function<void(Object*)>& callbackExit);
};