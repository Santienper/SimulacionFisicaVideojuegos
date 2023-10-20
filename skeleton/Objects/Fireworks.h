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

class Firework4 : public Particle {
public:
	Firework4(FIREWORK_ARGS);
	~Firework4();
};

class Firework5 : public Particle {
public:
	Firework5(FIREWORK_ARGS);
	~Firework5();
};

class Firework6 : public Particle {
public:
	Firework6(FIREWORK_ARGS);
	~Firework6();
};

#undef FIREWORK_ARGS