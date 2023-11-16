#include "Trigger.h"
#include "Structure/Scene.h"

Trigger::Trigger(const Vector3& pos, physx::PxGeometryHolder area) : Object(pos), area(area) {
	callbackEnter = callbackLoop = callbackExit = [](const Object*)->void{ };
}

void Trigger::update(double t) {
	// Recoger objetos
	const std::vector<SpPtr<Object>>* sceneObjects = Scene::get()->getObjects();

	auto it = sceneObjects->cbegin();
	while(it != sceneObjects->cend()) {
		const Object* object = it.operator*().operator->();
		if(isInside(object)) {
			if(objects.find(object) != objects.end()) {
				callbackLoop(object);
			} else {
				callbackEnter(object);
				objects.insert(object);
			}
		} else {
			if(objects.find(object) != objects.end()) {
				callbackExit(object);
				objects.erase(object);
			}
		}
		++it;
	}
}

void Trigger::setCallbackEnter(const std::function<void(const Object*)>& callback) {
	callbackEnter = callback;
}

void Trigger::setCallbackLoop(const std::function<void(const Object*)>& callback) {
	callbackLoop = callback;
}

void Trigger::setCallbackExit(const std::function<void(const Object*)>& callback) {
	callbackExit = callback;
}
