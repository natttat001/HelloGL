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
	screenWidth = 800;
	screenHeight = 800;
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
	glViewport(0, 0, screenWidth, screenHeight);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMotionFunc(GLUTCallbacks::MouseHover);
	glutPassiveMotionFunc(GLUTCallbacks::PassiveMouse);
	glutMainLoop();
}
void hello::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0.0f, 0.0f, -5.0f);
	DrawCube();
	glutSwapBuffers();
	glFlush();
}
void hello::MouseHover(int x, int y)
{
	int dx = x - centerX;
	int dy = y - centerY;

	camera->center.x += 0.02f * dx;
	camera->center.y -= 0.02f * dy;

	centerX = x;
	centerY = y;
}
void hello::PassiveMouse(int x, int y)
{
	centerX = x;
	centerY = y;
}
void hello::Keyboard(unsigned char key, int x, int y)
{
	/*if (key == 'd') {
		camera->eye.x -= 0.1f;
	}

	if (key == 'a') {
		camera->eye.x += 0.1f;
	}

	if (key == 'w') {
		camera->eye.z -= 0.1f;
	}

	if (key == 's') {
		camera->eye.z += 0.1f;
	}*/
	const float moveSpeed = 0.1f; // Speed of camera movement

	switch (key)
	{
	case 'w': // Move forward
		camera->eye.z -= moveSpeed;
		camera->center.z -= moveSpeed;
		break;
	case 's': // Move backward
		camera->eye.z += moveSpeed;
		camera->center.z += moveSpeed;
		break;
	case 'a': // Move left
		camera->eye.x -= moveSpeed;
		camera->center.x -= moveSpeed;
		break;
	case 'd': // Move right
		camera->eye.x += moveSpeed;
		camera->center.x += moveSpeed;
		break;
	case 'q': // Move up
		camera->eye.y += moveSpeed;
		camera->center.y += moveSpeed;
		break;
	case 'e': // Move down
		camera->eye.y -= moveSpeed;
		camera->center.y -= moveSpeed;
		break;
	default:
		break;
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
void hello::DrawCube()
{
	glBegin(GL_TRIANGLES);

	// Face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);

	// Face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// Face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	// Face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// Face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);

	// Face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	// Face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// Face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);

	// Face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);

	// Face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// Face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);

	// Face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();

}
void hello::DrawWireSphere(float rotation)
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireSphere(1.0, 20, 10);
	glPopMatrix();
}