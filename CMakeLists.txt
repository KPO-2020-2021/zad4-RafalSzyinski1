cmake_minimum_required(VERSION 3.17)
project(Rotation)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_run)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
add_subdirectory(test)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true include/*.h source/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/gplotpp)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
target_link_libraries(${EXECUTABLE} PRIVATE GNUPlot_lib)