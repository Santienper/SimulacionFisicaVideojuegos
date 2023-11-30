#include "MovingBox.h"

MovingBox::MovingBox(const Vector3& pos, const Vector3& halfExtents, const Vector3& vel, const Vector3& acc, float damp, float mass)
	: MovingObject(pos, vel, acc, damp, mass), halfExtents(halfExtents) {

	color = { 0.5, 1, 1, 1 };
	physx::PxBoxGeometry a; a.halfExtents = halfExtents;
	auto shape = CreateShape(a);
	render = new RenderItem(shape, &trans, color);
	
	// Recordatorio que halfExtents contiene el "radio" del cuboide, es decir, la mitad de sus medidas completas
	volume = (2 * halfExtents.x) * (2 * halfExtents.z) * (2 * halfExtents.y); // Volumen cuboide: area de la base * altura = alto base * ancho base * altura
	density = volume == 0 ? 0 : mass / volume; // Densidad objeto homogéneo: masa / volumen
}

void MovingBox::updateMass(float pMass) {
	if(mass + pMass < 0) return;
	mass += pMass; inv_mass = mass == 0 ? 0 : 1 / mass;
	density = volume == 0 ? 0 : mass / volume;
}

void MovingBox::updateBaseArea(float length) {
	if(halfExtents.x + length <= 0 || halfExtents.z + length <= 0) return;
	halfExtents.x += length; halfExtents.z += length;
	volume = (2 * halfExtents.x) * (2 * halfExtents.z) * (2 * halfExtents.y);
	density = volume == 0 ? 0 : mass / volume;

	updateShape();
}

void MovingBox::updateColor(Vector4 color) {
	this->color = color;

	updateShape();
}

void MovingBox::updateShape() {
	physx::PxBoxGeometry a; a.halfExtents = halfExtents;
	auto shape = CreateShape(a);
	render->release();
	render = new RenderItem(shape, &trans, color);
}
