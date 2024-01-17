#include "RSObject.h"
#include "Structure/Scene.h"

RSObject::RSObject(physx::PxGeometry* geo, const Vector4& color) : RSObject(Vector3(0), geo, color) {

}

RSObject::RSObject(const Vector3& pos, physx::PxGeometry* geo, const Vector4& color) : Object(pos) {
	rigid = scene->getPhysics()->createRigidStatic(trans);
	scene->addActor(*rigid);
	if(geo != nullptr) createShape(geo, color);
}

Vector3 RSObject::getPos() const {
	return rigid->getGlobalPose().p;
}

RSObject::~RSObject() {
	scene->removeActor(*rigid);
}

void RSObject::createShape(physx::PxGeometry* geo, const Vector4& color) {
	physx::PxShape* shape = CreateShape(*geo);
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
	if(color.w < 1) subRenderReset(true);
}
