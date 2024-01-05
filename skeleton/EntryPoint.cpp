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

// ���IMPORTANTE!!!
// Los objetos/sistemas creados con "new" se borran autom�ticamente desde la escena, as� que no se deber�a llamar a ning�n "delete" manualmente.
// (Para borrar un objeto/sistema durante ejecuci�n, pon la propiedad "alive" a false.)
void deleteScene() {

}