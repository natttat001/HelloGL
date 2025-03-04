#pragma once
#include <iostream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16


class hello
{
public:
	Camera* camera;
	Cube* cube;
	int screenWidth;
	int screenHeight;

	int centerX;
	int centerY;

	void Display();
	void MouseHover(int x, int y);
	void PassiveMouse(int x, int y);
	void Timer(int preferredRefresh);
	hello(int argc, char* argv[]);
	~hello(void);
	void DrawRectangle();
	void DrawScaleneTriangle();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void DrawWireSphere(float rotation);
private:
	float rotation;
};

