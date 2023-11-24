#include "ExplosionForce.h"
#include "../ForceEffectSphere.h"

ExplosionForce::ExplosionForce(const Vector3& pos, const Vector3& radius, float intensity, float timeConst)
	: radius(radius), intensity(intensity), timeConst(timeConst), time(0) {
	area = new ForceEffectSphere(this, pos, radius);
}

ExplosionForce::~ExplosionForce() {
	area->alive = false;
}

void ExplosionForce::updateForce(Particle* p, double t) {
	time += t;
	if(time >= 4 * timeConst) deleteForce();
	const Vector3 r = p->getTransform().p - trans.p;
	if(r.magnitudeSquared() < radius.magnitudeSquared()) { // Se usa r^2 y R^2 ya que es más eficiente en cuanto a los cálculos.
		p->addForce((intensity / r.magnitudeSquared()) * r * exp(-time / timeConst));
	}
}
