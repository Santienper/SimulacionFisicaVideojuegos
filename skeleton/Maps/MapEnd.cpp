#include "MapEnd.h"
#include "Objects/Player.h"
#include "Objects/RSObject.h"
#include "Objects/Target.h"
#include "Objects/Fader.h"

#include "Objects/ParticleGenerators/BasicFireworkGen.h"
#include "Objects/Fireworks.h"

class Reset : public Object {
public:
	Reset() {
		subKeyPress(true);
	}
	void keyPressed(unsigned char key) override {
		if(key == 'r') {
			physx::PxBoxGeometry geo(Vector3(10, 10, 10));
			new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 0 }, true, [this]() -> void {
				scene->loadMap(0);
			});
		}
	}
};

MapEnd::MapEnd() {

}

void MapEnd::createMap() {
	physx::PxBoxGeometry geo(Vector3(10, 10, 10));
	new Fader(scene->cam->getEye(), &geo, { 0, 0, 0, 1 }, false);

	new Reset();
	//new Player();

	display_text = "¡Has ganado! Pulsa 'R' para volver al primer nivel.";
	scene->cam->changeCam(Vector3(0));
	scene->cam->changeDir(Vector3(0, 0, 1));

	new BasicFireworkGen<Firework4>({ 0, -20, 100 }, 1, Vector3(5), 1.5, -1, Vector3(0, 20, 0));
}

void MapEnd::deleteMap() {
	display_text = "";
}

void MapEnd::clearedTargets() {
	
}
