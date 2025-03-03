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
	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloo ->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}
}
// DM C# va UNITY