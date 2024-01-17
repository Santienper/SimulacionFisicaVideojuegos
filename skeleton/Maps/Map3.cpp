#include "Map3.h"
#include "Objects/Player.h"
#include "Objects/RSObject.h"
#include "Objects/Target.h"
#include "Objects/Fader.h"

#include "Objects/ForceGenerators/SpringForce.h"
#include "Objects/Particle.h"
#include "Objects/RDGen.h"

Map3::Map3() {

}

void Map3::createMap() {
	physx::PxBoxGeometry geo(Vector3(10, 10, 10));
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 1 }, false);

	constexpr float wallThickness = 1.0f;
	constexpr float distance = 15.0f;
	constexpr float colorBrightness = 0.75f;

	auto pl = new Player({ distance * 3, distance * -3, 0 }, { 0, 15, 0 }, 0.15f);

	geo = Vector3(wallThickness, distance * 3.5f, distance * 3.5f);
	//new RSObject({ 0, 0, 0 }, &geo, { 1, 0, 0, 1 });
	new RSObject({ distance * -3.5f, 0, 0 }, &geo, { 0, colorBrightness, 0, 1 });
	new RSObject({ distance * 3.5f, 0, 0 }, &geo, { 0, colorBrightness, 0, 1 });

	geo = Vector3(distance * 3.5f, distance * 3.5f, wallThickness);
	new RSObject({ 0, 0, distance * -3.5f }, &geo, { colorBrightness, 0, 0, 1 });
	new RSObject({ 0, 0, distance * 3.5f }, &geo, { colorBrightness, 0, 0, 1 });

	geo = Vector3(distance * 3.5f, wallThickness, distance * 3.5f);
	new RSObject({ 0, distance * -3.5f, 0 }, &geo, { 0, 0, colorBrightness, 1 });
	new RSObject({ 0, distance * 3.5f, 0 }, &geo, { 0, 0, colorBrightness, 1 });

	geo = Vector3(wallThickness, distance / 2, distance / 2);
	Vector4 color = { 0, colorBrightness, 0, 1 };
	//new RSObject({ -distance * 0.5f, 0, 0 }, &geo, color);
	new RSObject({ distance * -2.5f, distance * -3, distance * 3 }, &geo, color);
	new RSObject({ distance * -1.5f, distance * -3, distance * 3 }, &geo, color);

	geo = Vector3(distance / 2, wallThickness, distance / 2);
	color = { 0, 0, colorBrightness, 1 };
	new RSObject({ distance * -3, distance * -2.5f, distance * 2 }, &geo, color);
	new RSObject({ distance * -3, distance * -2.5f, distance * 3 }, &geo, color);
	new RSObject({ distance * -2, distance * -2.5f, distance * 3 }, &geo, color);

	geo = Vector3(distance / 2, distance / 2, wallThickness);
	color = { colorBrightness, 0, 0, 1 };
	new RSObject({ distance * -3, distance * -3, distance * 1.5f }, &geo, color);
	new RSObject({ distance * -3, distance * -3, distance * 2.5f }, &geo, color);

	geo = Vector3(distance / 3, distance / 3, distance / 3);
	auto springHead = new Particle({ distance * -3, distance * -3, distance * 2 }, Vector3(0), Vector3(0), distance/3, 0.8f, 0.15f);
	auto springBack = new Object({ distance * -3.5f, distance * -3, distance * 2 });
	auto spring = new SpringForce(1, distance * 1.5f);
	spring->addPhysicsObject(springHead);
	spring->addObject(springBack);

	new Target({ distance * -3.5f, distance * -3, distance * 2 });

	physx::PxGeometry* geo1 = new physx::PxSphereGeometry(3), * geo2 = new physx::PxBoxGeometry(Vector3(3)), * geo3 = new physx::PxCapsuleGeometry(1, 1);
	RDGen::RDVisuals* vis1 = new RDGen::RDVisuals(geo1, Vector4(0.8f, 0.094f, 0.031f, 1)), * vis2 = new RDGen::RDVisuals(geo2, Vector4(1, 0.5, 1, 1)), * vis3 = new RDGen::RDVisuals(geo3, Vector4(0.239f, 0.722f, 0.671f, 1));
	//                       pos              , visuals             , rate, rndVel           , startVel  , maxTime
	RDGen* rdGen = new RDGen(Vector3(distance * 3, 0, 0), { vis1, vis2, vis3 }, 0.25f, Vector3(10, 0, 10), Vector3(0), 5);
}

void Map3::deleteMap() {

}

void Map3::clearedTargets() {
	physx::PxBoxGeometry geo(Vector3(10, 10, 10));
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 0 }, true, [this]() -> void {
		scene->nextMap();
	});
}
