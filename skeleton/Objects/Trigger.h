#pragma once
#include "Structure/Object.h"

class Trigger : public Object {
public:
	Trigger();
	void update(double t);

	void setCallbackEnter();
	void setCallbackLoop();
	void setCallbackExit();
protected:
	virtual bool isInside(Object*) = 0;
private:
	void* (*callbackEnter)(), *(*callbackLoop)(), *(*callbackExit)();
};