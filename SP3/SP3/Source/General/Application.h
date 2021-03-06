#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"
#include "../Scene/Scene.h"

class Application
{
public:
	static Application& GetInstance()
	{
		static Application app;
		return app;
	}
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);
	static bool IsMousePressed(unsigned short key);
	static void GetCursorPos(double *xpos, double *ypos);
	static void SetCursorPos(double xpos, double ypos);

	// Set glfw cursor input types
	static void SetDisabledCursor();
	static void SetNormalCursor();

    void GetMonitorResolution();

	static int GetWindowWidth();
	static int GetWindowHeight();

    static int m_width;
    static int m_height;

    static double cursorXPos;
    static double cursorYPos;

    static double mouseWheelX;
    static double mouseWheelY;

private:
	Application();
	~Application();

	//Declare a window object
	StopWatch m_timer;
};

#endif