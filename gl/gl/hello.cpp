#include "hello.h"


void hello::Update()
{
	glLoadIdentity();
	gluLookAt(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);
	rotation += 0.5f;
	if (rotation >= 360.0f) rotation = 0.0f;
	glutPostRedisplay();
}
hello::hello(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 1.0f;

	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;

	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv); // initialize
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}
void hello::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	DrawScaleneTriangle();
	glutSwapBuffers();
	glFlush();
}
void hello::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotation += 0.5f;
	}
}
void hello::Timer(int preferredRefresh)
{

}
hello::~hello(void)
{
	delete(camera);
}

void hello::DrawRectangle()
{
	glBegin(GL_POLYGON);
	{
		glVertex2f(-0.75, 0.5);
		glVertex2f(0.75, 0.5);
		glVertex2f(0.75, -0.5);
		glVertex2f(-0.75, -0.5);
		glEnd();
	}
}
void hello::DrawScaleneTriangle()
{
	glBegin(GL_POLYGON);
	{
		glVertex2f(-0.1, 0.5);
		glVertex2f(-0.75, -0.5);
		glVertex2f(0.5, -0.5);
		glEnd();
	}
}