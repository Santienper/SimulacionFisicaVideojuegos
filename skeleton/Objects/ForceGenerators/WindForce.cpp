﻿#include "WindForce.h"

WindForce::WindForce(const Vector3& wind, float k) : wind(wind), k(k) {
	
}

void WindForce::updateForce(Particle* p) {
	p->addForce(k * (wind - p->getVel())); // 𝐹𝑣⃗⃗⃗ = 𝑘1(𝑣𝑣 − 𝑣 ) + 𝑘2‖𝑣𝑣 − 𝑣 ‖(𝑣𝑣 − 𝑣 ) | k2 = 0
}
