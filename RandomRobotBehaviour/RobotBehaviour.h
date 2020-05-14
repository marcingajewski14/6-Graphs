#pragma once
#include "MazeBoard/RobotBehaviourBase.h"
#include "MazeBoard/Robot.h"
#include "MazeBoard/Position.h"
#include "MazeBoard/Maze.h"

class RobotBehaviour : public RobotBehaviourBase
{
public:
	RobotBehaviour(size_t const xSize, size_t const ySize, Robot & robot);

	virtual void reinit() override;

	virtual void explore(Position const& startPosition, Direction const & startDirection) override;
	
private:
	Robot & robot;
};

