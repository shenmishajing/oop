cmake_minimum_required(VERSION 3.13)
project(project)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(src DIR_SRCS)

find_package(FLTK)

include_directories(${FLTK_INCLUDE_DIR})

link_libraries(${FLTK_LIBRARIES})

add_executable(project ${DIR_SRCS})