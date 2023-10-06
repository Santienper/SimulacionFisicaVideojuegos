#include "Shooter.h"
#include "Particle.h"
#include "Structure/Scene.h"

Shooter::Shooter() {

}

void Shooter::keyPressed(unsigned char key) {
	if(key == ' ') {
		const Camera* cam = Scene::get()->cam;
		new Particle(cam->getEye(), Vector3(0), cam->getDir() * 10);
	}
}