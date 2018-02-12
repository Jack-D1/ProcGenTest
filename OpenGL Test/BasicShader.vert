#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 2) in vec2 texCoord;

out vec2 textureCoord;

uniform mat4 transform;
uniform mat4 proj;
uniform mat4 eye;

void main() {
	textureCoord = texCoord;
	gl_Position = proj * eye * transform * vec4(pos, 1.0);
}