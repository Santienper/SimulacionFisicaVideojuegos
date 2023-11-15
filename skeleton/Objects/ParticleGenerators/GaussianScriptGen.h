#pragma once
#include "GaussianPartGen.h"
#include <functional>

class GaussianScriptGen : public GaussianPartGen {
public:
	GaussianScriptGen(const Vector3& pos, double rate, double sigma, const Vector3& startVel = Vector3(0, 20, 0), const Vector3& rndVel = Vector3(1, 0, 1));
	void setCallback(std::function<void(Particle*)>);
protected:
	void createParticle(ParticleData& data);
	std::vector<std::function<void(Particle*)>> callbacks;
};