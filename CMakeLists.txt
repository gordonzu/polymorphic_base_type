project(drawtest)
cmake_minimum_required(VERSION 2.6)

include_directories(                    
		            "$ENV{GMOCK_INC}"
                    "$ENV{GTEST_INC}"
                    "${CMAKE_CURRENT_SOURCE_DIR}/src"
		           )

link_directories(
		        "$ENV{GMOCK_LIB}"
                "$ENV{GTEST_LIB}"
		        )

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -std=c++17 -g -Wall -O3")

set(sources
  main.cpp
  drawtest_test.cpp
  )

add_executable(drawtest ${sources})
target_link_libraries(drawtest gmock)
target_link_libraries(drawtest gtest)
target_link_libraries(drawtest pthread)

add_custom_command(TARGET drawtest
                   POST_BUILD
                   COMMAND "make")

add_custom_command(TARGET drawtest
                   POST_BUILD
#                  COMMAND valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all ./drawtest)
#		           COMMAND valgrind --tool=memcheck --leak-check=yes ./drawtest)
                   COMMAND "drawtest")

