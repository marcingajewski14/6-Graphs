#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <functional>

#include "MazeBoard/Maze.h"
#include "MazeBoard/Robot.h"

TEST_CASE("ConstructorInitialize0rowsMazeThrowException")
{
    std::function<void(void)> f1 = [] { Maze maze(0, 16); };
    REQUIRE_THROWS_AS(f1(), std::invalid_argument);
}

TEST_CASE("ConstructorInitialize0columnsMazeThrowException")
{
    std::function<void(void)> f1 = [] { Maze maze(16, 0); };
    REQUIRE_THROWS_AS(f1(), std::invalid_argument);
}
TEST_CASE("SizeForMinimalMaze")
{
    Maze maze(minMazeXSize, minMazeYSize);
    REQUIRE(maze.xSize() == minMazeXSize);
    REQUIRE(maze.ySize() == minMazeYSize);
}
TEST_CASE("SizeForMaximalMaze")
{
    Maze maze(maxMazeXSize, maxMazeYSize);
    REQUIRE(maze.xSize() == maxMazeXSize);
    REQUIRE(maze.ySize() == maxMazeYSize);
}
TEST_CASE("SizeForMiddleMaze")
{
    Maze maze(4, 7);
    REQUIRE(maze.xSize() == (size_t)4);
    REQUIRE(maze.ySize() == (size_t)7);
}

TEST_CASE("SetAndCheckVisitedForFirstRowFirstColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 0,0 });
    REQUIRE(maze.isVisited({ 0, 0 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 0 && y != 0)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
TEST_CASE("SetAndCheckVisitedForSecondRowMiddleColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 4, 1 });
    REQUIRE(maze.isVisited({ 4, 1 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 4 && y != 1)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
TEST_CASE("SetAndCheckVisitedForSecondRowLastColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 5, 1 });
    REQUIRE(maze.isVisited({ 5, 1 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 5 && y != 1)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}

TEST_CASE("SetAndCheckNWallMiddleRowFirstColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 0, 4 });
    REQUIRE(maze.isVisited({ 0, 4 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 0 && y != 4)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
TEST_CASE("SetAndCheckNWallMiddleRowMiddleColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 2, 3 });
    REQUIRE(maze.isVisited({ 2, 3 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 2 && y != 3)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
TEST_CASE("SetAndCheckNWallMiddleRowLastColumn")
{
    Maze mazeWalls(6, 8);
    mazeWalls.setVisited({ 5, 6 });
    REQUIRE(mazeWalls.isVisited({ 5, 6 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x != 5 && y != 6)
                REQUIRE_FALSE(mazeWalls.isVisited({ x, y }));
}

TEST_CASE("SetAndCheckVisitedForLastRowFirstColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 0, 7 });
    REQUIRE(maze.isVisited({ 0, 7 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 0 && y != 7)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
TEST_CASE("SetAndCheckVisitedForLastRowMiddleColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 3, 7 });
    REQUIRE(maze.isVisited({ 3, 7 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 3 && y != 7)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
TEST_CASE("SetAndCheckVisitedForLastRowLastColumn")
{
    Maze maze(6, 8);
    maze.setVisited({ 5, 7 });
    REQUIRE(maze.isVisited({ 5, 7 }));
    for (size_t x = 0; x < maze.xSize(); ++x)
        for (size_t y = 0; y < maze.ySize(); ++y)
            if (x != 5 && y != 7)
                REQUIRE_FALSE(maze.isVisited({ x, y }));
}
