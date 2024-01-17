#include "Target.h"
#include "Structure/Scene.h"
#include "SphereRigidTrigger.h"

Target::Target(const Vector3& pos, const Vector4& color) : Object(pos), sys(nullptr), trigger(nullptr) {
	sys = scene->getSystem<TargetSystem>();
	if(sys == nullptr) {
		alive = false;
		Log::logError("No hay sistema de dianas, omitiendo creacion de diana");
		return;
	}
	sys->addTarget(this);

	const int radius = 5;

	auto geo = physx::PxSphereGeometry(radius);
	physx::PxShape* shape = CreateShape(geo);
	render = new RenderItem(shape, &trans, color);

	trigger = new SphereRigidPublicTrigger(pos, radius);
	trigger->setCallbackEnter([this](Object*) -> void {
		hit();
	});
}

Target::~Target() {
	trigger->alive = false;
}

void Target::hit() {
	sys->targetHit(this);
}
