#pragma once
#include <iostream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

struct Vector3 { float x, y, z; };
struct Camera
{
	Vector3 eye, center, up;
};

class hello
{
public:
	Camera* camera;
	int screenWidth;
	int screenHeight;

	int centerX = screenWidth / 2;
	int centerY = screenHeight / 2;

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
	void DrawCube();
	void DrawWireSphere(float rotation);
private:
	float rotation;
};

