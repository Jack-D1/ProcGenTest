#define GLEW_STATIC
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include "Mesh.h"
#include "Transform.h"
#include "Input.h"
#include "Player.h"
#include "Map.h"

void initGLFW();
void initGL();
void createWindow(int width, int height, char* title);
void tick();
void render();
void exit();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow *window, double xPos, double yPos);

GLFWwindow* window;
int windowWidth, windowHeight;
char* windowTitle;

Map *map;

Player *player;

int main(int argc, char *argv[]) {
	initGLFW();
	createWindow(1200, 800, "OpenGl Window");
	initGL();

	map = new Map();

	Camera::init();
	player = new Player();

	while (!glfwWindowShouldClose(window)) {
		tick();
		render();
	}

	exit();

	return 0;
}

void initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void initGL() {
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
	}

	int width, height;
	//glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, windowWidth, windowHeight);
	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, mouse_callback);
}

void createWindow(int width, int height, char* title) {
	windowWidth = width;
	windowHeight = height;
	windowTitle = title;
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
}

void tick() {
	glfwPollEvents();
	player->tick();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	Input::tickKeys(key, scancode, action, mode);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
}

void mouse_callback(GLFWwindow *window, double xPos, double yPos) {
	Input::tickMouse(xPos, yPos);
}

void render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	map->render();
	glfwSwapBuffers(window);
}

void exit() {
	glfwTerminate();
	delete window;
}