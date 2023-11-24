#pragma once
#include "GaussianPartGen.h"
#include <functional>

class GaussianScriptGen : public GaussianPartGen {
public:
	GaussianScriptGen(const Vector3& pos, double rate, const Vector3& rndVel = Vector3(1, 0, 1), const Vector3& startVel = Vector3(0, 20, 0), float maxTime = 5);
	void addCallback(std::function<void(Particle*)>);
protected:
	void createParticle(ParticleData& data);
	std::vector<std::function<void(Particle*)>> callbacks;
private:
	float maxTime;
};