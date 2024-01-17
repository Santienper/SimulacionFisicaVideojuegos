#pragma once
#include "Core/RenderUtils.hpp"
#include <unordered_map>
#include "Utilities/SpPtr.h"
//#include <concepts> <-- para version c++20

class Map;

std::vector<Map*> createMaps();

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

	void init();
	void update(double t);
	void keyPressed(unsigned char key);
	void keyReleased(unsigned char key);
	void specialKeyPressed(int key);
	void specialKeyReleased(int key);
	void mousePressed(int button, int state, int x, int y);
	void mouseMoved(int x, int y);
	void commit();
	void resetRender();
	void nextMap();
	void loadMap(int mapIndex);
	Map* getCurrentMap() const { return maps[currentMap]; };

	bool isClosing() const noexcept { return closing; }
	std::string& display_text;

	physx::PxPhysics* getPhysics() const { return physxData.physics; }
	void addActor(physx::PxActor& actor) { return physxData.scene->addActor(actor); }
	void removeActor(physx::PxActor& actor) { return physxData.scene->removeActor(actor); }
protected:
	std::vector<SpPtr<Object>> objects, objToAdd;
	std::unordered_map<std::string, SpPtr<System>> systems;
	std::vector<std::pair<std::string, SpPtr<System>>> sysToAdd;
	std::vector<Object*> keyPressSubs, keyReleaseSubs, mouseMoveSubs, mousePressSubs, resetRenderSubs;
private:
	void addObject(Object*);
	void addSystem(System*, const std::string& id);

	void subKeyPress(Object*, bool add);
	void subKeyRelease(Object*, bool add);
	void subMousePress(Object*, bool add);
	void subMouseMove(Object*, bool add);
	void subResetRender(Object*, bool add);

	SpPtr<System> getSystem(const std::string& id);

	static Scene* instance;
	static SpPtr<Scene>* safeInstance;

	bool closing;
	pxData physxData;

	std::vector<Map*> maps;
	int currentMap;
};