#pragma once

// Solo funciona con windows (como la API de renderizado),
// si se quiere compilar/ejectuar en otro sistema operativo,
// implementar las funciones en el '.cpp'.

class Mouse {
public:
	static void init();
	static void destroy();

	static void getPos(int& x, int& y);
	static void setPos(int x, int y);
	static void getWindowBounds(int& width, int& height);
	static void showCursor(bool show);
private:
	// Para definir de manera distinta según el sistema operativo
	struct Window;
	static Window* win;
};