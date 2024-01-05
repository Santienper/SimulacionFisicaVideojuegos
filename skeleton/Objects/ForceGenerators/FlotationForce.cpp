#include "FlotationForce.h"
#include "../Not important/MovingBox.h"

FlotationForce::FlotationForce(const Vector3& pos, float liquidDensity) : ForceGenerator(pos), liquidDensity(liquidDensity) {
	
}

void FlotationForce::updateForce(PhysicsObject* obj, double t) {
	// Se asume que el objeto es un MovingBox
	MovingBox* box = static_cast<MovingBox*>(obj);
	int immersed;
	const float halfHeight = box->getHalfExtents().y;
	if(obj->getTransform().p.y - trans.p.y > halfHeight) {
		immersed = 0.0;
	} else if(trans.p.y - obj->getTransform().p.y > halfHeight) {
		immersed = 1.0;
	} else {
		immersed = (trans.p.y - obj->getTransform().p.y) / halfHeight * 2 + 0.5;
	}

	obj->addForce({ 0, liquidDensity * box->getVolume() * immersed * 9.8f, 0 });
}
