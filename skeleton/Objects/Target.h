#pragma once
#include "RSObject.h"
#include "Systems/TargetSystem.h"

class SphereRigidPublicTrigger;

class Target : public Object {
public:
	Target(const Vector3& pos = Vector3(0), const Vector4& color = { 1, 0.5, 1, 1 });
	~Target();

	void hit();
private:
	SpPtr<TargetSystem> sys;
	SphereRigidPublicTrigger* trigger;
};