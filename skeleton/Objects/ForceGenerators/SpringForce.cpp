#include "SpringForce.h"
#include "Structure/Scene.h"
#include "Systems/ForceSystem.h"

SpringForce::SpringForce(float k, float restingLength) : obj1(nullptr), obj2(nullptr), k(k), restingLength(restingLength) {

}

SpringForce::~SpringForce() {

}

void SpringForce::updateForce(Particle* part, double t) {
	if(obj1 == nullptr || obj2 == nullptr) return;
	Object* other;
	if(part == obj1) other = obj2;
	else if(part == obj2) other = obj1;
	else {
		// Intruso!
		//sys->deleteConnection(part, this);
		return;
	}
	Vector3 distance = other->getTransform().p - part->getTransform().p;
	// Está fuera de addForce() porque normalize también normaliza el vector.
	float length = distance.normalize();
	
	part->addForce(distance * k * (length - restingLength));
}

bool SpringForce::addObject(Object* part) {
	if(sys == nullptr) { alive = false; return false; }

	if(obj1 == nullptr) {
		obj1 = part;
	} else if(obj2 == nullptr) {
		obj2 = part;
	} else {
		return false;
	}
	return true;
}

bool SpringForce::addParticle(Particle* part) {
	bool done = addObject(part);
	if(done) sys->addConnection(part, this);
	return done;
}
