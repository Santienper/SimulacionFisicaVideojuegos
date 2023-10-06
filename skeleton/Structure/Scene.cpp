#include "Scene.h"
#include "Object.h"
#include "Objects/Shooter.h"

Scene::Scene() {
	cam = GetCamera();
	instance = this;
}

Scene::~Scene() {
	for(auto obj : objects) {
		delete obj;
	}
}

void Scene::update(double t) {
	for(auto obj : objects) {
		obj->update(t);
	}

	// Se borran los objetos que se necesiten borrar
	auto it = objects.begin();
	while(it != objects.end()) {
		if(!(*it)->alive) {
			delete* it;
			it = objects.erase(it);
		} else ++it;
	}
}

void Scene::keyPressed(unsigned char key) {
	/*auto it = objects.begin();
	while(it != objects.end()) {
		(*it)->keyPressed(key);
		++it;
	}*/
	shoot->keyPressed(key);
}

void Scene::addObject(Object* obj) {
	objects.push_back(obj);
}

Scene* Scene::instance = nullptr;