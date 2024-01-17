#pragma once
#include "Structure/Map.h"

class Map1 : public Map {
public:
	Map1();
	void createMap() override;
	void deleteMap() override;
	void clearedTargets() override;
};