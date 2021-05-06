cmake_minimum_required(VERSION 3.16)
project(Rotation)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_run)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/gplotpp)

add_subdirectory(lib/googletest)
add_subdirectory(test)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true include/*.h source/*.cpp)

add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})