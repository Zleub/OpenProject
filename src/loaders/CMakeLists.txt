file(GLOB FILES "src/*.cpp")
add_library (loaders SHARED ${FILES})

target_include_directories (loaders PUBLIC
  inc ../colors
)
