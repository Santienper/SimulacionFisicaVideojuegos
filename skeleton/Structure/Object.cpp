#include "Object.h"
#include "Scene.h"

Object::Object(const Vector3& pos) : trans(pos), render(nullptr), alive(true), scene(nullptr), subbedKey(false), subbedMousePress(false), subbedMouseMove(false), subbedResetRender(false) {
	scene = Scene::get();
	scene->addObject(this);
}

Object::~Object() {
	if(render != nullptr) render->release();
	subKey(false);
	subMouseMove(false);
	subMousePress(false);
	subRenderReset(false);
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

void Object::subRenderReset(bool add) {
	if(subbedResetRender != add) {
		scene->subResetRender(this, add);
	}
}
