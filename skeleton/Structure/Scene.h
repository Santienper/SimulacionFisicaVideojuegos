#pragma once
#include "Core/RenderUtils.hpp"
#include <unordered_map>
#include "Utilities/SpPtr.h"

void createScene();
void deleteScene();

struct pxData {
	physx::PxFoundation* foundation;
	physx::PxPhysics* physics;
	physx::PxPvd* pvd;
	physx::PxDefaultCpuDispatcher* dispatcher;
	physx::PxScene* scene;
};

class Scene {
	friend class Object;
	friend class System;
public:
	static SpPtr<Scene> get() { return *safeInstance; }
	Scene(pxData physxData, std::string& display_text);
	virtual ~Scene();

	Camera* cam;

	SpPtr<System> getSystem(std::string id);
	std::vector<SpPtr<Object>>* getObjects();

	void update(double t);
	void keyPressed(unsigned char key);
	void commit();

	bool isClosing() const { return closing; }
	std::string& display_text;

	physx::PxPhysics* getPhysics() const { return physxData.physics; }
	void addActor(physx::PxActor& actor) { return physxData.scene->addActor(actor); }
protected:
	std::vector<SpPtr<Object>> objects, objToAdd;
	std::unordered_map<std::string, SpPtr<System>> systems;
	std::vector<std::pair<std::string, SpPtr<System>>> sysToAdd;
private:
	void addObject(Object*);
	void addSystem(System*, std::string id);

	static Scene* instance;
	static SpPtr<Scene>* safeInstance;

	bool closing;
	pxData physxData;
};