#pragma once
#include "Structure/System.h"
#include "Objects/RDObject.h"
#include <unordered_map>
#include <unordered_set>

class ForceSystem;

class RDSystem : public System {
public:
	setID("rigidDynamic");

	RDSystem();
	~RDSystem();

	void addRD(RDObject* part, double maxTime, bool disappear);

	struct RDManaging {
		RDObject* rigid;
		double time, maxTime;
		bool disappear;
	};
	void addRD(RDManaging data);

	void update(double t);

	void getOtherSystems();
protected:
	std::vector<RDManaging> rigids;
	SpPtr<ForceSystem> forceSys;
};
