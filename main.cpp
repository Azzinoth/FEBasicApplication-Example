#include "SubSystems/FEBasicApplication/FEBasicApplication.h"
using namespace FocalEngine;

void MainWindowRender()
{
	ImGui::ShowDemoWindow();
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
	APPLICATION.AddWindow(1280, 720, "FEBasicApplication example");
	APPLICATION.GetWindow(0)->SetClearColor(0.6f, 0.85f, 0.917f, 1.0f);
	APPLICATION.GetWindow(0)->SetRenderFunction(MainWindowRender);

	APPLICATION.Run([]() {
		APPLICATION.BeginFrame();
		APPLICATION.RenderWindows();
		APPLICATION.EndFrame();
	});

	return 0;
}