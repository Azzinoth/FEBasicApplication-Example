#include "FEBasicApplication/FEBasicApplication.h"
using namespace FocalEngine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	APPLICATION.InitWindow(1280, 720, "FEBasicApplication example");

	while (APPLICATION.IsWindowOpened())
	{
		APPLICATION.BeginFrame();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ImGui::ShowDemoWindow();

		APPLICATION.EndFrame();
	}

	return 0;
}