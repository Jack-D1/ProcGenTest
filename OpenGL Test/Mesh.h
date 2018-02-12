#pragma once
#include <vector>
#include <iostream>
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <SOIL\SOIL.h>
#include "Shader.h"
#include "Transform.h"
#include "Texture.h"
#include "Camera.h"

class Mesh {
public:
	Mesh();
	Mesh(char *path);

	void attachShader(Shader* shader);
	void setTexture(Texture* texture);

	void rotate(glm::vec3 amt);
	void move(glm::vec3 amt);
	void scale(glm::vec3 amt);

	void tick();
	void render();

	~Mesh();

private:
	GLuint vao, vbo, ibo, tbo;
	GLuint vertexCount;

	Shader *shader;
	Transform *transform;
	Texture *texture;
};

