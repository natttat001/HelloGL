#include "GLUTCallbacks.h"
#include "hello.h"

namespace GLUTCallbacks
{
	namespace
	{
		hello* helloo = nullptr;
	}
	void Init (hello* gl)
	{
		helloo = gl;
	}
	void Display()
	{
		if(helloo != nullptr)
		{
			helloo -> Display();
		}
	}
	void Keyboard(unsigned char key, int x, int y)
	{
		helloo->Keyboard(key, x, y);
	}
	void MouseHover(int x, int y)
	{
		helloo->MouseHover(x, y);
	}
	void PassiveMouse(int x, int y)
	{
		helloo->PassiveMouse(x, y);
	}
	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloo ->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}
}
// DM C# va UNITY