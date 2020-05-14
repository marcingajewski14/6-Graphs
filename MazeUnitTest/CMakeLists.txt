
set(TEST_TARGET1 maze_tests)

set(SRC_LIST 
    MazeUnitTest.cpp
)

add_executable(${TEST_TARGET1} ${SRC_LIST})
target_link_libraries(${TEST_TARGET1} PRIVATE maze_lib Catch2::Catch)
add_test(NAME mazetest COMMAND ${TEST_TARGET1})

#########################################################3

set(TEST_TARGET2 maze_walls_tests)

set(SRC_LIST
    MazeWallsUnitTest.cpp
)

add_executable(${TEST_TARGET2} ${SRC_LIST})
target_link_libraries(${TEST_TARGET2} PRIVATE maze_lib Catch2::Catch)
add_test(NAME mazewallstest COMMAND ${TEST_TARGET2})
