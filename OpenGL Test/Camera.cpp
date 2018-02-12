#include "Camera.h"

using namespace glm;

static vec3 pos, target, direction, right, cameraUp, front;
static vec3 up;
static mat4 view;

void Camera::init() {
	up = vec3(0.0f, 1.0f, 0.0f);

	pos = vec3(0.0f, 0.0f, -1.0f);

	target = vec3(0.0f, 0.0f, 0.0f);
	front = glm::vec3(0.0f, 0.0f, 1.0f);
	direction = normalize(pos - target);
	right = normalize(cross(up, direction));
	cameraUp = cross(direction, right);

	view = glm::translate(view, pos); 
	//view = lookAt(pos, pos + front, cameraUp);
}

void Camera::move(vec3 amt) {
	//pos += amt;
	view = glm::translate(view, amt);
}

void Camera::tick() {
	direction = normalize(pos - target);
	right = normalize(cross(up, direction));
	cameraUp = cross(direction, right);
	
	//view = glm::translate(view, -pos);
}

mat4 Camera::getEye() {
	return view;
}

Camera::~Camera() {
}
