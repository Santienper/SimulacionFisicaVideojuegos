#include "Structure/Scene.h"

#include "Objects/Target.h"
#include "Systems/TargetSystem.h"

#include "Utilities/MouseControl.h"

#include "Objects/Player.h"
#include "Objects/Fader.h"

void createScene() {
	new TargetSystem();

	//new Target();
	//new Target(Vector3(3));
	//new Target(Vector3(-3));

	new Player(Vector3(10));
	auto
	geo = physx::PxBoxGeometry(Vector3(1, 100, 100));
	new RSObject(Vector3(100, 0, 0), &geo, { 1, 0, 0, 1 });
	new RSObject(Vector3(-100, 0, 0), &geo, { 0, 1, 1, 1 });
	geo = physx::PxBoxGeometry(Vector3(100, 100, 1));
	new RSObject(Vector3(0, 0, 100), &geo, { 0, 0, 1, 1 });
	new RSObject(Vector3(0, 0, -100), &geo, { 1, 1, 0, 1 });
	geo = physx::PxBoxGeometry(Vector3(100, 1, 100));
	new RSObject(Vector3(0, -50, 0), &geo, { 0, 1, 0, 1 });
	//geo = physx::PxBoxGeometry(Vector3(5));
	//new RDObject(Vector3(10), &geo);
	Scene::get()->cam->changeDir(Vector3(0, -1, 0.00001f));
	geo = physx::PxBoxGeometry(Vector3(1, 1, 20));
	new RSObject(Vector3(0, 0, 15), &geo, { 1, 0.5f, 1, 0.3f });

}

// ¡¡¡IMPORTANTE!!!
// Los objetos/sistemas creados con "new" se borran automáticamente desde la escena, así que no se debería llamar a ningún "delete" manualmente.
// (Para borrar un objeto/sistema durante ejecución, pon la propiedad "alive" a false.)
void deleteScene() {

}