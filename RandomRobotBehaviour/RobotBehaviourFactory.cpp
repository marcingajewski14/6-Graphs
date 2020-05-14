#include "MazeBoard/RobotBehaviourFactory.h"
#include "MazeBoard/Robot.h"
#include "MazeBoard/RobotBehaviourBase.h"
#include "RobotBehaviour.h"
#include <memory>

std::unique_ptr<RobotBehaviourBase> RobotBehaviourFactory::create(size_t const xSize, size_t const ySize, Robot& robot)
{
	return std::make_unique<RobotBehaviour>(xSize, ySize, robot);
}
