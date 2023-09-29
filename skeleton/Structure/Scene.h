#pragma once
#include "Core/RenderUtils.hpp"

void createScene();

class Scene {
	friend class Object;
public:
	static Scene* get() { return instance; }
	Scene();
	virtual ~Scene();

	Camera* cam;

	void update(double t);
	void keyPressed(unsigned char key);
protected:
	std::vector<Object*> objects;
private:
	void addObject(Object* obj);

	static Scene* instance;
};