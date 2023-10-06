#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"

#include "Objects/AxisSphere.h"
#include "Objects/GaussianPartGen.h"

void createScene() {
	new ParticleSystem();

	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));
	
	new GaussianPartGen(Vector3(0));
}