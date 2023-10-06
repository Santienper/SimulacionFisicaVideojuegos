#pragma once
#include "Core/RenderUtils.hpp"
#include <unordered_map>

void createScene();

class Scene {
	friend class Object;
	friend class System;
public:
	static Scene* get() { return instance; }
	Scene();
	virtual ~Scene();

	Camera* cam;

	System* getSystem(std::string id);

	void update(double t);
	void keyPressed(unsigned char key);
	void commit();
protected:
	std::vector<Object*> objects, objToAdd;
	std::unordered_map<std::string, System*> systems;
	std::vector<std::pair<std::string, System*>> sysToAdd;
private:
	void addObject(Object* obj);
	void addSystem(System* sys, std::string id);

	static Scene* instance;
};