#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"
#include "Systems/ForceSystem.h"

#include "Objects/AxisSphere.h"

#include "Objects/ParticleGenerators/GaussianPartGen.h"
#include "Objects/ParticleGenerators/UniformPartGen.h"
#include "Objects/ParticleGenerators/BasicFireworkGen.h"
#include "Objects/Fireworks.h"

#include "Objects/ForceGenerators/GravityForce.h"
#include "Objects/ForceGenerators/WindForce.h"
#include "Objects/ForceGenerators/WhirlwindForce.h"
#include "Objects/ParticleGenerators/GaussianScriptGen.h"

#include "Utilities/SpPtr.h"

void createScene() {
	auto particle = new ParticleSystem();
	auto force = new ForceSystem();

	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));
	
	//new GaussianPartGen(Vector3(0), 0.1, 5);
	//new UniformPartGen(Vector3(0), 0.1);
	//new BasicFireworkGen<Firework4>(Vector3(0), 1.5, 5, 2, -1, Vector3(0, 70, 0), Vector3(1, 5, 1));

	ForceGenerator* gen = new GravityForce(Vector3(0, -10, 0));
	auto part = new Particle(Vector3(10, 0, 0), Vector3(0, 20, 0));
	force->addConnection(part, gen);
	particle->addParticle(part, 10, true);

	//gen = new WindForce(Vector3(10, 0, 0));
	gen = new WhirlwindForce();
	force->addConnection(part, gen);

	auto partGen = new GaussianScriptGen(Vector3(0), 0.01, 5);
	partGen->setCallback([force, gen](Particle* p)-> void {
		force->addConnection(p, gen);
	});

	//gen = new GravityForce(Vector3(0, 10, 0));
	//part = new Particle(Vector3(1, 0, 0), Vector3(0, -20, 0));
	//force->addConnection(part, gen);

	
}