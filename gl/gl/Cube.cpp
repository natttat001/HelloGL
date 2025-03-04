#include "Cube.h"
#include <iostream>
void Cube::Draw()
{
	glPushMatrix();

	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	std::cout << "Drawing Cube" << std::endl;
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();

}
Vertex Cube::indexedVertices[] = {
	{ 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 }, // v0-v1-v2 (front)
	{ -1, -1, 1 }, { 1, -1, 1 }, { 1, 1, 1 }, // v2-v3-v0
	{ 1, 1, 1 }, { 1, -1, 1 }, { 1, -1, -1 }, // v0-v3-v4 (right)
	{ 1, -1, -1 }, { 1, 1, -1 }, { 1, 1, 1 }, // v4-v5-v0
	{ 1, 1, 1 }, { 1, 1, -1 }, { -1, 1, -1 }, // v0-v5-v6 (top)
	{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 }, // v6-v1-v0
	{ -1, 1, 1 }, { -1, 1, -1 }, { -1, -1, -1 }, // v1-v6-v7 (left)
	{ -1, -1, -1 }, { -1, -1, 1 }, { -1, 1, 1 }, // v7-v2-v1
	{ -1, -1, -1 }, { 1, -1, -1 }, { 1, -1, 1 }, // v7-v4-v3 (bottom)
	{ 1, -1, 1 }, { -1, -1, 1 }, { -1, -1, -1 }, // v3-v2-v7
	{ 1, -1, -1 }, { -1, -1, -1 }, { -1, 1, -1 }, // v4-v7-v6 (back)
	{ -1, 1, -1 }, { 1, 1, -1 }, { 1, -1, -1 } // v6-v5-v4
};

Color Cube::indexedColors[] = {
	{ 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 0 }, // v0-v1-v2 (front)
	{ 1, 0, 0 }, { 1, 0, 1 }, { 1, 1, 1 }, // v2-v3-v0
	{ 1, 1, 1 }, { 1, 0, 1 }, { 0, 0, 1 }, // v0-v3-v4 (right)
	{ 0, 0, 1 }, { 0, 1, 1 }, { 1, 1, 1 }, // v4-v5-v0
	{ 1, 1, 1 }, { 0, 1, 1 }, { 0, 1, 0 }, // v0-v5-v6 (top)
	{ 0, 1, 0 }, { 1, 1, 0 }, { 1, 1, 1 }, // v6-v1-v0
	{ 1, 1, 0 }, { 0, 1, 0 }, { 0, 0, 0 }, // v1-v6-v7 (left)
	{ 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, // v7-v2-v1
	{ 0, 0, 0 }, { 0, 0, 1 }, { 1, 0, 1 }, // v7-v4-v3 (bottom)
	{ 1, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 }, // v3-v2-v7
	{ 0, 0, 1 }, { 0, 0, 0 }, { 0, 1, 0 }, // v4-v7-v6 (back)
	{ 0, 1, 0 }, { 0, 1, 1 }, { 0, 0, 1 } // v6-v5-v4
};

GLushort Cube::indices[] = {
	0, 1, 2, 2, 3, 0,
	4, 5, 6, 6, 7, 4,
	0, 1, 5, 5, 4, 0,
	2, 3, 7, 7, 6, 2,
	0, 3, 7, 7, 4, 0,
	1, 2, 6, 6, 5, 1
};

Cube::Cube() : _rotation(0.0f) {}
Cube::~Cube() {}

void Cube::Update() {
	_rotation += 0.1f;
}