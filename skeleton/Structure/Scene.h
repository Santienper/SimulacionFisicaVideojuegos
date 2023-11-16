#pragma once
#include "Core/RenderUtils.hpp"
#include <unordered_map>
#include "Utilities/SpPtr.h"

void createScene();

class Scene {
	friend class Object;
	friend class System;
public:
	static SpPtr<Scene> get() { return *safeInstance; }
	Scene();
	virtual ~Scene();

	Camera* cam;

	SpPtr<System> getSystem(std::string id);
	std::vector<SpPtr<Object>>* getObjects();

	void update(double t);
	void keyPressed(unsigned char key);
	void commit();
protected:
	std::vector<SpPtr<Object>> objects, objToAdd;
	std::unordered_map<std::string, SpPtr<System>> systems;
	std::vector<std::pair<std::string, SpPtr<System>>> sysToAdd;
private:
	void addObject(Object* obj);
	void addSystem(System* sys, std::string id);

	static Scene* instance;
	static SpPtr<Scene>* safeInstance;
};