#pragma once
#include "Structure/Map.h"

class Map3 : public Map {
public:
	Map3();
	void createMap() override;
	void deleteMap() override;
	void clearedTargets() override;
};