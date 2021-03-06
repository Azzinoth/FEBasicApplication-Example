cmake_minimum_required(VERSION 3.1)

set(BUILD_TYPE "Debug and Release" CACHE STRING "Choose Build type")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# set the project name
project(FEBasicApplication LANGUAGES CXX)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# *************** THIRD_PARTY ***************

file(GLOB imgui_SRC
	"FEBasicApplication/ThirdParty/imgui/imgui.cpp"
	"FEBasicApplication/ThirdParty/imgui/imgui_demo.cpp"
	"FEBasicApplication/ThirdParty/imgui/imgui_draw.cpp"
	"FEBasicApplication/ThirdParty/imgui/imgui_impl_glfw.cpp"
	"FEBasicApplication/ThirdParty/imgui/imgui_impl_opengl3.cpp"
	"FEBasicApplication/ThirdParty/imgui/imgui_tables.cpp"
	"FEBasicApplication/ThirdParty/imgui/imgui_widgets.cpp"
)

file(GLOB BasicApplicationSubSystem_SRC
	"FEBasicApplication/FEBasicApplication.cpp"
	"FEBasicApplication/FEBasicApplication.h"
	"FEBasicApplication/FEThreadPool.cpp"
	"FEBasicApplication/FEThreadPool.h"
	"FEBasicApplication/FETime.cpp"
	"FEBasicApplication/FETime.h"
)

file(GLOB source_SRC
	"main.cpp"
)

link_directories("FEBasicApplication/ThirdParty/glew2/lib/$(PlatformTarget)")
link_directories("FEBasicApplication/ThirdParty/GLFW/lib/$(PlatformTarget)")

# add the executable
add_executable(FEBasicApplication WIN32
								  ${source_SRC}
								  ${BasicApplicationSubSystem_SRC}
								  # *************** THIRD_PARTY ***************
								  ${imgui_SRC}
)

target_link_libraries(FEBasicApplication glew32.lib)
target_link_libraries(FEBasicApplication glfw3.lib)
target_link_libraries(FEBasicApplication glfw3dll.lib)
target_link_libraries(FEBasicApplication opengl32.lib)

source_group("Source Files" FILES ${source_SRC})
source_group("Source Files/SubSystems/BasicApplication" FILES ${BasicApplicationSubSystem_SRC})
# *************** THIRD_PARTY ***************
source_group("Source Files/ThirdParty/imgui" FILES ${imgui_SRC})

# set FEBasicApplication as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FEBasicApplication)

include_directories(
	"FEBasicApplication/ThirdParty/glew2/include"
	"FEBasicApplication/ThirdParty/"
)