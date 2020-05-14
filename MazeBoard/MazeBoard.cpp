#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

#include "Maze.h"
#include "MazeBoard.h"
#include "Robot.h"

MazeBoard::MazeBoard(bool displayDebugInfo) : _startPosition(0, 0), _startDirection( N ),
                                        _robotPosition(0, 0), _robotDirection( N ), cost(0UL),
                                        displayDebugInfo(displayDebugInfo)
{
}

void MazeBoard::reinit()
{
    cost = 0UL;
    _fields.clear();
    _fields.reserve(xSize());
    for (size_t x = 0; x < xSize(); ++x)
    {
        _fields.push_back(std::vector<FieldInfo>());
        _fields[x].reserve(ySize());
        for (size_t y = 0; y < ySize(); ++y)
            _fields[x].push_back(FieldInfo());
    }
    visibleWalls.init(xSize(), ySize());
    setRobotToStartPosition();
}

void MazeBoard::init(size_t const xSize, size_t const ySize, Position const startPosition, Direction const startDirection)
{
    cost = 0UL;
    _fields.clear();
    _fields.reserve(xSize);
    for (size_t x = 0; x < xSize; ++x)
    {
        _fields.push_back(std::vector<FieldInfo>());
        _fields[x].reserve(ySize);
        for (size_t y = 0; y < ySize; ++y)
            _fields[x].push_back(FieldInfo());
    }

    visibleWalls.init(xSize, ySize);
    walls.init(xSize, ySize);

    _startPosition = startPosition;
    _startDirection = startDirection;

    setRobotToStartPosition();
}

void MazeBoard::read(std::string const fileName)
{
    size_t xSize;
    size_t ySize;

    std::fstream fs;
    fs.open(fileName, std::fstream::in);

    fs >> xSize;
    fs >> ySize;

    if (xSize < minMazeXSize || xSize > maxMazeXSize || ySize < minMazeYSize || ySize > maxMazeYSize)
        throw std::runtime_error("Incorrect maze size.");

    size_t xStart;
    size_t yStart;
    Direction startDirection;
    char direction;

    fs >> xStart;
    fs >> yStart;
    fs >> direction;

    if (xStart < (size_t)0 || xStart >= xSize || yStart < 0 || yStart >= ySize)
        throw std::runtime_error("Incorrect robot start field.");

    switch (direction)
    {
    case 'N':
        startDirection = N;
        break;
    case 'S':
        startDirection = S;
        break;
    case 'W':
        startDirection = W;
        break;
    case 'E':
        startDirection = E;
        break;
    default:
        throw std::runtime_error("Incorrect robot start direction.");
    }

    init(xSize, ySize, { xStart, yStart }, startDirection);

    // read vertical walls
    for (size_t y = 0; y < this->ySize(); ++y)
        for (size_t x = 0; x < this->xSize() - 1; ++x)
        {
            int isWall;
            fs >> isWall;
            if (isWall != 0 && isWall != 1)
                throw std::runtime_error( "Incorrect is vertical wall (expected: 0, 1)." );
            if( isWall == 1 )
                walls.setWallE({ x, y });
            //_isVerticalWalls[x][y] = isWall == 1;
        }

    // read horizontal walls
    for (size_t y = 0; y < this->ySize() - 1; ++y)
        for (size_t x = 0; x < this->xSize(); ++x)
        {
            int isWall;
            fs >> isWall;
            if (isWall != 0 && isWall != 1)
                throw std::runtime_error("Incorrect is horizontal wall (expected: 0, 1).");
            if (isWall == 1)
                walls.setWallS({ x, y });
            //_isHorizontalWalls[x][y] = isWall == 1;
        }
    fs.close();

}

