#include "Object.h"
#include "Scene.h"

Object::Object(Vector3 pos) : trans(pos), render(nullptr), alive(true) {
	Scene::get()->addObject(this);
}

Object::~Object() {
	if(render != nullptr) render->release();
}
