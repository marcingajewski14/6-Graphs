#pragma once
#include "Robot.h"
#include "RobotBehaviourBase.h"
#include "MazeBoard.h"
#include "RobotBehaviourFactory.h"

#include <memory>

class RobotSim : public Robot
{
public:
    RobotSim(MazeBoard& mazeBoard, RobotBehaviourFactory & robotBehaviourFactory);

    void reinit();

    virtual void teleport(Position const& position) override;
    virtual void forward() override;
    virtual void backward() override;
    virtual void turnLeft() override;
    virtual void turnRight() override;

    virtual bool isWallFront() const override;
    virtual bool isWallBack() const override;
    virtual bool isWallLeft() const override;
    virtual bool isWallRight() const override;

    virtual bool isInExit() const override;

    bool explore();
private:
    MazeBoard & _mazeBoard;

    std::unique_ptr<RobotBehaviourBase> robot;
};

