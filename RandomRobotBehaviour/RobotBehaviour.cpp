#include <cstdlib>
#include <iostream>
#include "RobotBehaviour.h"

RobotBehaviour::RobotBehaviour(size_t const xSize, size_t const ySize, Robot & robot) : RobotBehaviourBase(xSize, ySize, robot), robot(robot)
{
}

void RobotBehaviour::reinit()
{
}

void RobotBehaviour::explore(Position const& startPosition, Direction const& startDirection)
{
	while (!robot.isInExit())
	{
		int availableDirection = 0;
		if (!robot.isWallFront())
			++availableDirection;
		if (!robot.isWallRight())
			++availableDirection;
		if (!robot.isWallBack())
			++availableDirection;
		if (!robot.isWallLeft())
			++availableDirection;

		int direction = rand() % availableDirection;

		if (robot.isWallFront())
			++direction;
		if (robot.isWallRight() && direction > 0)
			++direction;
		if (robot.isWallBack() && direction > 1)
			++direction;
		while (direction > 0)
		{
			robot.turnRight();
			--direction;
		}
		robot.forward();
	}
}

