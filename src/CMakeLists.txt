# Author: Debray Arnaud <adebray>
# Date:   2017-07-20T00:01:02+02:00
# Email:  adebray@student.42.fr
# Last modified by:   adebray
# Last modified time: 2017-07-20T00:01:02+02:00

cmake_minimum_required(VERSION 3.8)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

add_subdirectory (demo)
add_subdirectory (../deps/glfw ./glfw)

add_executable (helloworld main.cpp)
target_link_libraries (helloworld LINK_PUBLIC demo "-framework OpenGL" glfw)
