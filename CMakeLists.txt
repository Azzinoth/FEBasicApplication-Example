cmake_minimum_required(VERSION 3.1)

set(BUILD_TYPE "Debug and Release" CACHE STRING "Choose Build type")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# set the project name
project(FEBasicApplicationExample LANGUAGES CXX)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(FEBasicApplication)

file(GLOB source_SRC
	"main.cpp"
)

link_directories("FEBasicApplication/ThirdParty/glew2/lib/$(PlatformTarget)")
link_directories("FEBasicApplication/ThirdParty/GLFW/lib/$(PlatformTarget)")

# add the executable
add_executable(FEBasicApplicationExample WIN32
								         ${source_SRC}
)

target_link_libraries(FEBasicApplicationExample FEBasicApplication)

target_link_libraries(FEBasicApplicationExample glew32s.lib)
target_link_libraries(FEBasicApplicationExample glfw3.lib)
target_link_libraries(FEBasicApplicationExample glfw3dll.lib)
target_link_libraries(FEBasicApplicationExample opengl32.lib)

source_group("Source Files" FILES ${source_SRC})

# set as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FEBasicApplicationExample)

include_directories(
	"FEBasicApplication/ThirdParty/glew2/include"
	"FEBasicApplication/ThirdParty/"
)