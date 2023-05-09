cmake_minimum_required(VERSION 3.9)
project(poly)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)


# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -O0 -fmax-errors=1")
#
# set(sources
#     drawtest_test.cpp
#     main.cpp
# )
#
# add_executable(drawtest ${sources})
#
# add_custom_command(TARGET drawtest 
#   POST_BUILD
#   COMMAND "make")
#
# add_custom_command(TARGET drawtest
#  POST_BUILD
#  COMMAND "drawtest")
  #COMMAND valgrind --tool=memcheck --leak-check=yes ./drawtest)
  #COMMAND valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all ./drawtest)
  #COMMAND valgrind --tool=memcheck --leak-check=yes ./drawtest)


