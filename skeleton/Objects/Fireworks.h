#pragma once
#include "Particle.h"

#define FIREWORK_ARGS const Vector3& pos = Vector3(0), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float damp = 0.998f, float mass = 1

class Firework1 : public Particle {
public:
	Firework1(FIREWORK_ARGS);
	~Firework1();
};

class Firework2 : public Particle {
public:
	Firework2(FIREWORK_ARGS);
	~Firework2();
};

class Firework3 : public Particle {
public:
	Firework3(FIREWORK_ARGS);
	~Firework3();
};

#undef FIREWORK_ARGS