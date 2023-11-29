#pragma once
#include "Structure/Object.h"

class ChangeText : public Object {
public:
	ChangeText(std::string& display_text, bool& wind, bool& whirlwind, bool& gravity) : display_text(display_text), wind(wind), whirlwind(whirlwind), gravity(gravity) { }

	void update(double t) {
#define DISP_BOOL(param) std::string(param ? "true" : "false")

		display_text = "Wind: " + DISP_BOOL(wind) + " Whirlwind: " + DISP_BOOL(whirlwind) + " Gravity: " + DISP_BOOL(gravity);
	}
private:
	std::string& display_text;
	bool& wind, &whirlwind, &gravity;
};