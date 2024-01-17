#include "Map1.h"
#include "Objects/Player.h"
#include "Objects/RSObject.h"
#include "Objects/Target.h"
#include "Objects/Fader.h"

Map1::Map1() {

}

void Map1::createMap() {
	constexpr float wallThickness = 0.2f;
	constexpr float distance = 15.0f;
	constexpr float wallHeight = 10.0f;
	
	auto pl = new Player({ 0, 0, 0 }, { 0, 100, 0 }, 0.15f);
	pl->restrict(true);

	scene->cam->changeDir(Vector3(0, -1, 0.00001f));

	auto geo = physx::PxBoxGeometry(Vector3(wallThickness, wallHeight, distance * 3.5f + wallThickness * 3));
	new RSObject(Vector3(distance * 3.5f, 0, 0), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 3.5f, 0, 0), &geo, { 1, 0, 0, 1 });
	geo = physx::PxBoxGeometry(Vector3(distance * 3.5f + wallThickness * 3, wallHeight, wallThickness));
	new RSObject(Vector3(0, 0, distance * 3.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(0, 0, -distance * 3.5f), &geo, { 0, 0, 1, 1 });

	geo = physx::PxBoxGeometry(Vector3(wallThickness, wallHeight, distance / 2));
	new RSObject(Vector3(distance * 2.5f, 0, distance * 3), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 2.5f, 0, -distance), &geo, { 1, 0, 0, 1 });

	new RSObject(Vector3(distance * 1.5f, 0, distance * 2), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 1.5f, 0, distance), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 1.5f, 0, 0), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 1.5f, 0, -distance * 2), &geo, { 1, 0, 0, 1 });

	new RSObject(Vector3(distance * 0.5f, 0, distance * 2), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 0.5f, 0, distance), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 0.5f, 0, -distance), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(distance * 0.5f, 0, -distance * 2), &geo, { 1, 0, 0, 1 });

	new RSObject(Vector3(-distance * 0.5f, 0, distance * 3), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 0.5f, 0, distance * 2), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 0.5f, 0, 0), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 0.5f, 0, -distance), &geo, { 1, 0, 0, 1 });

	new RSObject(Vector3(-distance * 1.5f, 0, distance), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 1.5f, 0, -distance), &geo, { 1, 0, 0, 1 });

	new RSObject(Vector3(-distance * 2.5f, 0, distance * 2), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 2.5f, 0, distance), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 2.5f, 0, 0), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-distance * 2.5f, 0, -distance * 2), &geo, { 1, 0, 0, 1 });

	geo = physx::PxBoxGeometry(Vector3(distance / 2, wallHeight, wallThickness));
	new RSObject(Vector3(-distance * 2, 0, distance * 2.5f), &geo, { 0, 0, 1, 1 });

	new RSObject(Vector3(distance * 2, 0, distance * 1.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(-distance, 0, distance * 1.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(-distance * 2, 0, distance * 1.5f), &geo, { 0, 0, 1, 1 });

	new RSObject(Vector3(distance * 3, 0, distance * 0.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(0, 0, distance * 0.5f), &geo, { 0, 0, 1, 1 });

	new RSObject(Vector3(distance * 2, 0, -distance * 0.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(distance, 0, -distance * 0.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(-distance * 2, 0, -distance * 0.5f), &geo, { 0, 0, 1, 1 });

	new RSObject(Vector3(-distance, 0, -distance * 1.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(-distance * 3, 0, -distance * 1.5f), &geo, { 0, 0, 1, 1 });

	new RSObject(Vector3(distance * 3, 0, -distance * 2.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(distance * 2, 0, -distance * 2.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(0, 0, -distance * 2.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(-distance, 0, -distance * 2.5f), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(-distance * 2, 0, -distance * 2.5f), &geo, { 0, 0, 1, 1 });

	geo = physx::PxBoxGeometry(Vector3(distance * 3.5f + wallThickness * 3, 1, distance * 3.5f + wallThickness * 3));
	new RSObject(Vector3(0, -wallHeight, 0), &geo, { 0, 1, 0, 1 });
	new RSObject(Vector3(0, wallHeight, 0), &geo, { 1, 1, 1, 0.3f });

	new Target({ distance * 3, -distance * 0.5f, distance * 3 });
	new Target({ -distance * 2, -distance * 0.5f, distance * 2 });
	new Target({ -distance * 2, -distance * 0.5f, distance });
	new Target({ -distance * 3, -distance * 0.5f, -distance * 2 });



	geo = Vector3(10, 10, 10);
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 1 }, false);
}

void Map1::deleteMap() {

}

void Map1::clearedTargets() {
	physx::PxBoxGeometry geo(Vector3(10, 10, 10));
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 0 }, true, [this]() -> void {
		scene->nextMap();
	});
}
