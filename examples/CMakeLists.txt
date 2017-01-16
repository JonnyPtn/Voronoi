cmake_minimum_required(VERSION 2.8)

project(sfvoronoi_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake/modules")

find_package(SFML 2.4 COMPONENTS graphics system window)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SFML_INCLUDE_DIR} ../include)

add_executable(sfvoronoi_example SFML_Example.cpp)

include(FindPackageHandleStandardArgs)

# Search for the library
find_library(LIBRARY NAMES voronoi PATHS "${PROJECT_SOURCE_DIR}/../" PATH_SUFFIXES lib bin)

# Did we find everything we need?
FIND_PACKAGE_HANDLE_STANDARD_ARGS(voronoi DEFAULT_MSG LIBRARY)

target_link_libraries(sfvoronoi_example ${LIBRARY} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})