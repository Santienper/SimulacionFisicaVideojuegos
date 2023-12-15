#include "SpringForce.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"

SpringForce::SpringForce(float k, float restingLength) : obj1(nullptr), obj2(nullptr), k(k), restingLength(restingLength) {

}

SpringForce::~SpringForce() {

}

void SpringForce::updateForce(PhysicsObject* obj, double t) {
	if(obj1 == nullptr || obj2 == nullptr) return;
	Object* other;
	if(obj == obj1) other = obj2;
	else if(obj == obj2) other = obj1;
	else {
		// Intruso!
		//sys->deleteConnection(obj, this);
		return;
	}
	Vector3 distance = other->getTransform().p - obj->getTransform().p;
	// Está fuera de addForce() porque normalize también normaliza el vector.
	float length = distance.normalize();
	
	obj->addForce(distance * k * (length - restingLength));
}

bool SpringForce::addObject(Object* obj) {
	if(sys == nullptr) { alive = false; return false; }

	if(obj1 == nullptr) {
		obj1 = obj;
	} else if(obj2 == nullptr) {
		obj2 = obj;
	} else {
		return false;
	}
	return true;
}

bool SpringForce::addPhysicsObject(PhysicsObject* obj) {
	const bool done = addObject(obj);
	if(done) sys->addConnection(obj, this);
	return done;
}
