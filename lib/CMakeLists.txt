add_subdirectory(googletest)
file(GLOB_RECURSE GNUPlot LIST_DIRECTORIES false gplotpp/*.h gplotpp/*.cpp)
add_library(GNUPlot_lib STATIC ${GNUPlot})