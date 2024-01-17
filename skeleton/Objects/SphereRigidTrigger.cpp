#include "SphereRigidTrigger.h"
#include "RSObject.h"
#include "RDObject.h"

SphereRigidTrigger::SphereRigidTrigger(const Vector3& pos, float radius) : Trigger(pos), radius(radius) {
	
}

bool SphereRigidTrigger::isInside(Object* obj) {
	if(!obj->isType("rigid")) return false;

	Vector3 pos;
	if(obj->isType("physics")) pos = static_cast<RDObject*>(obj)->getPos();
	else pos = static_cast<RSObject*>(obj)->getPos();
	pos = (pos - trans.p).abs();
	return pos.magnitude() < radius;
}

SphereRigidPublicTrigger::SphereRigidPublicTrigger(const Vector3& pos, float radius) : SphereRigidTrigger(pos, radius) {

}

void SphereRigidPublicTrigger::setCallbackEnter(const std::function<void(Object*)>& callback) {
	Trigger::setCallbackEnter(callback);
}

void SphereRigidPublicTrigger::setCallbackLoop(const std::function<void(Object*)>& callback) {
	Trigger::setCallbackLoop(callback);
}

void SphereRigidPublicTrigger::setCallbackExit(const std::function<void(Object*)>& callback) {
	Trigger::setCallbackExit(callback);
}
