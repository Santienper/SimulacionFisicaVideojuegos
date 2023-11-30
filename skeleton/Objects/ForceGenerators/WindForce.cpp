#include "WindForce.h"

WindForce::WindForce(const Vector3& wind, float k, const Vector3& pos) : ForceGenerator(pos), wind(wind), k(k) {
	
}

void WindForce::updateForce(MovingObject* obj, double t) {
	getWindVel(obj, t);
	obj->addForce(k * (wind - obj->getVel())); // 𝐹𝑣⃗⃗⃗ = 𝑘1(𝑣𝑣 − 𝑣 ) + 𝑘2‖𝑣𝑣 − 𝑣 ‖(𝑣𝑣 − 𝑣 ) | k2 = 0
}
