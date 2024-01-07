#pragma once
#include "Core/RenderUtils.hpp"
#include <unordered_map>
#include "Utilities/SpPtr.h"
#include <concepts>

void createScene();
void deleteScene();

struct pxData {
	physx::PxFoundation* foundation;
	physx::PxPhysics* physics;
	physx::PxPvd* pvd;
	physx::PxDefaultCpuDispatcher* dispatcher;
	physx::PxScene* scene;
};

class Object; // compatibilidad con c++20
class System; // compatibilidad con c++20

class Scene {
	friend class Object;
	friend class System;
public:
	static SpPtr<Scene> get() { return *safeInstance; }
	Scene(pxData physxData, std::string& display_text);
	virtual ~Scene();

	Camera* cam;

	template<typename Sys>
	//requires std::derived_from<Sys, System> // <- para usar esto se necesita tener la versión c++20, la cual no se puede usar
	                                          //    porque physx usa la palabra clave "requires" como nombre de método en varios lados
	SpPtr<Sys> getSystem() {
		return getSystem(Sys::getStaticID()).cast<Sys>();
	}
	std::vector<SpPtr<Object>>* getObjects();

	void update(double t);
	void keyPressed(unsigned char key);
	void mousePressed(int button, int state, int x, int y);
	void mouseMoved(int x, int y);
	void commit();

	bool isClosing() const noexcept { return closing; }
	std::string& display_text;

	physx::PxPhysics* getPhysics() const { return physxData.physics; }
	void addActor(physx::PxActor& actor) { return physxData.scene->addActor(actor); }
protected:
	std::vector<SpPtr<Object>> objects, objToAdd;
	std::unordered_map<std::string, SpPtr<System>> systems;
	std::vector<std::pair<std::string, SpPtr<System>>> sysToAdd;
	std::vector<Object*> keySubs, mouseMoveSubs, mousePressSubs;
private:
	void addObject(Object*);
	void addSystem(System*, const std::string& id);

	void subKey(Object*, bool add);
	void subMousePress(Object*, bool add);
	void subMouseMove(Object*, bool add);

	SpPtr<System> getSystem(const std::string& id);

	static Scene* instance;
	static SpPtr<Scene>* safeInstance;

	bool closing;
	pxData physxData;
};