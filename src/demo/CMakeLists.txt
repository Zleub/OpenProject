#Author: Debray Arnaud <adebray>
#Date:   2017-07-19T23:49:04+02:00
#Email:  adebray@student.42.fr
#Last modified by:   adebray
#Last modified time: 2017-07-19T23:49:31+02:00

add_library (demo src/demo.cpp)
target_include_directories (demo PUBLIC
  inc
  ../../deps/glfw/include
)
