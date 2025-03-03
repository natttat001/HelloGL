#pragma once

class hello;

namespace GLUTCallbacks
{
	void Init(hello* gl);
	void Display();
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
	void MouseHover(int x, int y);
	void PassiveMouse(int x, int y);
}
