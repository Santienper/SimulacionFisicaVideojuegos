#include "MovingBox.h"

MovingBox::MovingBox(const Vector3& pos, const Vector3& vel, const Vector3& acc, float radius, float damp, float mass)
	: Particle(pos, vel, acc, radius, damp, mass) {
	
}
