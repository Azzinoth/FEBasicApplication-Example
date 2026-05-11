#include "SubSystems/FEBasicApplication/FEBasicApplication.h"
using namespace FocalEngine;

void MainWindowRender()
{
	ImGui::ShowDemoWindow();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	APPLICATION.AddWindow(1280, 720, "FEBasicApplication example");
	APPLICATION.GetWindow(0)->SetClearColor(0.6f, 0.85f, 0.917f, 1.0f);
	APPLICATION.GetWindow(0)->SetRenderFunction(MainWindowRender);

	while (APPLICATION.IsNotTerminated())
	{
		APPLICATION.BeginFrame();

		APPLICATION.RenderWindows();

		APPLICATION.EndFrame();
	}

	return 0;
}