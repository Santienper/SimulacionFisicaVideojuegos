#pragma once
#include "Core/RenderUtils.hpp"

void createScene();
class Shooter;

class Scene {
	friend class Object;
public:
	static Scene* get() { return instance; }
	Scene();
	virtual ~Scene();

	Camera* cam;

	void update(double t);
	void keyPressed(unsigned char key);
	Shooter* shoot;
protected:
	std::vector<Object*> objects;
private:
	void addObject(Object* obj);

	static Scene* instance;
};