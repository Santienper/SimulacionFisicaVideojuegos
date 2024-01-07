#include "Object.h"
#include "Scene.h"

Object::Object(const Vector3& pos) : trans(pos), render(nullptr), alive(true), scene(nullptr), subbedKey(false), subbedMousePress(false), subbedMouseMove(false) {
	scene = Scene::get();
	scene->addObject(this);
}

Object::~Object() {
	if(render != nullptr) render->release();
	subKey(false);
	subMouseMove(false);
	subMousePress(false);
}

void Object::subKey(bool add) {
	if(subbedKey != add) {
		scene->subKey(this, add);
	}
}

void Object::subMousePress(bool add) {
	if(subbedMousePress != add) {
		scene->subMousePress(this, add);
	}
}

void Object::subMouseMove(bool add) {
	if(subbedMouseMove != add) {
		scene->subMouseMove(this, add);
	}
}
