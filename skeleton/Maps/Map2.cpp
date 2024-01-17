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
	const Vector4 color1 = Vector4(0.1882f, 0.0353f, 0.8078f, 1);
	const Vector4 color2 = Vector4(0, 0.7608f, 0.5451f, 1);
	const Vector4 color3 = Vector4(0.8902f, 0.5843f, 0.9843f, 1);

	auto pl = new Player({ distance * 3, distance * -3, 0 }, { 0, 15, 0 }, 0.15f);

	auto grav = new GravityForce({ 0, -98.0f, 0 });
	new ForceEffectBox(grav, { 0, 0, 0 }, { distance * 3.5f, distance * 3.5f, distance * 3.5f });
	auto wind = new WindForce({ 20, 0, 0 }, 1);
	new ForceEffectBox(wind, { 0, 0, 0 }, { distance * 3.5f, distance * 3.5f, distance * 3.5f });

	geo = Vector3(wallThickness, distance * 3.5f, distance * 3.5f);
	//new RSObject({ 0, 0, 0 }, &geo, { 1, 0, 0, 1 });
	new RSObject({ distance * -3.5f, 0, 0 }, &geo, color2);
	new RSObject({ distance * 3.5f, 0, 0 }, &geo, color2);

	geo = Vector3(distance * 3.5f, distance * 3.5f, wallThickness);
	new RSObject({ 0, 0, distance * -3.5f }, &geo, color3);
	new RSObject({ 0, 0, distance * 3.5f }, &geo, color3);

	geo = Vector3(distance * 3.5f, wallThickness, distance * 3.5f);
	new RSObject({ 0, distance * -3.5f, 0 }, &geo, color1);
	new RSObject({ 0, distance * 3.5f, 0 }, &geo, color1);

	geo = Vector3(wallThickness, distance / 2, distance / 2);
	//new RSObject({ -distance * 0.5f, 0, 0 }, &geo, color);
	new RSObject({ distance * 2.5f, distance * -3, distance * 2 }, &geo, color2);
	new RSObject({ distance * 2.5f, distance * -3, distance }, &geo, color2);
	new RSObject({ distance * 2.5f, distance * -3, 0 }, &geo, color2);
	new RSObject({ distance * 2.5f, distance * -3, -distance }, &geo, color2);

	new RSObject({ distance * 0.5f, distance * -2, distance * 2 }, &geo, color2);

	new RSObject({ distance * -2.5f, distance * -3, distance * -3 }, &geo, color2);
	new RSObject({ distance * -2.5f, distance * -2, distance * -3 }, &geo, color2);
	new RSObject({ distance * -2.5f, distance * -1, distance * -3 }, &geo, color2);
	new RSObject({ distance * -2.5f, distance *  0, distance * -3 }, &geo, color2);
	new RSObject({ distance * -2.5f, distance *  1, distance * -3 }, &geo, color2);
	new RSObject({ distance * -2.5f, distance *  2, distance * -3 }, &geo, color2);
	new RSObject({ distance * -2.5f, distance *  3, distance * -3 }, &geo, color2);

	new Target({ distance * -3, 0, distance * -3 });

	new GaussianPartGen({ distance * -3, distance * 3.5f, distance * -2 }, 0.01f, { 5, 0, 5 }, { 0, 0, 0 });

	geo = Vector3(distance / 2, wallThickness, distance / 2);
	new RSObject({ distance * 3, distance * 2.5f, distance * 0 }, &geo, color1);
	
	geo = Vector3(distance  / 2, distance / 2, wallThickness);
	new RSObject({ distance * 3, distance * 3, distance * -0.5f }, &geo, color3);
	new RSObject({ distance * 3, distance * 3, distance * 0.5f }, &geo, color3);

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
