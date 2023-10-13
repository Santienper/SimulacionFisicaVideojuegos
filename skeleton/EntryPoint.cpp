#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"

#include "Objects/AxisSphere.h"
#include "Objects/GaussianPartGen.h"
#include "Objects/UniformPartGen.h"
#include "Objects/FireworkGen.h"
#include "Objects/Fireworks.h"

void createScene() {
	new ParticleSystem();

	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));
	
	//new GaussianPartGen(Vector3(0), 0.1, 5);
	//new UniformPartGen(Vector3(0), 0.1);
	new FireworkGen<Firework3>(Vector3(0), 1.5, 5, -1, Vector3(0, 30, 0), Vector3(1, 1, 1));
}