#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"

#include "Objects/AxisSphere.h"
#include "Objects/ParticleGenerators/GaussianPartGen.h"
#include "Objects/ParticleGenerators/UniformPartGen.h"
#include "Objects/ParticleGenerators/BasicFireworkGen.h"
#include "Objects/Fireworks.h"

void createScene() {
	new ParticleSystem();

	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));
	
	new GaussianPartGen(Vector3(0), 0.1, 5);
	//new UniformPartGen(Vector3(0), 0.1);
	new BasicFireworkGen<Firework4>(Vector3(0), 1.5, 5, 2, -1, Vector3(0, 70, 0), Vector3(1, 5, 1));
}