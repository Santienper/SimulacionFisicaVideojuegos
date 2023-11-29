#include "Scene.h"
#include "Object.h"
#include "System.h"

Scene::Scene(std::string& display_text) : closing(false), display_text(display_text) {
	cam = GetCamera();
	instance = this;
	safeInstance = new SpPtr<Scene>(this);
}

Scene::~Scene() {
	closing = true;
	for(auto& obj : objects) {
		obj.free();
	}
	for(auto& sys : systems) {
		sys.second.free();
	}
}

void Scene::update(double t) {
	for(auto& pair : systems) {
		pair.second->update(t);
	}
	for(auto obj : objects) {
		obj->update(t);
	}

	// Se borran los objetos y los sistemas que se necesiten borrar
	auto objIt = objects.begin();
	while(objIt != objects.end()) {
		if(!(*objIt)->alive) {
			objIt->free();
			objIt = objects.erase(objIt);
		} else ++objIt;
	}

	auto sysIt = systems.begin();
	while(sysIt != systems.end()) {
		if(!sysIt->second->alive) {
			sysIt->second.free();
			sysIt = systems.erase(sysIt);
		} else ++sysIt;
	}
}

void Scene::keyPressed(unsigned char key) {
	for(auto& pair : systems) {
		pair.second->keyPressed(key);
	}
	for(auto obj : objects) {
		obj->keyPressed(key);
	}
}

void Scene::commit() {
	for(auto obj : objToAdd) {
		objects.push_back(obj);
	}
	objToAdd.clear();
	for(auto& sys : sysToAdd) {
		systems[sys.first] = sys.second;
	}
	sysToAdd.clear();
}

void Scene::addObject(Object* obj) {
	objToAdd.push_back(obj);
}

void Scene::addSystem(System* sys, std::string id) {
	sysToAdd.push_back(std::make_pair(id, sys));
}

SpPtr<System> Scene::getSystem(std::string id) {
	// Busca en los sistemas ya establecidos
	auto it = systems.find(id);
	if(it != systems.end()) return it->second;
	// Si no encuentra el sistema, busca en los que se acaban de añadir
	for(auto& data : sysToAdd) {
		if(data.first == id) return data.second;
	}
	// Si no lo encuentra, devuelve nullptr
	return nullptr;
}

std::vector<SpPtr<Object>>* Scene::getObjects() {
	return &objects;
}

Scene* Scene::instance = nullptr;

SpPtr<Scene>* Scene::safeInstance = nullptr;