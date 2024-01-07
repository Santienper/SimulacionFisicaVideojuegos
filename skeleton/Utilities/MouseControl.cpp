#include "MouseControl.h"
#include "core.hpp"
#include "Log.h"

Mouse::Window* Mouse::win = nullptr;

// Solo compila con windows, si se quiere compilar con otro sistema operativo, implementar las funciones
#ifdef _WIN32
#include <Windows.h>

// Para definir de manera distinta según el sistema operativo
struct Mouse::Window {
	HWND window;
};

void Mouse::init() {
	win = new Window();
	win->window = FindWindowA(NULL, WINDOW_NAME);
}

void Mouse::destroy() {
	delete win;
}

void Mouse::getPos(int& x, int& y) {
	POINT point = { 0 };
	GetCursorPos(&point);
	RECT rect = { 0 };
	GetWindowRect(win->window, &rect);
	x = point.x - rect.left;
	y = point.y - rect.top;
}

void Mouse::setPos(int x, int y) {
	RECT rect = { 0 };
	GetWindowRect(win->window, &rect);
	if(x > rect.right - rect.left || y > rect.bottom - rect.top) {
		Log::logError("Einc?");
		return;
	}
	SetCursorPos(rect.left + x, rect.top + y);
}

void Mouse::getWindowBounds(int& width, int& height) {
	RECT rect = { 0 };
	GetWindowRect(win->window, &rect);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
}
void Mouse::showCursor(bool show) {
	while((ShowCursor(show) >= 0) != show);
}
#else
// IMPLEMENTAR AQUÍ
#endif