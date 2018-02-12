#include "Mesh.h"

const static glm::mat4 projection = glm::perspective(45.0f, (float)1200 / 800, 01.f, 100.0f);

Mesh::Mesh() {
	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	GLfloat texCoords[]{
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	vertexCount = sizeof(indices) / sizeof(GLuint);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &tbo);
	glGenBuffers(1, &ibo);

	glGenVertexArrays(1, &vao); {
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

		glBindBuffer(GL_ARRAY_BUFFER, tbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glEnableVertexAttribArray(0);
	}
	glBindVertexArray(0);

	transform = new Transform();
}

void Mesh::attachShader(Shader* shader) {
	this->shader = shader;
	shader->addUniform("transform");
	shader->addUniform("eye");
	shader->addUniform("proj");

	shader->setUniformMat4f("transform", transform->getTransform());
	shader->setUniformMat4f("proj", projection);
	shader->setUniformMat4f("eye", Camera::getEye());
}

void Mesh::setTexture(Texture *texture) {
	this->texture = texture;
}

void Mesh::rotate(glm::vec3 amt) {
	transform->rotate(amt);
}

void Mesh::move(glm::vec3 amt) {
	transform->move(amt);
}

void Mesh::scale(glm::vec3 amt) {
	transform->reScale(amt);
}

void Mesh::tick() {
	shader->setUniformMat4f("transform", transform->getTransform());
	shader->setUniformMat4f("eye", Camera::getEye());
}

void Mesh::render() {
	shader->bind();
	if(texture != NULL) texture->bind();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	if(texture != NULL) texture->unbind();
	shader->unbind();
}

Mesh::~Mesh() {
}
