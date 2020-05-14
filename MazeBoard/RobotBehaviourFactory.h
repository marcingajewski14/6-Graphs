#pragma once
#include "RobotBehaviourBase.h"
#include "Robot.h"
#include "RobotBehaviour.h"

#include <memory>

class RobotBehaviourFactory
{
public:
    std::unique_ptr<RobotBehaviourBase>  create(size_t const xSize, size_t const ySize, Robot& robot);
};

