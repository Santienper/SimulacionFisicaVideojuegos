#pragma once
#include "Scene.h"

class Map {
public:
	Map() : scene(Scene::get()) { }
	virtual void createMap() = 0;
	virtual void deleteMap() { }
	virtual void clearedTargets() = 0;
protected:
	SpPtr<Scene> scene;
};