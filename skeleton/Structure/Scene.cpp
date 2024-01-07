#include "Scene.h"
#include "Object.h"
#include "System.h"
#include "Core/RenderUtils.hpp"

Scene::Scene(pxData physxData, std::string& display_text) : closing(false), physxData(physxData), display_text(display_text) {
	cam = GetCamera();
	instance = this;
	safeInstance = new SpPtr<Scene>(this);
	_setScene(this);
}

Scene::~Scene() {
	closing = true;
	for(auto& obj : objects) {
		obj.free();
	}
	for(auto& sys : systems) {
		sys.second.free();
	}
	_setScene(nullptr);
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
	for(auto& obj : keySubs) {
		obj->keyPressed(key);
	}
}

void Scene::mousePressed(int button, int state, int x, int y) {
	for(auto& pair : systems) {
		pair.second->mousePressed(button, state, x, y);
	}
	for(auto& obj : mousePressSubs) {
		obj->mousePressed(button, state, x, y);
	}
}

void Scene::mouseMoved(int x, int y) {
	for(auto& pair : systems) {
		pair.second->mouseMoved(x, y);
	}
	for(auto& obj : mouseMoveSubs) {
		obj->mouseMoved(x, y);
	}
}

void Scene::commit() {
	for(auto obj : objToAdd) {
		if(obj->alive) objects.push_back(obj);
		else obj.free();
	}
	objToAdd.clear();
	for(auto& sys : sysToAdd) {
		if(sys.second->alive) systems[sys.first] = sys.second;
		else sys.second.free();
	}
	sysToAdd.clear();
}

void Scene::addObject(Object* obj) {
	objToAdd.push_back(obj);
}

void Scene::addSystem(System* sys, const std::string& id) {
	sysToAdd.push_back(std::make_pair(id, sys));
}

void Scene::subKey(Object* obj, bool add) {
	if(add) keySubs.push_back(obj);
	else {
		for(auto it = keySubs.cbegin(); it != keySubs.cend(); ++it) {
			if(*it == obj) {
				keySubs.erase(it);
				break;
			}
		}
	}
}

void Scene::subMousePress(Object* obj, bool add) {
	if(add) mousePressSubs.push_back(obj);
	else {
		for(auto it = mousePressSubs.cbegin(); it != mousePressSubs.cend(); ++it) {
			if(*it == obj) {
				mousePressSubs.erase(it);
				break;
			}
		}
	}
}

void Scene::subMouseMove(Object* obj, bool add) {
	if(add) mouseMoveSubs.push_back(obj);
	else {
		for(auto it = mouseMoveSubs.cbegin(); it != mouseMoveSubs.cend(); ++it) {
			if(*it == obj) {
				mouseMoveSubs.erase(it);
				break;
			}
		}
	}
}

std::vector<SpPtr<Object>>* Scene::getObjects() {
	return &objects;
}

SpPtr<System> Scene::getSystem(const std::string& id) {
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

Scene* Scene::instance = nullptr;

SpPtr<Scene>* Scene::safeInstance = nullptr;