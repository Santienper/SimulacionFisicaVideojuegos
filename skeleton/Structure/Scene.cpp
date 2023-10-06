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
	for(auto obj : objects) {
		obj->keyPressed(key);
	}
}

void Scene::addObjects() {
	for(auto obj : toAdd) {
		objects.push_back(obj);
	}
	toAdd.clear();
}

void Scene::addObject(Object* obj) {
	toAdd.push_back(obj);
}

Scene* Scene::instance = nullptr;