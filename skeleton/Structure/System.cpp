#include "System.h"
#include "Scene.h"

System::System(std::string id) : alive(true) {
	Scene::get()->addSystem(this, id);
}