void MazeBoard::dispaly(std::ostream & ostream) const
{
    if (!displayDebugInfo)
        return;
    ostream << std::endl;

    // border top
    ostream << "   ";
    for (size_t x = 0; x < xSize(); ++x)
        ostream << " " << std::setw(3) << x;
    ostream << " ";
    ostream << std::endl;
    ostream << "   ";
    for (size_t x = 0; x < xSize(); ++x)
        ostream << "+---";
    ostream << "+";
    ostream << std::endl;

    for (size_t y = 0; y < ySize(); ++y)
    {
        // field row
        ostream << std::setw(3) << y;
        // border left
        ostream << "|";
        for (size_t x = 0; x < xSize(); ++x)
        {
            //field (x,y)
            ostream << (visited({ x,y }) ? "*" : " ");
            if (x == _robotPosition._x && y == _robotPosition._y)
            {
                switch (_robotDirection)
                {
                case N:
                    ostream << "N";
                    break;
                case S:
                    ostream << "S";
                    break;
                case W:
                    ostream << "W";
                    break;
                case E:
                    ostream << "E";
                    break;
                default:
                    throw std::runtime_error("Incorrect direction.");
                }
            }
            else
                ostream << " ";

            ostream << " ";
            // right side wall
            if (x == xSize() - 1 || walls.isWallE({ x,y }))	//  _isVerticalWalls[x][y])
            {
                if (visibleWalls.isWallE({ x,y }))
                    ostream << "#";
                else
                    ostream << "|";
            }
            else
            {
                if (visibleWalls.isWallE({ x,y }))
                    throw std::runtime_error("Wall in invalid position.");
                ostream << " ";
            }
        }
        ostream << std::endl;

        // wall row
        // border left
        ostream << "   +";
        for (size_t x = 0; x < xSize(); ++x)
        {
            // bottom side wall
            if (y == ySize() - 1 || walls.isWallS({ x,y }))  // _isHorizontalWalls[x][y])
            {
                if (visibleWalls.isWallS({ x,y }))
                    ostream << "###";
                else
                    ostream << "---";
            }
            else
            {
                if (visibleWalls.isWallS({ x,y }))
                    throw std::runtime_error("Wall in invalid position.");
                ostream << "   ";
            }
            ostream << "+";
        }
        ostream << std::endl;
    }
    ostream << "Cost:" << cost;
    ostream << std::endl;
}

size_t MazeBoard::xSize() const
{
    return walls.xSize();
}

size_t MazeBoard::ySize() const
{
    return walls.xSize();
}

Position const& MazeBoard::getStartPosition() const
{
    return _startPosition;
}

Direction const& MazeBoard::getStartDirection() const
{
    return _startDirection;
}

void MazeBoard::setRobotToStartPosition()
{
    _robotPosition = _startPosition;
    _robotDirection = _startDirection;
    visit(_robotPosition);
}

void MazeBoard::teleportRobot(Position const& position)
{
    if (position._x < 0 || position._x >= xSize() || position._y < 0 || position._y >= ySize())
        throw std::runtime_error("Invalid move.");
    if (!seen(position))
        throw std::runtime_error("The field was not seen.");
    cost += abs((long)(position._x) - (long)(_robotPosition._x));
    cost += abs((long)(position._y) - (long)(_robotPosition._y));
    _robotPosition = position;
    visit(position);
    dispaly(std::cout);
}

void MazeBoard::moveRobotForward()
{
    ++cost;
    switch (_robotDirection)
    {
    case N:
        moveRobotN();
        break;
    case S:
        moveRobotS();
        break;
    case W:
        moveRobotW();
        break;
    case E:
        moveRobotE();
        break;
    }
    dispaly(std::cout);
}

void MazeBoard::moveRobotBackward()
{
    ++cost;
    switch (_robotDirection)
    {
    case N:
        moveRobotS();
        break;
    case S:
        moveRobotN();
        break;
    case W:
        moveRobotE();
        break;
    case E:
        moveRobotW();
        break;
    }
    dispaly(std::cout);
}

void MazeBoard::turnRobotLeft()
{
    switch (_robotDirection)
    {
    case N:
        _robotDirection = W;
        break;
    case S:
        _robotDirection = E;
        break;
    case W:
        _robotDirection = S;
        break;
    case E:
        _robotDirection = N;
        break;
    }
    //dispaly(std::cout);
}

void MazeBoard::turnRobotRight()
{
    switch (_robotDirection)
    {
    case N:
        _robotDirection = E;
        break;
    case S:
        _robotDirection = W;
        break;
    case W:
        _robotDirection = N;
        break;
    case E:
        _robotDirection = S;
        break;
    }
    //dispaly(std::cout);
}

bool MazeBoard::isWallFront()
{
    switch (_robotDirection)
    {
    case N:
        return isWallN();
    case S:
        return isWallS();
    case W:
        return isWallW();
    case E:
        return isWallE();
    default:
        throw std::exception();
    }
}

bool MazeBoard::isWallBack()
{
    switch (_robotDirection)
    {
    case N:
        return isWallS();
    case S:
        return isWallN();
    case W:
        return isWallE();
    case E:
        return isWallW();
    default:
        throw std::exception();
    }
}

