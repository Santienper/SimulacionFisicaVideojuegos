#include "RDObject.h"
#include "Structure/Scene.h"

RDObject::RDObject(physx::PxGeometry* geo) : RDObject(Vector3(0), geo) {

}

RDObject::RDObject(const Vector3& pos, physx::PxGeometry* geo) : Object(pos) {
	rigid = Scene::get()->getPhysics()->createRigidDynamic(trans);
	physx::PxShape* shape = CreateShape(*geo);
	rigid->attachShape(*shape);
	physx::PxRigidBodyExt::setMassAndUpdateInertia(*rigid, 0.15);
	Scene::get()->addActor(*rigid);
	Vector4 color = { 1, 0.5, 1, 1 };
	render = new RenderItem(shape, rigid, color);
	rigid->setLinearDamping(0.8f);
}

RDObject::~RDObject() {

}
