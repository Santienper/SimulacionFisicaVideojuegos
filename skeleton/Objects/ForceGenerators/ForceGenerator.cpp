#include "ForceGenerator.h"
#include "Structure/Scene.h"

ForceGenerator::ForceGenerator(const Vector3& pos) : Object(pos) {
	sys = Scene::get()->getSystem<ForceSystem>();
	if(sys == nullptr) {
		alive = false;
		Log::logError("No hay sistema de fuerzas, omitiendo creacion de generador de fuerzas");
	}
}

ForceGenerator::~ForceGenerator() {
	
}

void ForceGenerator::deleteForce() {
	sys->deleteForce(this);
}