bool MazeBoard::isWallLeft()
{
    switch (_robotDirection)
    {
    case N:
        return isWallW();
    case S:
        return isWallE();
    case W:
        return isWallS();
    case E:
        return isWallN();
    default:
        throw std::exception();
    }
}

bool MazeBoard::isWallRight()
{
    switch (_robotDirection)
    {
    case N:
        return isWallE();
    case S:
        return isWallW();
    case W:
        return isWallN();
    case E:
        return isWallS();
    default:
        throw std::exception();
    }
}

bool MazeBoard::isInExit() const
{
    if ((_robotPosition._x == (xSize() - 1) / 2 || _robotPosition._x == (xSize() - 1) / 2 + 1) &&
            (_robotPosition._y == (ySize() - 1) / 2 || _robotPosition._y == (ySize() - 1) / 2 + 1))
            return true;
        else
            return false;
}

unsigned long MazeBoard::getCost()
{
    return cost;
}

void MazeBoard::moveRobotN()
{
    if (_robotPosition._y <= 0)
        throw std::runtime_error("Invalid move.");
    if (walls.isWallN({ _robotPosition._x, _robotPosition._y }))
        throw std::runtime_error("Invalid move.");
    --_robotPosition._y;
    visit(_robotPosition);
}

void MazeBoard::moveRobotS()
{
    if ((size_t)(_robotPosition._y) >= ySize()-1)
        throw std::runtime_error("Invalid move.");
    if (walls.isWallS({ _robotPosition._x, _robotPosition._y }))
        throw std::runtime_error("Invalid move.");
    ++_robotPosition._y;
    visit(_robotPosition);
}

void MazeBoard::moveRobotW()
{
    if (_robotPosition._x <= 0)
        throw std::runtime_error("Invalid move.");
    if (walls.isWallW({ _robotPosition._x, _robotPosition._y }))
        throw std::runtime_error("Invalid move.");
    --_robotPosition._x;
    visit(_robotPosition);
}

void MazeBoard::moveRobotE()
{
    if ((size_t)(_robotPosition._x) >= xSize() - 1)
        throw std::runtime_error("Invalid move.");
    if (walls.isWallE({ _robotPosition._x, _robotPosition._y }))
        throw std::runtime_error("Invalid move.");
    ++_robotPosition._x;
    visit(_robotPosition);
}

bool MazeBoard::isWallN()
{
    return walls.isWallN({ _robotPosition._x,_robotPosition._y });
}

bool MazeBoard::isWallS()
{
    return walls.isWallS({ _robotPosition._x,_robotPosition._y });
}

bool MazeBoard::isWallW()
{
    return walls.isWallW({ _robotPosition._x,_robotPosition._y });
}

bool MazeBoard::isWallE()
{
    return walls.isWallE({ _robotPosition._x,_robotPosition._y });
}

void MazeBoard::visit(Position const& pos)
{
    _fields[pos._x][pos._y].visited = true;
    _fields[pos._x][pos._y].seen = true;
    if (walls.isWallN(pos))
        visibleWalls.setWallN(pos);
    else
        _fields[pos._x][pos._y - 1].seen = true;
    if (walls.isWallS(pos))
        visibleWalls.setWallS(pos);
    else
        _fields[pos._x][pos._y + 1].seen = true;
    if (walls.isWallW(pos))
        visibleWalls.setWallW(pos);
    else
        _fields[pos._x - 1][pos._y].seen = true;
    if (walls.isWallE(pos))
        visibleWalls.setWallE(pos);
    else
        _fields[pos._x + 1][pos._y].seen = true;
}

bool MazeBoard::visited(Position const& pos) const
{
    return _fields[pos._x][pos._y].visited;
}

bool MazeBoard::seen(Position const& pos) const
{
    return _fields[pos._x][pos._y].seen;
}

bool MazeBoard::isVisibleWallN(Position const& pos) const
{
    return visibleWalls.isWallN(pos);
}

bool MazeBoard::isVisibleWallS(Position const& pos) const
{
    return visibleWalls.isWallS(pos);
}

bool MazeBoard::isVisibleWallW(Position const& pos) const
{
    return visibleWalls.isWallW(pos);
}

bool MazeBoard::isVisibleWallE(Position const& pos) const
{
    return visibleWalls.isWallE(pos);
}
