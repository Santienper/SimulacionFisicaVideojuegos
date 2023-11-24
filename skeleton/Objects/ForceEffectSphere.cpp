#include "ForceEffectSphere.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"
#include "ForceGenerators/ForceGenerator.h"

ForceEffectSphere::ForceEffectSphere(ForceGenerator* force, const Vector3& pos, Vector3 radius) : Trigger(pos), force(force), radius(radius) {
	sys = Scene::get()->getSystem("forces").cast<ForceSystem>();
	setCallbackEnter([&, force](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(!force->alive) return;
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
	Vector3 pos = (obj->getTransform().p - trans.p).abs();
	return pos.magnitudeSquared() < radius.magnitudeSquared();
}
