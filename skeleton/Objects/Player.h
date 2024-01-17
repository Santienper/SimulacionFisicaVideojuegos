#pragma once
#include "RDObject.h"

class Player : public RDObject {
public:
	Player(const Vector3& pos = Vector3(0), const Vector3& camPos = Vector3(0), float mass = 0.15);
	~Player();

	void update(double t) override;
	void keyPressed(unsigned char key) override;
	void keyReleased(unsigned char key) override;
	void specialKeyPressed(int key) override;
	void mouseMoved(int x, int y) override;
	void mousePressed(int button, int state, int x, int y) override;

	void restrict(bool restricted);
private:
	Camera* cam;
	Vector3 move;
	bool wPressed, aPressed, sPressed, dPressed;
	// mouseBlock
	bool mBlock, mBlocked;
	bool fpsMode, restricted;
	Vector3 cameraDir;
};