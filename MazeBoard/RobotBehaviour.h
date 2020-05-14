#include "RobotBehaviourBase.h"
#include "Robot.h"
#include "Position.h"
#include "Maze.h"

class RobotBehaviour:public RobotBehaviourBase{

public:
    static int const distanceToExitFactor=10;
    static int const teleportationFactor=10;

    RobotBehaviour(size_t const xSize, size_t const ySize, Robot &robot){};

    void reinit();

    bool explore(Position const& startPosition, Direction const &startDirection);

    private:

    Robot _robot;

    //M
    class FieldInfo{

        Position _position;
        int _routeCost;
        int _previousField;

    };    ///tu coś cwaniak schował

    Position _startPosition;
    Direction _startDirection;
    Position _robotPosition;
    Direction _robotDirection;

    void forwardAndUpdate();
    void turnLeftAndUpdate();
    void turnRightAndUpdate();
    std::vector<FieldInfo> _fields;
    int findField(Position const& position) const;
    int findNextField() const;

    void processField(int const previousFieldIndex, Position const& fieldPosition);
    int distanceToExit(Position const& position) const;

    void setVisitedAndLookAround();
    void moveTo(Position const& newPosition);

    Maze _maze=new Maze(xSize,ySize);

}
