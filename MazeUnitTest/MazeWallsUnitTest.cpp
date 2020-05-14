#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <functional>

#include "MazeBoard/MazeWalls.h"
#include "MazeBoard/Robot.h"


TEST_CASE("ConstructorInitialize0rowsMazeThrowException")
{
    std::function<void(void)> f1 = [] { MazeWalls mazeWalls(0, 16); };
    REQUIRE_THROWS_AS(f1(), std::invalid_argument);
}

TEST_CASE("ConstructorInitialize0columnsMazeThrowException")
{
    std::function<void(void)> f1 = [] { MazeWalls mazeWalls(16, 0); };
    REQUIRE_THROWS_AS(f1(), std::invalid_argument);
}
TEST_CASE("SizeForMinimalMaze")
{
    MazeWalls maze(minMazeXSize, minMazeYSize);
    REQUIRE(maze.xSize() == minMazeXSize);
    REQUIRE(maze.ySize() == minMazeYSize);
}
TEST_CASE("SizeForMaximalMaze")
{
    MazeWalls maze(maxMazeXSize, maxMazeYSize);
    REQUIRE(maze.xSize() == maxMazeXSize);
    REQUIRE(maze.ySize() == maxMazeYSize);
}
TEST_CASE("SizeForMiddleMaze")
{
    MazeWalls maze(4, 7);
    REQUIRE(maze.xSize() == (size_t)4);
    REQUIRE(maze.ySize() == (size_t)7);
}

//TEST_CASE(SetNWallForFirstRowFirstColumnThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallN({ 0, 0 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}
//TEST_CASE(SetNWallForFirstRowMiddleColumnThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallN({ 3, 0 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}
//TEST_CASE(SetNWallForFirstRowLastColumnThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallN({ 5, 0 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}

