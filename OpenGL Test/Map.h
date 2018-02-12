#pragma once

#define MAP_SIZE 2
#define TILE_SIZE 32

#include <vector>
#include "Mesh.h"

class Map {
public:
	Map();


	void render();

	~Map();

private:
	Shader *mapShader;
	Mesh *mesh1;

	struct Chunk {
		Mesh *mesh;
		Shader *shader;
		glm::vec2 pos;
	};

	void gen(int seed);

	std::vector<Chunk> chunks;
	GLint tiles[TILE_SIZE * TILE_SIZE];
};

