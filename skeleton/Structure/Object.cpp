#include "Object.h"
#include "Scene.h"

Object::Object(const Vector3& pos) : trans(pos), render(nullptr), alive(true), scene(nullptr),
	subbedKeyPress(false), subbedKeyRelease(false), subbedMousePress(false), subbedMouseMove(false), subbedResetRender(false) {

	scene = Scene::get();
	scene->addObject(this);
}

Object::~Object() {
	if(render != nullptr) render->release();
	subKeyPress(false);
	subKeyRelease(false);
	subMouseMove(false);
	subMousePress(false);
	subRenderReset(false);
}

bool Object::isType(const std::string& type) const {
	return std::find(types.cbegin(), types.cend(), type) != types.cend();
}

void Object::subKeyPress(bool add) {
	if(subbedKeyPress != add) {
		scene->subKeyPress(this, add);
		subbedKeyPress = add;
	}
}

void Object::subKeyRelease(bool add) {
	if(subbedKeyRelease != add) {
		scene->subKeyRelease(this, add);
		subbedKeyRelease = add;
	}
}

void Object::subMousePress(bool add) {
	if(subbedMousePress != add) {
		scene->subMousePress(this, add);
		subbedMousePress = add;
	}
}

void Object::subMouseMove(bool add) {
	if(subbedMouseMove != add) {
		scene->subMouseMove(this, add);
		subbedMouseMove = add;
	}
}

void Object::subRenderReset(bool add) {
	if(subbedResetRender != add) {
		scene->subResetRender(this, add);
		subbedResetRender = add;
	}
}

bool Object::addType(const std::string& type) {
	if(isType(type)) return false;
	types.push_back(type);
	return true;
}