TEST_CASE("SetAndCheckNWallForSecondRowFirstColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 0,1 });
    REQUIRE(mazeWalls.isWallN({ 0, 1 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 0 && y != 1)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}
TEST_CASE("SetAndCheckNWallForSecondRowMiddleColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 4, 1 });
    REQUIRE(mazeWalls.isWallN({ 4, 1 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 4 && y != 1)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}
TEST_CASE("SetAndCheckNWallForSecondRowLastColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 5, 1 });
    REQUIRE(mazeWalls.isWallN({ 5, 1 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 5 && y != 1)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}

TEST_CASE("SetAndCheckNWallMiddleRowFirstColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 0, 4 });
    REQUIRE(mazeWalls.isWallN({ 0, 4 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 0 && y != 4)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}
TEST_CASE("SetAndCheckNWallMiddleRowMiddleColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 2, 3 });
    REQUIRE(mazeWalls.isWallN({ 2, 3 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 2 && y != 3)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}
TEST_CASE("SetAndCheckNWallMiddleRowLastColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 5, 6 });
    REQUIRE(mazeWalls.isWallN({ 5, 6 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 5 && y != 6)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}

TEST_CASE("SetAndCheckNWallForLastRowFirstColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 0, 7 });
    REQUIRE(mazeWalls.isWallN({ 0, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 0 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}
TEST_CASE("SetAndCheckNWallForLastRowMiddleColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 3, 7 });
    REQUIRE(mazeWalls.isWallN({ 3, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 3 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}
TEST_CASE("SetAndCheckNWallForLastRowLastColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallN({ 5, 7 });
    REQUIRE(mazeWalls.isWallN({ 5, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 0)
                REQUIRE(mazeWalls.isWallN({ x, y }));
            else
                if (x != 5 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallN({ x, y }));
}


//TEST_CASE(SetSWallForlastRowFirstColumnThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallS({ 0, 7 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}
//TEST_CASE(SetSWallForLastRowMiddleColumnThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallS({ 3, 7 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}
//TEST_CASE(SetSWallForLastRowLastColumnThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallS({ 5, 7 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}

TEST_CASE("SetAndCheckSWallForOneBeforeLastRowFirstColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 0, 6 });
    REQUIRE(mazeWalls.isWallS({ 0, 6 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 0 && y != 6)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}
TEST_CASE("SetAndCheckSWallForOneBeforeLastRowMiddleColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 4, 6 });
    REQUIRE(mazeWalls.isWallS({ 4, 6 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 4 && y != 6)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}
TEST_CASE("SetAndCheckSWallForOneBeforeLastRowLastColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 5, 6 });
    REQUIRE(mazeWalls.isWallS({ 5, 6 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 5 && y != 6)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}

TEST_CASE("SetAndCheckSWallMiddleRowFirstColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 0, 4 });
    REQUIRE(mazeWalls.isWallS({ 0, 4 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 0 && y != 4)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}
TEST_CASE("SetAndCheckSWallMiddleRowMiddleColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 2, 3 });
    REQUIRE(mazeWalls.isWallS({ 2, 3 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 2 && y != 3)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}
TEST_CASE("SetAndCheckSWallMiddleRowLastColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 5, 4 });
    REQUIRE(mazeWalls.isWallS({ 5, 4 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 5 && y != 4)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}

TEST_CASE("SetAndCheckSWallForFirstRowFirstColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 0, 0 });
    REQUIRE(mazeWalls.isWallS({ 0, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 0 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}
TEST_CASE("SetAndCheckSWallForFirstRowMiddleColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 3, 0 });
    REQUIRE(mazeWalls.isWallS({ 3, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 3 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}
TEST_CASE("SetAndCheckSWallForFirstRowLastColumn")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallS({ 5, 0 });
    REQUIRE(mazeWalls.isWallS({ 5, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (y == 7)
                REQUIRE(mazeWalls.isWallS({ x, y }));
            else
                if (x != 5 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallS({ x, y }));
}


//TEST_CASE(SetWWallForFirstColumnFirstRowThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallW({ 0, 0 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}
//TEST_CASE(SetWWallForFirstColumnMiddleRowThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallW({ 0, 4 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}
//TEST_CASE(SetWWallForFirstColumnLastRowThrowException)
//{
//	MazeWalls mazeWalls(6, 8);
//	std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallW({ 0, 7 }); };
//	Assert::ExpectException<std::invalid_argument>(f1);
//}

TEST_CASE("SetAndCheckWWallForSecondColumnFirstRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 1, 0 });
    REQUIRE(mazeWalls.isWallW({ 1, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 1 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}
TEST_CASE("SetAndCheckWWallForSecondColumnMiddleRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 1, 4 });
    REQUIRE(mazeWalls.isWallW({ 1, 4 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 1 && y != 4)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}
TEST_CASE("SetAndCheckWWallForSecondColumnLastRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 1, 7 });
    REQUIRE(mazeWalls.isWallW({ 1, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 1 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}

TEST_CASE("SetAndCheckWWallMiddlecolumnFirstRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 3, 0 });
    REQUIRE(mazeWalls.isWallW({ 3, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 3 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}
TEST_CASE("SetAndCheckWWallMiddleColumnMiddleRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 2, 3 });
    REQUIRE(mazeWalls.isWallW({ 2, 3 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 2 && y != 3)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}
TEST_CASE("SetAndCheckWWallMiddleColumnLastRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 2, 7 });
    REQUIRE(mazeWalls.isWallW({ 2, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 2 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}

TEST_CASE("SetAndCheckWWallForLastColumnFirstRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 5, 0 });
    REQUIRE(mazeWalls.isWallW({ 5, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 5 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}
TEST_CASE("SetAndCheckWWallForLastColumnMiddleRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 5, 4 });
    REQUIRE(mazeWalls.isWallW({ 5, 4 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 5 && y != 4)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}
TEST_CASE("SetAndCheckWWallForLastColumnLastRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallW({ 5, 7 });
    REQUIRE(mazeWalls.isWallW({ 5, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 0)
                REQUIRE(mazeWalls.isWallW({ x, y }));
            else
                if (x != 5 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallW({ x, y }));
}




/*TEST_CASE(SetEWallForLastColumnFirstRowThrowException)
{
    MazeWalls mazeWalls(6, 8);
    std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallE({ 5, 0 }); };
    Assert::ExpectException<std::invalid_argument>(f1);
}
TEST_CASE(SetEWallForLastColumnMiddleRowThrowException)
{
    MazeWalls mazeWalls(6, 8);
    std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallE({ 5, 3 }); };
    Assert::ExpectException<std::invalid_argument>(f1);
}
TEST_CASE(SetEWallForLastColumnLastRowThrowException)
{
    MazeWalls mazeWalls(6, 8);
    std::function<void(void)> f1 = [&mazeWalls] { mazeWalls.setWallE({ 5, 7 }); };
    Assert::ExpectException<std::invalid_argument>(f1);
}*/

TEST_CASE("SetAndCheckEWallForOneBeforeLastColumnFirstRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 4, 0 });
    REQUIRE(mazeWalls.isWallE({ 4, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 4 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
TEST_CASE("SetAndCheckEWallForOneBeforeLastColumnMiddleRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 4, 3 });
    REQUIRE(mazeWalls.isWallE({ 4, 3 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 4 && y != 3)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
TEST_CASE("SetAndCheckEWallForOneBeforeLastColumnLastRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 4, 7 });
    REQUIRE(mazeWalls.isWallE({ 4, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 4 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}

TEST_CASE("SetAndCheckEWallMiddleColumnFirstRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 3, 0 });
    REQUIRE(mazeWalls.isWallE({ 3, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 3 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
TEST_CASE("SetAndCheckEWallMiddleColumnMiddleRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 2, 3 });
    REQUIRE(mazeWalls.isWallE({ 2, 3 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 2 && y != 3)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
TEST_CASE("SetAndCheckEWallMiddleColumnLastRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 2, 7 });
    REQUIRE(mazeWalls.isWallE({ 2, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 2 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}

TEST_CASE("SetAndCheckEWallForFirstColumnFirstRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 0, 0 });
    REQUIRE(mazeWalls.isWallE({ 0, 0 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 0 && y != 0)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
TEST_CASE("SetAndCheckEWallForFirstColumnMiddleRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 0, 4 });
    REQUIRE(mazeWalls.isWallE({ 0, 4 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 0 && y != 4)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
TEST_CASE("SetAndCheckEWallForFirstColumnLastRow")
{
    MazeWalls mazeWalls(6, 8);
    mazeWalls.setWallE({ 0, 7 });
    REQUIRE(mazeWalls.isWallE({ 0, 7 }));
    for (size_t x = 0; x < mazeWalls.xSize(); ++x)
        for (size_t y = 0; y < mazeWalls.ySize(); ++y)
            if (x == 5)
                REQUIRE(mazeWalls.isWallE({ x, y }));
            else
                if (x != 0 && y != 7)
                    REQUIRE_FALSE(mazeWalls.isWallE({ x, y }));
}
