#pragma once

#include <GLFW\glfw3.h>

class Input {
public:
	static bool keys[];
	static double xPos, yPos, deltaX, deltaY;

	static void tickKeys(int key, int scancode, int action, int mode);
	static void tickMouse(double xPos, double yPos);
	~Input();
};

