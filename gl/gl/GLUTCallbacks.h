#pragma once

class hello;

namespace GLUTCallbacks
{
	void Init(hello* gl);
	void Display();
	void Timer(int preferredRefresh);
}
