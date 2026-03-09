cmake_minimum_required(VERSION 3.10)

set(BUILD_TYPE "Debug and Release" CACHE STRING "Choose Build type")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# set the project name
project(FEBasicApplicationExample)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(USE_STATIC_RUNTIME ON CACHE BOOL "Use static runtime (/MT) instead of dynamic (/MD)" FORCE)

if(MSVC)
	# Disable C4251 warning
	add_compile_options(/wd4251)
	
	if(USE_STATIC_RUNTIME)
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	else()
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
	endif()

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif()

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(NOT TARGET FEBasicApplication)
  add_subdirectory(SubSystems/FEBasicApplication)
endif()

file(GLOB source_SRC
	"main.cpp"
)

link_directories(${GLEW_LIB_DIR})
link_directories(${GLFW_LIB_DIR})

# add the executable
add_executable(FEBasicApplicationExample WIN32
								         ${source_SRC}
)

target_link_libraries(FEBasicApplicationExample
	PRIVATE
		FEBasicApplication
)

if(USE_DAWN_WEBGPU)
    target_link_libraries(FEBasicApplicationExample
        PRIVATE
            debug ${DAWN_LIBRARY_DEBUG}
            optimized ${DAWN_LIBRARY_RELEASE}
    )
endif()

source_group("Source Files" FILES ${source_SRC})

# set as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FEBasicApplicationExample)

include_directories(
	${GLEW_INCLUDE_DIR}
	${BASICAPP_THIRDPARTY_DIR}
	$<$<BOOL:${USE_DAWN_WEBGPU}>:${DAWN_INCLUDE_DIR}>
)

if(USE_DAWN_WEBGPU)
	add_custom_command(TARGET FEBasicApplicationExample POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${DAWN_LIB_DIR}$<IF:$<CONFIG:Debug>,Debug,Release>/Dynamic_runtime/"
			"$<TARGET_FILE_DIR:FEBasicApplicationExample>"
	)
endif()