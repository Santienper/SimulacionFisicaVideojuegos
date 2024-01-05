#include "Structure/Scene.h"

#include "Objects/Target.h"
#include "Systems/TargetSystem.h"

void createScene() {
	auto sys = new TargetSystem();

	//new Target();
	//new Target(Vector3(3));
	//new Target(Vector3(-3));

	physx::PxGeometry* geo = new physx::PxSphereGeometry(3);
	new RSObject(Vector3(0), geo);
	new RSObject(Vector3(3), geo);
	delete geo;

	//sys->alive = false;
}

// ¡¡¡IMPORTANTE!!!
// Los objetos/sistemas creados con "new" se borran automáticamente desde la escena, así que no se debería llamar a ningún "delete" manualmente.
// (Para borrar un objeto/sistema durante ejecución, pon la propiedad "alive" a false.)
void deleteScene() {

}