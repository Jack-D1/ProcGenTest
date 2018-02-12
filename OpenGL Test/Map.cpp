#include "Map.h"

/*Map::Map() {
	Mesh *mesh = new Mesh();
	mapShader = new Shader("TileMap");
	mesh->attachShader((Shader*) mapShader);

	Chunk *chunk = new Chunk;
	chunk->mesh = mesh;
	chunk->mesh->attachShader(mapShader);
	chunks.push_back(*chunk);
}*/

Map::Map() {
	Chunk *chunk = new Chunk;
	Mesh *mesh;
	mapShader = new Shader("TileMap");
	mapShader->addUniform("tiles");
	for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
		gen(32323);

		mapShader->setUniformIntA("tiles", sizeof(tiles), tiles);

		mesh = new Mesh();

		float x = int(i % MAP_SIZE);
		float y = floor(i / MAP_SIZE);
		mesh->move(glm::vec3(x, y, 0.0f));

		chunk->mesh = mesh;
		chunk->mesh->attachShader(mapShader);
		chunks.push_back(*chunk);
	}
}

void Map::gen(int seed) {
	tiles[0] = 1;
	for (int j = 1; j < TILE_SIZE * TILE_SIZE; j++) {
		tiles[j] = rand() % 2;
	}

}

void Map::render() {
	for (int i = 0; i < chunks.size(); i++) {
		chunks.at(i).mesh->tick();
		chunks.at(i).mesh->render();
	}
}

Map::~Map() {
	chunks.clear();
	delete tiles;
}
