#include "Input.h"
#include <iostream>

bool Input::keys[100];
double Input::xPos, Input::yPos, Input::deltaX, Input::deltaY;

void Input::tickKeys(int key, int scancode, int action, int mode) {
	if (action == 1) {
		keys[key] = true;
	} 
	else if (action == 0) {
		keys[key] = false;
	}
}

void Input::tickMouse(double xPos, double yPos) {
	deltaX = Input::xPos - xPos;
	Input::xPos = xPos;
	deltaY = Input::yPos - yPos;
	Input::yPos = yPos;
}

Input::~Input() {
}
