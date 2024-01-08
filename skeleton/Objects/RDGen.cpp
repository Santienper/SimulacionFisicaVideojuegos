#include "RDGen.h"
#include "Structure/Scene.h"

RDGen::RDGen(const Vector3& pos, std::vector<RDVisuals*> visuals, double rate, const Vector3& rndVel, const Vector3& startVel, float maxTime)
	: Object(pos), rnd(0, 1), intRnd(0, visuals.size() - 1), time(0), visuals(visuals), rate(rate), rndVel(rndVel), startVel(startVel), maxTime(maxTime), startRate(rate) {
	sys = scene->getSystem<RDSystem>();
	if(sys == nullptr) {
		alive = false;
		Log::logError("No hay sistema de solidos rigidos, omitiendo creacion de generador de solidos rigidos");
		return;
	}
	std::random_device rd;
	gen = std::mt19937(rd());
}

RDGen::~RDGen() {
	for(RDVisuals* visual : visuals) {
		delete visual;
	}
}

void RDGen::update(double t) {
	time += t;

	if(sys == nullptr) {
		alive = false;
		return;
	}

	if(time > rate) {
		time -= rate;
		RDData data{ nullptr, 0, 0, false };
		createRD(data);
		sys->addRD(data);
	}
}

void RDGen::createRD(RDData& data) {
	const Vector3 aux(rndVel.x * rnd(gen), rndVel.y * rnd(gen), rndVel.z * rnd(gen));
	const Vector3 vel = startVel + aux;
	RDVisuals* visual = visuals.at(intRnd(gen)); // Saca una forma aleatoria del vector
	data.rigid = new RDObject(trans.p, visual->geo, vel, 0.998f, 1, visual->color);
	data.maxTime = maxTime; data.disappear = false;

	rate = rnd(gen) * 0.2f + startRate;
}
