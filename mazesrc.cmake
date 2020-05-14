
set(MAZE_LIB_NAME maze_lib)

set(SRC_LIST
    RandomRobotBehaviour/RobotBehaviour.cpp
    RandomRobotBehaviour/RobotBehaviourFactory.cpp
    RandomRobotBehaviour/RobotBehaviour.h

    MazeBoard/MazeWalls.h
    MazeBoard/RobotSim.h
    MazeBoard/RobotBehaviourBase.h
    MazeBoard/MazeWalls.cpp
    MazeBoard/RobotSim.cpp
    MazeBoard/Maze.h
    MazeBoard/Maze.cpp
    MazeBoard/RobotBehaviour.h
    MazeBoard/RobotBehaviour.cpp
    MazeBoard/RobotBehaviourFactory.h
    MazeBoard/RobotBehaviourFactory.cpp
    MazeBoard/Robot.h
    MazeBoard/Position.h
    MazeBoard/MazeBoard.cpp
    MazeBoard/MazeBoard.h
    MazeBoard/Position.cpp
)

add_library(${MAZE_LIB_NAME} ${SRC_LIST})

target_include_directories(${MAZE_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

