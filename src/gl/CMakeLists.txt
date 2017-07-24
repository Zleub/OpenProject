file(GLOB FILES "src/*.cpp")
add_library (gl ${FILES})

target_include_directories (gl PUBLIC
  inc
  ../../deps/glfw/include
)
