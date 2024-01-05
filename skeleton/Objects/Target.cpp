#include "Target.h"
#include "Structure/Scene.h"
#include "Utilities/Log.h"

Target::Target(const Vector3& pos, const Vector4& color) : RSObject(pos, nullptr) {
	sys = Scene::get()->getSystem<TargetSystem>();
	if(sys == nullptr) {
		alive = false;
		Logger::logError("No hay sistema de dianas, omitiendo creacion de diana");
		return;
	}
	sys->addTarget(this);

	physx::PxGeometry* geo = new physx::PxSphereGeometry(3);
	createShape(geo, color);
	delete geo;
}

Target::~Target() {

}

void Target::hit() {
	sys->targetHit(this);
}
