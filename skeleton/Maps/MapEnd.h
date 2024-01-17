#pragma once
#include "Structure/Map.h"

class MapEnd : public Map {
public:
	MapEnd();
	void createMap() override;
	void deleteMap() override;
	void clearedTargets() override;
};