#pragma once
#include "../Particle.h"

class MovingBox : public MovingObject {
public:
	MovingBox(const Vector3& pos = Vector3(0), const Vector3& halfExtents = Vector3(3), const Vector3& vel = Vector3(0), const Vector3& acc = Vector3(0), float damp = 0.998f, float mass = 1);

	Vector3 getHalfExtents() const { return halfExtents; }
	float getVolume() const noexcept { return volume; }

	void updateMass(float mass);
	void updateBaseArea(float length);
protected:
	Vector3 halfExtents;
	float volume, density;
	physx::PxShape* shape;
	Vector4 color;

	void updateColor(Vector4 color);
private:
	void updateShape();
};