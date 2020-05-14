#include "RobotSim.h"
#include "MazeBoard.h"

RobotSim::RobotSim(MazeBoard& mazeBoard, RobotBehaviourFactory & robotBehaviourFactory) : _mazeBoard(mazeBoard),
robot(robotBehaviourFactory.create(mazeBoard.xSize(), mazeBoard.ySize(), *this))
{
}

void RobotSim::reinit()
{
	_mazeBoard.setRobotToStartPosition();
	robot->reinit();
}

void RobotSim::teleport(Position const& position)
{
	_mazeBoard.teleportRobot(position);
}

void RobotSim::forward()
{
	_mazeBoard.moveRobotForward();
}

void RobotSim::backward()
{
	_mazeBoard.moveRobotBackward();
}

void RobotSim::turnLeft()
{
	_mazeBoard.turnRobotLeft();
}

void RobotSim::turnRight()
{
	_mazeBoard.turnRobotRight();
}

bool RobotSim::isWallFront() const
{
	return _mazeBoard.isWallFront();
}

bool RobotSim::isWallBack() const
{
	return _mazeBoard.isWallBack();
}

bool RobotSim::isWallLeft() const
{
	return _mazeBoard.isWallLeft();
}

bool RobotSim::isWallRight() const
{
	return _mazeBoard.isWallRight();
}

bool RobotSim::isInExit() const
{
	return _mazeBoard.isInExit();
}

bool RobotSim::explore()
{
	robot->explore(_mazeBoard.getStartPosition(), _mazeBoard.getStartDirection());
	return _mazeBoard.isInExit();
}
