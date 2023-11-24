#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"
#include "Systems/ForceSystem.h"

#include "Objects/AxisSphere.h"
#include "Objects/Keys.h"

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

#include "Utilities/SpPtr.h"

void createScene() {
	auto particle = new ParticleSystem();
	auto force = new ForceSystem();

	particle->getOtherSystems();

	new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));
	
	//new GaussianPartGen(Vector3(0), 0.1, Vector3(5));
	//new UniformPartGen(Vector3(0), 0.1);
	//new BasicFireworkGen<Firework4>(Vector3(0), 1.5, Vector3(5, 25, 5), 2, -1, Vector3(0, 70, 0));

	//ForceGenerator* gen = new GravityForce(Vector3(0, -10, 0));
	//particle->addParticle(part, 10, true);
	//auto eff = new ForceEffectSphere(gen);

	auto wind = new WindForce(Vector3(10, 0, 0));
	auto whirlwind = new WhirlwindForce();
	//force->addConnection(part, gen);
	//auto eff = new ForceEffectSphere(gen);

	SpringForce* gen = new SpringForce(2, 20);
	auto part = new Particle(Vector3(10, 0, 0), Vector3(0, 20, 0));
	gen->addParticle(part);
	//part = new Particle();
	//gen->addParticle(part);
	Box* box = new Box();
	gen->addObject(box);
	

	auto partGen = new GaussianScriptGen(Vector3(0, 0, 0), 0.02, Vector3(5), Vector3(0, 0, 0), 10);
	//*
	static int i = 0;
	partGen->addCallback([force, gen, partGen](Particle* p) -> void {
		//force->addConnection(p, gen);
		gen->addParticle(p);

		if(++i == 1) partGen->alive = false;
	});
	//*/

	//gen = new GravityForce(Vector3(0, 10, 0));
	//part = new Particle(Vector3(1, 0, 0), Vector3(0, -20, 0));
	//force->addConnection(part, gen);

	auto keys = new Keys();
	static auto areas = new std::unordered_map<char, ForceEffectSphere*>();
	keys->add('E', [](){ // nice
		new ExplosionForce();
	});
	static bool windSwitch = false;
	keys->add('V', [wind](){
		if(windSwitch) {
			areas->erase('V');
		} else {
			const Vector3 pos = Vector3(0);
			const float radius = 2;
			auto sphere = new ForceEffectSphere(wind, pos, radius);
			areas->insert({ 'V', sphere });
		}
		windSwitch = !windSwitch;
	});
	static bool whirlwindSwitch = false;
	keys->add('T', [whirlwind](){
		if(whirlwindSwitch) {
			areas->erase('T');
		} else {
			const Vector3 pos = Vector3(0);
			const float radius = 2;
			auto sphere = new ForceEffectSphere(whirlwind, pos, radius);
			areas->insert({ 'V', sphere });
		}
	});
}