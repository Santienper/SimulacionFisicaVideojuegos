#include "RSObject.h"
#include "Structure/Scene.h"

RSObject::RSObject(physx::PxGeometry* geo) : RSObject(Vector3(0), geo) {

}

RSObject::RSObject(const Vector3& pos, physx::PxGeometry* geo) : Object(pos) {
	rigid = Scene::get()->getPhysics()->createRigidStatic(trans);
	physx::PxShape* shape = CreateShape(*geo);
	rigid->attachShape(*shape);
	Scene::get()->addActor(*rigid);
	Vector4 color = { 1, 0.5, 1, 1 };
	render = new RenderItem(shape, rigid, color);
}

RSObject::~RSObject() {
	
}
