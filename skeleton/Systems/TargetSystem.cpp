#include "TargetSystem.h"
#include "Objects/Target.h"

TargetSystem::TargetSystem() : SystemConstr {
	
}

TargetSystem::~TargetSystem() {
	for(Target* tg : targets) tg->alive = false;
}

void TargetSystem::update(double t) {
	
}

void TargetSystem::addTarget(Target* tg) {
	targets.push_back(tg);
}

void TargetSystem::targetHit(Target* tg) {
	for(auto it = targets.cbegin(); it != targets.cend(); ++it) {
		if(*it == tg) {
			targets.erase(it);
			break;
		}
	}
	tg->alive = false;
	if(targets.size() == 0) {
		// TODO: Ganaste!!! :D
	}
}
