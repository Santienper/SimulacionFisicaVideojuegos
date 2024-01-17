#include "Scene.h"
#include "Object.h"
#include "System.h"
#include "Core/RenderUtils.hpp"
#include "Map.h"

Scene::Scene(pxData physxData, std::string& display_text) : closing(false), physxData(physxData), display_text(display_text), currentMap(-1) {
	cam = GetCamera();
	instance = this;
	safeInstance = new SpPtr<Scene>(this);
	_setScene(this);
}

Scene::~Scene() {
	closing = true;
	loadMap(-1);
	for(auto& obj : objects) {
		obj.free();
	}
	for(auto& sys : systems) {
		sys.second.free();
	}
	for(Map* map : maps) {
		delete map;
	}
	instance = nullptr;
	_setScene(nullptr);
}

void Scene::init() {
	maps = createMaps();
	loadMap(0);
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
	for(auto& obj : keyPressSubs) {
		obj->keyPressed(key);
	}
}

void Scene::keyReleased(unsigned char key) {
	for(auto& pair : systems) {
		pair.second->keyReleased(key);
	}
	for(auto& obj : keyReleaseSubs) {
		obj->keyReleased(key);
	}
}

void Scene::specialKeyPressed(int key) {
	for(auto& pair : systems) {
		pair.second->specialKeyPressed(key);
	}
	for(auto& obj : keyPressSubs) {
		obj->specialKeyPressed(key);
	}
}

void Scene::specialKeyReleased(int key) {
	for(auto& pair : systems) {
		pair.second->specialKeyReleased(key);
	}
	for(auto& obj : keyReleaseSubs) {
		obj->specialKeyReleased(key);
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

void Scene::resetRender() {
	for(auto obj : resetRenderSubs) {
		DeregisterRenderItem(obj->render);
		RegisterRenderItem(obj->render);
	}
}

void Scene::nextMap() {
	loadMap(currentMap + 1);
}

void Scene::loadMap(int mapIndex) {
	if(currentMap > -1) {
		maps[currentMap]->deleteMap();
		for(auto& sys : systems) {
			sys.second->clear();
		}
		for(auto& obj : objects) {
			obj->alive = false;
		}
	}
	if(mapIndex > -1) maps[mapIndex]->createMap();
	resetRender();
	currentMap = mapIndex;
}

void Scene::addObject(Object* obj) {
	objToAdd.push_back(obj);
}

void Scene::addSystem(System* sys, const std::string& id) {
	sysToAdd.push_back(std::make_pair(id, sys));
}

void Scene::subKeyPress(Object* obj, bool add) {
	if(add) keyPressSubs.push_back(obj);
	else {
		for(auto it = keyPressSubs.cbegin(); it != keyPressSubs.cend(); ++it) {
			if(*it == obj) {
				keyPressSubs.erase(it);
				break;
			}
		}
	}
}

void Scene::subKeyRelease(Object* obj, bool add) {
	if(add) keyReleaseSubs.push_back(obj);
	else {
		for(auto it = keyReleaseSubs.cbegin(); it != keyReleaseSubs.cend(); ++it) {
			if(*it == obj) {
				keyReleaseSubs.erase(it);
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

void Scene::subResetRender(Object* obj, bool add) {
	if(add) resetRenderSubs.push_back(obj);
	else {
		for(auto it = resetRenderSubs.cbegin(); it != resetRenderSubs.cend(); ++it) {
			if(*it == obj) {
				resetRenderSubs.erase(it);
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