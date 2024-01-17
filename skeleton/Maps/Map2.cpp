#include "Map2.h"
#include "Objects/Player.h"
#include "Objects/RSObject.h"
#include "Objects/Target.h"
#include "Objects/Fader.h"

#include "Objects/ForceGenerators/GravityForce.h"
#include "Objects/ForceGenerators/WindForce.h"
#include "Objects/ForceEffectBox.h"

#include "Objects/ParticleGenerators/GaussianPartGen.h"

Map2::Map2() {

}

void Map2::createMap() {
	physx::PxBoxGeometry geo(Vector3(10, 10, 10));
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 1 }, false);

	constexpr float wallThickness = 1.0f;
	constexpr float distance = 15.0f;
	constexpr float colorBrightness = 0.75f;

	auto pl = new Player({ distance * 3, distance * -3, 0 }, { 0, 15, 0 }, 0.15f);

	auto grav = new GravityForce({ 0, -98.0f, 0 });
	new ForceEffectBox(grav, { 0, 0, 0 }, { distance * 3.5f, distance * 3.5f, distance * 3.5f });
	auto wind = new WindForce({ 20, 0, 0 }, 1);
	new ForceEffectBox(wind, { 0, 0, 0 }, { distance * 3.5f, distance * 3.5f, distance * 3.5f });

	geo = Vector3(wallThickness, distance * 3.5f, distance * 3.5f);
	//new RSObject({ 0, 0, 0 }, &geo, { 1, 0, 0, 1 });
	new RSObject({ distance * -3.5f, 0, 0 }, &geo, { 0, colorBrightness, 0, 1 });
	new RSObject({ distance * 3.5f, 0, 0 }, &geo, { 0, colorBrightness, 0, 1 });

	geo = Vector3(distance * 3.5f, distance * 3.5f, wallThickness);
	new RSObject({ 0, 0, distance * -3.5f }, &geo, { 0, 0, colorBrightness, 1 });
	new RSObject({ 0, 0, distance * 3.5f }, &geo, { 0, 0, colorBrightness, 1 });

	geo = Vector3(distance * 3.5f, wallThickness, distance * 3.5f);
	new RSObject({ 0, distance * -3.5f, 0 }, &geo, { colorBrightness, 0, 0, 1 });
	new RSObject({ 0, distance * 3.5f, 0 }, &geo, { colorBrightness, 0, 0, 1 });

	geo = Vector3(wallThickness, distance / 2, distance / 2);
	Vector4 color = { 0, colorBrightness, 0, 1 };
	//new RSObject({ -distance * 0.5f, 0, 0 }, &geo, color);
	new RSObject({ distance * 2.5f, distance * -3, distance * 2 }, &geo, color);
	new RSObject({ distance * 2.5f, distance * -3, distance }, &geo, color);
	new RSObject({ distance * 2.5f, distance * -3, 0 }, &geo, color);
	new RSObject({ distance * 2.5f, distance * -3, -distance }, &geo, color);

	new RSObject({ distance * 0.5f, distance * -2, distance * 2 }, &geo, color);

	new RSObject({ distance * -2.5f, distance * -3, distance * -3 }, &geo, color);
	new RSObject({ distance * -2.5f, distance * -2, distance * -3 }, &geo, color);
	new RSObject({ distance * -2.5f, distance * -1, distance * -3 }, &geo, color);
	new RSObject({ distance * -2.5f, distance *  0, distance * -3 }, &geo, color);
	new RSObject({ distance * -2.5f, distance *  1, distance * -3 }, &geo, color);
	new RSObject({ distance * -2.5f, distance *  2, distance * -3 }, &geo, color);
	new RSObject({ distance * -2.5f, distance *  3, distance * -3 }, &geo, color);

	new Target({ distance * -3, 0, distance * -3 });

	new GaussianPartGen({ distance * -3, distance * 3.5f, distance * -2 }, 0.01f, { 5, 0, 5 }, { 0, 0, 0 });

	geo = Vector3(distance / 2, wallThickness, distance / 2);
	color = { colorBrightness, 0, 0, 1 };
	new RSObject({ distance * 3, distance * 2.5f, distance * 0 }, &geo, color);
	
	geo = Vector3(distance  / 2, distance / 2, wallThickness);
	color = { 0, 0, colorBrightness, 1 };
	new RSObject({ distance * 3, distance * 3, distance * -0.5f }, &geo, color);
	new RSObject({ distance * 3, distance * 3, distance * 0.5f }, &geo, color);

	new Target({ distance * 3, distance * 3, 0 });

	new Target({ distance * -3, distance * -1, distance * 3 });
}

void Map2::deleteMap() {

}

void Map2::clearedTargets() {
	physx::PxBoxGeometry geo(Vector3(10, 10, 10));
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 0 }, true, [this]() -> void {
		scene->nextMap();
	});
}
