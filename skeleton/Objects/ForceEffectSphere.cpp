#include "ForceEffectSphere.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"
#include "ForceGenerators/ForceGenerator.h"

ForceEffectSphere::ForceEffectSphere(ForceGenerator* force, const Vector3& pos, float radius) : Trigger(pos), force(force), radius(radius) {
	sys = scene->getSystem<ForceSystem>();
	setCallbackEnter([&, force](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(!force->alive) return;
		if(obj->isType("physics")) {
			sys->addConnection(static_cast<PhysicsObject*>(obj), force);
		}
	});
	setCallbackExit([&, force](Object* obj) -> void {
		if(sys == nullptr) { alive = false; return; }
		if(obj->isType("physics")) {
			sys->deleteConnection(static_cast<PhysicsObject*>(obj), force);
		}
	});
}

bool ForceEffectSphere::isInside(Object* obj) {
	Vector3 pos = (obj->getPos() - trans.p).abs();
	return pos.magnitude() < radius;
}
