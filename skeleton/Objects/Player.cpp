#include "Player.h"
#include "Structure/Scene.h"
#include "Utilities/MouseControl.h"

Player::Player(const Vector3& pos, const Vector3& camPos, float mass) : RDObject(pos, nullptr, Vector3(0), mass), move(Vector3(0)), cameraDir(Vector3(0)),
	fpsMode(false), restricted(false), mBlock(false), mBlocked(false), wPressed(false), aPressed(false), sPressed(false), dPressed(false) {
	trans.p = camPos;

	cam = scene->cam;
	cam->changeCam(trans.p);
	subKeyPress(true);
	subKeyRelease(true);
	subMouseMove(true);
	subMousePress(true);
	auto geo = physx::PxBoxGeometry(Vector3(2));
	createShape(&geo);
	Vector3 dir = pos - camPos;
	if(dir.y == 1) dir.y += 0.00001f;
	cam->changeDir(dir);
}

Player::~Player() {
	if(fpsMode) RegisterRenderItem(render);
	Mouse::showCursor(true);
}

void Player::update(double t) {
	//clearAcum();

	move = Vector3(0);
	if(wPressed) move.z =  1;
	if(aPressed) move.x = -1;
	if(sPressed) move.z = -1;
	if(dPressed) move.x =  1;
	move.normalize();

	const Vector3 normal = cam->getDir().cross(Vector3(0, 1, 0)).getNormalized();
	const Vector3 dir = restricted ? -(normal.cross(Vector3(0, 1, 0)).getNormalized()) : cam->getDir();
	Vector3 force = dir * move.z + normal * move.x;
	force.normalize();
	addForce(force * 100);
	//Log::logInfo("x: " + std::to_string(trans.p.x) + ", y: " + std::to_string(trans.p.y) + ", z: " + std::to_string(trans.p.z));

	RDObject::update(t);

	if(fpsMode) cam->changeCam(rigid->getGlobalPose().p);
}

void Player::keyPressed(unsigned char key) {
	switch(key) {
	case 'w': wPressed = true; break;
	case 'a': aPressed = true; break;
	case 's': sPressed = true; break;
	case 'd': dPressed = true; break;
	case 'p':
		if(fpsMode = !fpsMode) {
			DeregisterRenderItem(render);
			if(restricted) {
				cameraDir = cam->getDir();
			}
		}
		else {
			RegisterRenderItem(render);
			cam->changeCam(trans.p);
			scene->resetRender();
			if(restricted) {
				mBlock = mBlocked = false;
				Mouse::showCursor(true);
				cam->changeDir(cameraDir);
			}
		}
		break;
	case 'r':
		if(restricted = !restricted && !fpsMode) {
			mBlock = mBlocked = false;
			Mouse::showCursor(true);
		}
		break;
	default: break;
	}
	//Log::logInfo(std::to_string(key));
}

void Player::keyReleased(unsigned char key) {
	switch(key) {
	case 'w': wPressed = false; break;
	case 'a': aPressed = false; break;
	case 's': sPressed = false; break;
	case 'd': dPressed = false; break;
	default:                    break;
	}
}

void Player::specialKeyPressed(int key) {

}

void Player::mouseMoved(int x, int y) {
	if(mBlock) {
		Mouse::getPos(x, y);
		int centerX, centerY;
		Mouse::getWindowBounds(centerX, centerY);
		centerX /= 2;
		centerY /= 2;
		Mouse::setPos(centerX, centerY);
		if(mBlocked && (x != centerX || y != centerY)) {
			const float dx = (centerX - x) / 10.0f;
			const float dy = (centerY - y) / 10.0f;

			Vector3 dir = scene->cam->getDir();
			const Vector3 viewY = dir.cross(Vector3(0, 1, 0)).getNormalized();

			const physx::PxQuat qx(physx::PxPi * dx / 180.0f, Vector3(0, 1, 0));
			dir = qx.rotate(dir);
			const physx::PxQuat qy(physx::PxPi * dy / 180.0f, viewY);
			dir = qy.rotate(dir);

			scene->cam->changeDir(dir);
		}
		mBlocked = true;
	}
}
void Player::mousePressed(int button, int state, int x, int y) {
	if(state == 0) {
		if(button == 0) {
			if(!restricted || fpsMode) {
				mBlock = true;
				Mouse::showCursor(false);
			}
		} else if(button == 2) {
			mBlock = mBlocked = false;
			Mouse::showCursor(true);
		}
	}
}

void Player::restrict(bool restricted) {
	this->restricted = restricted;
}
