#include "RDObject.h"
#include "Structure/Scene.h"

RDObject::RDObject(physx::PxGeometry* geo, const Vector3& vel, float damp, float mass, const Vector4& color) : RDObject(Vector3(0), geo, vel, damp, mass, color) {

}

RDObject::RDObject(const Vector3& pos, physx::PxGeometry* geo, const Vector3& vel, float damp, float mass, const Vector4& color) : PhysicsObject(pos), disappearing(false) {
	rigid = Scene::get()->getPhysics()->createRigidDynamic(trans);
	Scene::get()->addActor(*rigid);
	physx::PxRigidBodyExt::setMassAndUpdateInertia(*rigid, mass);
	rigid->setLinearDamping(damp);
	rigid->setLinearVelocity(vel);
	if(geo != nullptr) createShape(geo, color);
}

void RDObject::createShape(physx::PxGeometry* geo, const Vector4& color) {
	shape = CreateShape(*geo);
	rigid->attachShape(*shape);
	render = new RenderItem(shape, rigid, color);
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
