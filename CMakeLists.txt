# Author: Debray Arnaud <adebray>
# Date:   2017-07-20T00:01:02+02:00
# Email:  adebray@student.42.fr
# Last modified by:   adebray
# Last modified time: 2017-07-20T00:01:02+02:00

cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)
set (GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

execute_process(
	COMMAND ./configure
)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory (deps/glfw ./src/glfw)

add_subdirectory (src/gl)

add_executable (helloworld src/main.cpp)
target_link_libraries (helloworld LINK_PUBLIC
  ${OPENGL_gl_LIBRARY}
  glfw
  gl
)
