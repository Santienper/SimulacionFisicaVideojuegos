#pragma once
#include "Structure/Object.h"
#include <unordered_map>
#include <functional>

class Keys : public Object {
public:
	Keys();

	void add(char key, std::function<void(void)>);
	void remove(char key);

	void keyPressed(unsigned char key) override;
private:
	std::unordered_map<char, std::vector<std::function<void(void)>>> map;
};