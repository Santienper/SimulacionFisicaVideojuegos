#include "RDObject.h"
#include "Structure/Scene.h"

RDObject::RDObject(physx::PxGeometry* geo, float damp, float mass) : RDObject(Vector3(0), geo, damp, mass) {

}

RDObject::RDObject(const Vector3& pos, physx::PxGeometry* geo, float damp, float mass) : PhysicsObject(pos), disappearing(false) {
	rigid = Scene::get()->getPhysics()->createRigidDynamic(trans);
	shape = CreateShape(*geo);
	rigid->attachShape(*shape);
	physx::PxRigidBodyExt::setMassAndUpdateInertia(*rigid, mass);
	Scene::get()->addActor(*rigid);
	Vector4 color = { 1, 0.5, 1, 1 };
	render = new RenderItem(shape, rigid, color);
	rigid->setLinearDamping(damp);
}

RDObject::~RDObject() {

}

void RDObject::update(double t) {
	if(disappearing) {
		auto geo = shape->getGeometry();
		bool die = false;
		switch(geo.getType()) {
		case physx::PxGeometryType::eSPHERE:
			geo.sphere().radius -= 0.05;
			die = geo.sphere().radius <= 0;
		case physx::PxGeometryType::eBOX:
			Vector3& hE = geo.box().halfExtents;
			hE -= Vector3(0.05);
			die = hE.x <= 0 || hE.y <= 0 || hE.z <= 0;
		}
		if(die) {
			alive = false;
			callbackDelete();
		} else {
			shape = CreateShape(geo.any());
			const Vector4 color = render->color;
			render->release();
			render = new RenderItem(shape, &trans, color);
		}
	}
}

void RDObject::addForce(const Vector3& force) {
	rigid->addForce(force);
}

void RDObject::clearAcum() {
	rigid->clearForce();
}

Vector3 RDObject::getVel() const {
	return rigid->getLinearVelocity();
}

float RDObject::getMass() const {
	return rigid->getMass();
}

void RDObject::disappear() {
	disappearing = true;
}
