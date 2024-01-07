#pragma once
#include "RSObject.h"

class Fader : public RSObject {
public:
	Fader(const Vector3& pos, physx::PxGeometry* geo, const Vector4& color) : RSObject(pos, geo, color), rising(false) {
		subKey(true);
	}
	void update(double t) override {
		if(render->color.w >= 1) rising = true;
		//else if(render->color.w <= 0) rising = true;

		float change = 0.01f;
		if(!rising) //change = -change;
			render->color.w += change;
	}
	void keyPressed(unsigned char key) override {
		if(key == 'u') {
			rising = false;
			render->color.w = 0;
		}
	}
private:
	bool rising;
};
