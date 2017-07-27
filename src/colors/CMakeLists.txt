cmake_minimum_required(VERSION 3.8)

m4(_ colors.h.m4)
m4(prep_files colors.cpp.m4)

add_library(colors ${prep_files})
target_include_directories (colors PUBLIC .)
