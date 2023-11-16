#include "Trigger.h"
#include "Structure/Scene.h"

Trigger::Trigger(const Vector3& pos) : Object(pos) {
	callbackEnter = callbackLoop = callbackExit = [](const Object*)->void{ };
	sceneObjects = Scene::get()->getObjects();
	SpPtr<Object> aa;
}

Trigger::~Trigger() {
	for(auto obj : objects) {
		if(obj != nullptr) {
			callbackExit(obj.get());
		}
	}
}

void Trigger::update(double t) {
	for(auto& obj : *sceneObjects) {
		Object* object = obj.get();
		if(isInside(object)) {
			if(objects.find(obj) != objects.end()) {
				callbackLoop(object);
			} else {
				callbackEnter(object);
				objects.insert(obj);
			}
		} else {
			if(objects.find(obj) != objects.end()) {
				callbackExit(object);
				objects.erase(obj);
			}
		}
	}
}

void Trigger::setCallbackEnter(const std::function<void(Object*)>& callback) {
	callbackEnter = callback;
}

void Trigger::setCallbackLoop(const std::function<void(Object*)>& callback) {
	callbackLoop = callback;
}

void Trigger::setCallbackExit(const std::function<void(Object*)>& callback) {
	callbackExit = callback;
}

PublicTrigger::PublicTrigger(const Vector3& pos) : Trigger(pos) {
	
}

void PublicTrigger::setCallbackEnter(const std::function<void(Object*)>& callback) {
	Trigger::setCallbackEnter(callback);
}

void PublicTrigger::setCallbackLoop(const std::function<void(Object*)>& callback) {
	Trigger::setCallbackLoop(callback);
}

void PublicTrigger::setCallbackExit(const std::function<void(Object*)>& callback) {
	Trigger::setCallbackExit(callback);
}
