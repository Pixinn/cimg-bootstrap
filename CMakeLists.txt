cmake_minimum_required(VERSION 3.19)

# Project name - should not contain whitespace 
project(Bootstrap_CIMP)


#========== Global Configurations =============#

set(CMAKE_CXX_STANDARD 14)     
set(CMAKE_VERBOSE_MAKEFILE ON)

#========== Conan Setup =============#

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


#========== Targets Configurations ============#

add_executable(${PROJECT_NAME} src/main.cpp)

# custom definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE cimg_use_png)

# Set executable dependency libraries
conan_set_find_library_paths(${PROJECT_NAME})
conan_target_link_libraries(${PROJECT_NAME})