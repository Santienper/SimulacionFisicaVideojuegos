#include "Shooter.h"
#include "Particle.h"

Shooter::Shooter() {

}

void Shooter::keyPressed(unsigned char key) {
	if(key == ' ') {
		new Particle(Vector3(0), Vector3(0), Vector3(5, 0, 0));
	}
}