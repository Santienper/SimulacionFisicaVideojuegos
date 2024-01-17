#pragma once
#include "RSObject.h"
#include <functional>

class Fader : public RSObject {
public:
	Fader(const Vector3& pos, physx::PxGeometry* geo, const Vector4& color, bool rising = true, const std::function<void()>& finish = []() -> void { }) : RSObject(pos, geo, color), callback(finish), rising(rising) {
		subRenderReset(true);
	}
	void update(double t) override {
		if((rising && render->color.w >= 1) || (!rising && render->color.w <= 0)) {
			callback();
			alive = false;
		}

		constexpr float change = 0.01f;
		if(rising) render->color.w += change;
		else render->color.w -= change;
		trans.p = scene->cam->getEye();
		rigid->setGlobalPose(trans);
	}
private:
	bool rising;
	std::function<void()> callback;
};
