#include "WhirlwindForce.h"

WhirlwindForce::WhirlwindForce(const Vector3& pos, float windConst, float forceConst) : WindForce(Vector3(0), windConst, pos), forceConst(forceConst) {
	
}

void WhirlwindForce::getWindVel(Particle* p) {
	const physx::PxTransform partTrans = p->getTransform();
	wind = forceConst * Vector3(trans.p.z - partTrans.p.z, trans.p.y + 50 - partTrans.p.y, partTrans.p.x - trans.p.x);
}
