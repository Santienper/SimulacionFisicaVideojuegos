#include "ForceEffectSphere.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"

ForceEffectSphere::ForceEffectSphere(ForceGenerator* force, const Vector3& pos, float radius) : Trigger(pos), force(force), radius(radius) {
	SpPtr<ForceSystem> sys = Scene::get()->getSystem("forces").cast<ForceSystem>();
	setCallbackEnter([&](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(Particle* part = dynamic_cast<Particle*>(obj)) {
			sys->addConnection(part, force);
		}
	});
	setCallbackExit([&](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(Particle* part = dynamic_cast<Particle*>(obj)) {
			sys->deleteConnection(part, force);
		}
	});
}

ForceEffectSphere::~ForceEffectSphere() {
	
}

bool ForceEffectSphere::isInside(Object* obj) {
	return (obj->getTransform().p - trans.p).magnitude() < radius;
}
