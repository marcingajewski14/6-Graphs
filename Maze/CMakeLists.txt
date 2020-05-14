
set(APP_NAME maze)

set(SRC_LIST
    Maze.cpp
)

add_executable(${APP_NAME} ${SRC_LIST})
target_link_libraries(${APP_NAME} PRIVATE maze_lib)
