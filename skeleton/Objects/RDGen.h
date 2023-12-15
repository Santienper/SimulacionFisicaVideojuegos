#pragma once
#include "Structure/Object.h"
#include "Systems/RDSystem.h"
#include <random>

class RDGen : public Object {
public:
	struct RDVisuals {
		physx::PxGeometry* geo;
		Vector4 color;
		RDVisuals(physx::PxGeometry* geo, Vector4 color) : geo(geo), color(color) { }
		~RDVisuals() { delete geo; }
	};

	RDGen(const Vector3& pos, std::vector<RDVisuals*> visuals, double rate = 1, const Vector3& rndVel = Vector3(5, 0, 5), const Vector3& startVel = Vector3(0, 20, 0), float maxTime = 5);
	~RDGen();

	void update(double t);

protected:
	using RDData = RDSystem::RDManaging;
	virtual void createRD(RDData& data);

	std::normal_distribution<float> rnd;
	std::uniform_int_distribution<> intRnd;
	std::mt19937 gen;
	Vector3 startVel, rndVel;
private:
	double time, rate, startRate;
	SpPtr<RDSystem> sys;
	float maxTime;
	std::vector<RDVisuals*> visuals;
};