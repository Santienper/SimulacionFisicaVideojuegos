#include "FlotationForce.h"

FlotationForce::FlotationForce(const Vector3& pos) : ForceGenerator(pos) {
	
}

void FlotationForce::updateForce(Particle* p, double t) {
	int immersed;
	// TODO Hacer bien lo de height, liquid_density y volume
	float height = 1, liquid_density = 1, volume = 1;
	if(p->getTransform().p.y - trans.p.y > height * 0.5) {
		immersed = 0.0;
	} else if(trans.p.y - p->getTransform().p.y > height * 0.5) {
		immersed = 1.0;
	} else {
		immersed = (trans.p.y - p->getTransform().p.y) / height + 0.5;
	}

	p->addForce({ 0, liquid_density * volume * immersed * 9.8, 0 });
}
