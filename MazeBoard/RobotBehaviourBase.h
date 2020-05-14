#pragma once
#include "Robot.h"

class RobotBehaviourBase
{
public:
	RobotBehaviourBase(); //dodane
	RobotBehaviourBase(size_t const xSize, size_t const ySize, Robot& robot)
	{
	}
	virtual void reinit() = 0;
	virtual void explore(Position const& startPosition, Direction const & startDirection) = 0;
};

