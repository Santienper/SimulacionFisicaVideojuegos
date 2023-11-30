#pragma once
#include "Particle.h"

class MovingBox : public Particle {
public:
	MovingBox(const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float radius = 3, float damp = 0.998f, float mass = 1);


};