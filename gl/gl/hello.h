#pragma once
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
	void Display();
	void Timer(int preferredRefresh);
	hello(int argc, char* argv[]);
	~hello(void);
	void DrawRectangle();
	void DrawScaleneTriangle();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
private:
	float rotation;
};

