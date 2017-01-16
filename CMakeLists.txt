cmake_minimum_required(VERSION 2.8)

project(Voronoi)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

find_package(SFML 2.4 COMPONENTS graphics system window)

file(GLOB LIB_SOURCE "src/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SFML_INCLUDE_DIR} include)

add_library(Voronoi ${LIB_SOURCE})

add_executable(SFML_Example "examples/SFML_Example.cpp")
target_link_libraries(SFML_Example ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
debug Debug/Voronoi optimized release/Voronoi)