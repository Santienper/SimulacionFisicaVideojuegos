#include "ForceEffectSphere.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"

ForceEffectSphere::ForceEffectSphere(ForceGenerator* force, const Vector3& pos, float radius) : Trigger(pos), force(force), radius(radius) {
	sys = Scene::get()->getSystem("forces").cast<ForceSystem>();
	setCallbackEnter([&, force](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(obj->getType() == "particle") {
			sys->addConnection(static_cast<Particle*>(obj), force);
		}
	});
	setCallbackExit([&, force](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(obj->getType() == "particle") {
			sys->deleteConnection(static_cast<Particle*>(obj), force);
		}
	});
}

ForceEffectSphere::~ForceEffectSphere() {
	
}

bool ForceEffectSphere::isInside(Object* obj) {
	return (obj->getTransform().p - trans.p).magnitude() < radius;
}
