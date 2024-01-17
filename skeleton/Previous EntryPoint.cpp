#include "Structure/Scene.h"

#include "Systems/ParticleSystem.h"
#include "Systems/ForceSystem.h"
#include "Systems/RDSystem.h"

#include "Objects/Not important/AxisSphere.h"
#include "Objects/Not important/Keys.h"
#include "Objects/Not important/Shooter.h"

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
#include "Objects/Not important/Box.h"
#include "Objects/ForceGenerators/FlotationForce.h"
#include "Objects/Not important/MovingBox.h"

#include "Objects/RSObject.h"
#include "Objects/RDObject.h"
#include "Objects/RDGen.h"

#include "Utilities/ChangeText.h"
#include "Utilities/SpPtr.h"

static std::unordered_map<char, Object*>* keyObjects;

void createDebugScene() {
	auto particle = new ParticleSystem();
	auto force = new ForceSystem();
	auto rigidSystem = new RDSystem();

	particle->getOtherSystems();

	//new AxisSphere(Vector3(10, 0, 0), Vector4(1, 0, 0, 1));
	//new AxisSphere(Vector3(0, 10, 0), Vector4(0, 1, 0, 1));
	//new AxisSphere(Vector3(0, 0, 10), Vector4(0, 0, 1, 1));

	new Shooter(); // Usar la tecla 'Espacio' para "disparar" una partícula
	
	//new GaussianPartGen(Vector3(0), 0.1, Vector3(5));
	//new UniformPartGen(Vector3(0), 0.1);
	//new BasicFireworkGen<Firework4>(Vector3(0), 1.5, Vector3(5, 25, 5), 2, -1, Vector3(0, 70, 0));

	//auto gravity = new GravityForce(Vector3(0, -100, 0)); // Aceleración que genera la gravedad
	//particle->addParticle(part, 10, true);

	auto wind = new WindForce(Vector3(10, 0, 0));
	//auto whirlwind = new WhirlwindForce();

	// ¡¡¡IMPORTANTE!!!
	// En estos bloques de código comentados solo hace falta cambiar los carácteres '/*' a '//*' para descomentar el bloque de código
	// Se recomienda tener sólo un bloque de código descomentado (para descomentar solo hace falta cambiar los carácteres a como estaban antes ('/*'))

	/* Primeros objetos de PhysX (Práctica 5)
	physx::PxBoxGeometry a; a.halfExtents = Vector3(3); // Vector3(10, 3, 10);
	RSObject* objjj = new RSObject(&a);
	a.halfExtents = Vector3(3);
	RDObject* souith = new RDObject(Vector3(0, 10, 0), &a);
	//*/
	
	/* Generador de objetos de PhysX
	physx::PxGeometry *geo1 = new physx::PxSphereGeometry(3), *geo2 = new physx::PxBoxGeometry(Vector3(3)), *geo3 = new physx::PxCapsuleGeometry(1, 1);
	RDGen::RDVisuals *vis1 = new RDGen::RDVisuals(geo1, Vector4(0.8f, 0.094f, 0.031f, 1)), *vis2 = new RDGen::RDVisuals(geo2, Vector4(1, 0.5, 1, 1)), *vis3 = new RDGen::RDVisuals(geo3, Vector4(0.239f, 0.722f, 0.671f, 1));
	//                       pos              , visuals             , rate, rndVel           , startVel  , maxTime
	RDGen* rdGen = new RDGen(Vector3(0, 20, 0), { vis1, vis2, vis3 }, 0.5, Vector3(10, 0, 10), Vector3(0), 5);
	//*/

	/* Primer muelle Práctica 4
	auto part = new Particle(Vector3(10, 0, 0), Vector3(0, 0, 0));
	SpringForce* gen = new SpringForce(2, 20);
	gen->addPhysicsObject(part);
	//part = new Particle();
	//gen->addPhysicsObject(part);
	Box* box = new Box();
	gen->addObject(box);
	//*/

	/* 2 partículas yendo hacia abajo (Práctica 4)
	auto part = new Particle(Vector3(20, 0, 0), Vector3(0, 0, 0));
	auto gen = new SpringForce(2, 20);
	gen->addPhysicsObject(part);
	part = new Particle(Vector3(-10, 0, 0), Vector3(0, -20, 0)); // Primer parámetro: posición, Segundo parámetro: velocidad
	gen->addPhysicsObject(part);
	//*/

	/* Slinky (Práctica 4)
	const int k = 100, restingLength = 20;
	SpringForce* gen = new SpringForce(k, restingLength);
	Box* box = new Box();
	gen->addObject(box);
	Particle* part;
	const int particleNum = 5, particleDistance = 20;
	for(int i = 1; i < particleNum; i++) {
		part = new Particle(Vector3(0, particleDistance * i, 0), Vector3(0, 0, 0));
		gen->addPhysicsObject(part);
		gen = new SpringForce(k, restingLength);
		gen->addPhysicsObject(part);
	}
	part = new Particle(Vector3(0, particleDistance * particleNum, 0), Vector3(0, 0, 0));
	gen->addPhysicsObject(part);
	//*/

	// Para la flotación hace falta descomentar otro trozo de código donde se asignan las teclas
	// Para activar la flotación hay que pulsar la 'f'
	/* Agua (Flotacion) (Práctica 4)
	const Vector3 waterPos = Vector3(0);
	Box* waterPlane = new Box(waterPos, Vector3(1000, 0.5, 1000), Vector4(0, 0.3, 0.5, 0.7));
	FlotationForce* floater = new FlotationForce(waterPos, 1000);
	MovingBox* waterFloatingBox = new MovingBox(Vector3(0, 10, 0), Vector3(3), Vector3(0), Vector3(0), 0.5f, 10000);
	//*/



	// ¡Teclas! :D
	auto keys = new Keys();
	keyObjects = new std::unordered_map<char, Object*>();
	//keys->add('E', [](){ // nice
	//	new ExplosionForce();
	//});
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
	//FORCE_KEY('T', whirlwind, Vector3(0), 100);
	//FORCE_KEY('G', gravity, Vector3(0), 100000);
	/* Agüis (Práctica 4 - Flotación)
	FORCE_KEY('F', floater, Vector3(0), 1000);

	keys->add('I', [waterFloatingBox]() {
		waterFloatingBox->updateMass(-100);
	});
	keys->add('O', [waterFloatingBox]() {
		waterFloatingBox->updateMass(100);
	});
	keys->add('K', [waterFloatingBox]() {
		waterFloatingBox->updateBaseArea(-0.5);
	});
	keys->add('L', [waterFloatingBox]() {
		waterFloatingBox->updateBaseArea(0.5);
	});//*/

	//new ChangeText(display_text, windSwitch, whirlwindSwitch, gravitySwitch);
#undef FORCE_KEY
}

void deleteDebugScene() {
	delete keyObjects;
}