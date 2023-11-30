#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"
#include "Systems/ForceSystem.h"

#include "Objects/AxisSphere.h"
#include "Objects/Keys.h"
#include "Objects/Shooter.h"

#include "Objects/ParticleGenerators/GaussianPartGen.h"
#include "Objects/ParticleGenerators/UniformPartGen.h"
#include "Objects/ParticleGenerators/BasicFireworkGen.h"
#include "Objects/Fireworks.h"

#include "Objects/ForceGenerators/GravityForce.h"
#include "Objects/ForceGenerators/WindForce.h"
#include "Objects/ForceGenerators/WhirlwindForce.h"
#include "Objects/ParticleGenerators/GaussianScriptGen.h"
#include "Objects/ForceEffectSphere.h"
#include "Objects/ForceGenerators/ExplosionForce.h"

#include "Objects/ForceGenerators/SpringForce.h"
#include "Objects/Box.h"
#include "Objects/ForceGenerators/FlotationForce.h"
#include "Objects/MovingBox.h"

#include "Utilities/ChangeText.h"
#include "Utilities/SpPtr.h"

static std::unordered_map<char, Object*>* keyObjects;

void createScene() {
	auto particle = new ParticleSystem();
	auto force = new ForceSystem();

	particle->getOtherSystems();

	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));

	new Shooter();
	
	//new GaussianPartGen(Vector3(0), 0.1, Vector3(5));
	//new UniformPartGen(Vector3(0), 0.1);
	//new BasicFireworkGen<Firework4>(Vector3(0), 1.5, Vector3(5, 25, 5), 2, -1, Vector3(0, 70, 0));

	auto gravity = new GravityForce(Vector3(0, -100, 0));
	//particle->addParticle(part, 10, true);
	//auto eff = new ForceEffectSphere(gen);

	auto wind = new WindForce(Vector3(10, 0, 0));
	auto whirlwind = new WhirlwindForce();
	//force->addConnection(part, gen);
	//auto eff = new ForceEffectSphere(gen);

	//SpringForce* gen = new SpringForce(2, 20);
	//auto part = new Particle(Vector3(10, 0, 0), Vector3(0, 0, 0));
	//gen->addMovingObject(part);
	//part = new Particle();
	//gen->addMovingObject(part);
	//Box* box = new Box();
	//gen->addObject(box);

	//gen = new SpringForce(2, 20);
	//gen->addMovingObject(part);
	//part = new Particle(Vector3(-10, 0, 0), Vector3(0, -20, 0));
	//gen->addMovingObject(part);
	

	//auto partGen = new GaussianScriptGen(Vector3(0, 0, 0), 0.02, Vector3(5), Vector3(0, 0, 0), 10);
	/*
	static int i = 0;
	partGen->addCallback([force, gen, partGen](Particle* p) -> void {
		//force->addConnection(p, gen);
		gen->addMovingObject(p);

		if(++i == 1) partGen->alive = false;
	});
	//*/

	//gen = new GravityForce(Vector3(0, 10, 0));
	//part = new Particle(Vector3(1, 0, 0), Vector3(0, -20, 0));
	//force->addConnection(part, gen);

	/* Slinky
	const int k = 100, restingLength = 20;
	SpringForce* gen = new SpringForce(k, restingLength);
	Box* box = new Box();
	gen->addObject(box);
	Particle* part;
	const int particleNum = 5, particleDistance = 20;
	for(int i = 1; i < particleNum; i++) {
		part = new Particle(Vector3(0, particleDistance * i, 0), Vector3(0, 0, 0));
		gen->addMovingObject(part);
		gen = new SpringForce(k, restingLength);
		gen->addMovingObject(part);
	}
	part = new Particle(Vector3(0, particleDistance * particleNum, 0), Vector3(0, 0, 0));
	gen->addMovingObject(part);
	//*/

	//* Agua (Flotacion)
	const Vector3 waterPos = Vector3(0);
	Box* waterPlane = new Box(waterPos, Vector3(1000, 0.5, 1000));
	// Estás loco si le pones a 1000 la densidad del agua
	FlotationForce* floater = new FlotationForce(waterPos, 10);
	MovingBox* waterFloating = new MovingBox(Vector3(0, 10, 0), Vector3(3), Vector3(0), Vector3(0), 0.5f, 1000);
	//*/

	auto keys = new Keys();
	keyObjects = new std::unordered_map<char, Object*>();
	keys->add('E', [](){ // nice
		new ExplosionForce();
	});
#define FORCE_KEY(key, force, pos, radius) \
static bool force##Switch = false; \
keys->add(key, [force](){ \
	if(force##Switch) { \
		keyObjects->at(key)->alive = false; \
		keyObjects->erase(key); \
	} else { \
		auto sphere = new ForceEffectSphere(force, pos, radius); \
		keyObjects->insert({ key, sphere }); \
	} \
	force##Switch = !force##Switch; \
})
	FORCE_KEY('V', wind, Vector3(0), 100);
	FORCE_KEY('T', whirlwind, Vector3(0), 100);
	FORCE_KEY('G', gravity, Vector3(0), 100000);
	FORCE_KEY('F', floater, Vector3(0), 1000);

	keys->add('I', [waterFloating]() {
		waterFloating->updateMass(-0.5);
	});
	keys->add('O', [waterFloating]() {
		waterFloating->updateMass(0.5);
	});
	keys->add('K', [waterFloating]() {
		waterFloating->updateBaseArea(-0.5);
	});
	keys->add('L', [waterFloating]() {
		waterFloating->updateBaseArea(0.5);
	});

	new ChangeText(display_text, windSwitch, whirlwindSwitch, gravitySwitch);
}

void deleteScene() {
	delete keyObjects;
}