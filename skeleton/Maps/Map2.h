#pragma once
#include "Structure/Map.h"

class Map2 : public Map {
public:
	Map2();
	void createMap() override;
	void deleteMap() override;
	void clearedTargets() override;
};