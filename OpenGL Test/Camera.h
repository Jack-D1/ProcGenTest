#pragma once

#include <glm\glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Transform.h"

class Camera {
public:
	static void init();
	static void tick();

	static void move(glm::vec3 amt);

	static glm::mat4 getEye();

	~Camera();

private:

};

