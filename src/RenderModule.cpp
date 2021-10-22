/*

Game Boy Color - Screen

Resolution: 160(w) x 144(h)
FPS: 59.7 (1s / 59.7fps = 0.01675041876046901172529313232831s interval between frames)

Written by Anders Wilhelmsen

*/

#include <Windows.h>
#include <iostream>
#include <thread>
#include <synchapi.h>

HWND window = GetConsoleWindow();
HDC cdc = GetDC(window);



class RenderModule
{
public:
	void Run()
	{
		std::thread(Render);
	}

	void Render()
	{
		Sleep(RenderInterval);
	}

private:
	const int RenderInterval = (1 / 60) * 1000;
};

//int main()
//{
//    for (;;)
//    {
//       
//        SetPixelV(cdc, 10, 10, RGB(255, 255, 255));
//    }
//}