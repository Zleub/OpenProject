# Author: Debray Arnaud <adebray>
# Date:   2017-07-20T00:01:02+02:00
# Email:  adebray@student.42.fr
# Last modified by:   adebray
# Last modified time: 2017-07-20T00:01:02+02:00

cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)
set (GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

function(m4 out_var)
	set(result)
	foreach(in_f ${ARGN})
		string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${in_f})
		set(striped ${CMAKE_MATCH_1})
		set(in "${CMAKE_CURRENT_BINARY_DIR}/${in_f}")
		set(out "${CMAKE_CURRENT_BINARY_DIR}/${striped}")
		execute_process(
			OUTPUT_FILE ${out}
			INPUT_FILE ${in}
			COMMAND m4
		)
		list(APPEND result ${out})
	endforeach()
	set(${out_var} "${result}" PARENT_SCOPE)
endfunction()

execute_process( COMMAND ./configure )

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory (deps/glfw ./src/glfw)
add_subdirectory (deps/glm ./src/glm)

add_subdirectory (src/gl)
add_subdirectory (src/colors)

add_executable (helloworld src/demo/helloworld.cpp)
target_link_libraries (helloworld LINK_PUBLIC
	${OPENGL_gl_LIBRARY} glfw glm
	gl colors
)

add_executable (opt src/demo/opt.cpp)
target_link_libraries(opt glm)
