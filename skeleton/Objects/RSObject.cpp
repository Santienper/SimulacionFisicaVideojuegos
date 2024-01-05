#include "RSObject.h"
#include "Structure/Scene.h"

RSObject::RSObject(physx::PxGeometry* geo, const Vector4& color) : RSObject(Vector3(0), geo, color) {

}

RSObject::RSObject(const Vector3& pos, physx::PxGeometry* geo, const Vector4& color) : Object(pos) {
	rigid = Scene::get()->getPhysics()->createRigidStatic(trans);
	if(geo != nullptr) createShape(geo, color);
	trans.p += pos;
}

RSObject::~RSObject() {
	
}

void RSObject::createShape(physx::PxGeometry* geo, const Vector4& color) {
	physx::PxShape* shape = CreateShape(*geo);
	rigid->attachShape(*shape);
	Scene::get()->addActor(*rigid);
	render = new RenderItem(shape, rigid, color);
}
