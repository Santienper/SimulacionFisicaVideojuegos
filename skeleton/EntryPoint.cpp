#include "Structure/Scene.h"

#include "Objects/AxisSphere.h"
#include "Objects/Shooter.h"

void createScene() {
	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));
	
	Scene::get()->shoot = new Shooter();
}