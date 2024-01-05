#pragma once
#include "Structure/System.h"

class Target;

class TargetSystem : public System {
public:
	setID("targets");

	TargetSystem();
	~TargetSystem();

	void update(double t) override;
private:
	friend class Target;
	void addTarget(Target*);
	void targetHit(Target*);
	std::vector<Target*> targets;
};