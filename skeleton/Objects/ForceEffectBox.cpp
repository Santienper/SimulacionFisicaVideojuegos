#include "ForceEffectBox.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"
#include "ForceGenerators/ForceGenerator.h"

ForceEffectBox::ForceEffectBox(ForceGenerator* force, const Vector3& pos, const Vector3& halfExtents) : Trigger(pos), force(force), halfExtents(halfExtents) {
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

bool ForceEffectBox::isInside(Object* obj) {
	Vector3 pos = (obj->getPos() - trans.p).abs();
	return pos.x > -halfExtents.x && pos.x < halfExtents.x && pos.y > -halfExtents.y && pos.y < halfExtents.y && pos.z > -halfExtents.z && pos.z < halfExtents.z;
}
