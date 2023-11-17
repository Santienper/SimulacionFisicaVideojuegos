#include "ForceGenerator.h"
#include "Structure/Scene.h"
#include <iostream>

ForceGenerator::ForceGenerator(const Vector3& pos) : Object(pos) {
	sys = Scene::get()->getSystem("forces").cast<ForceSystem>();
	if(sys == nullptr) {
		alive = false;
		std::cout << "[ERROR] No hay sistema de fuerzas, omitiendo creacion de generador de fuerzas\n";
	}
}

ForceGenerator::~ForceGenerator() {
	
}

void ForceGenerator::deleteForce() {
	sys->deleteForce(this);
}
