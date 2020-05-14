#pragma once
#include <vector>
#include <string>
#include <ostream>
#include "Maze.h"
#include "Position.h"

class MazeBoard
{
public:
	
	MazeBoard(bool displayDebugInfo);
	void reinit();

	void read( std::string const fileName);
	void dispaly(std::ostream & ostream) const;

	size_t xSize() const;
	size_t ySize() const;
	Position const& getStartPosition() const;
	Direction const& getStartDirection() const;

	void setRobotToStartPosition();


	void teleportRobot(Position const& position);

	void moveRobotForward();
	void moveRobotBackward();
	void turnRobotLeft();
	void turnRobotRight();

	bool isWallFront();
	bool isWallBack();
	bool isWallLeft();
	bool isWallRight();

	bool isInExit() const;

	unsigned long getCost();

private:
	bool displayDebugInfo;
	class FieldInfo
	{
	public:
		bool visited;
		bool seen;
		FieldInfo() : visited(false), seen(false) {}
	};
	std::vector<std::vector<FieldInfo>> _fields;

	MazeWalls visibleWalls;
	MazeWalls walls;

	Position _startPosition;
	Direction _startDirection;

	Position  _robotPosition;
	Direction _robotDirection;
	unsigned long cost;

	void init(size_t const xSize, size_t const ySize, Position const startPosition, Direction const startDirection);

	void moveRobotN();
	void moveRobotS();
	void moveRobotW();
	void moveRobotE();

	bool isWallN();
	bool isWallS();
	bool isWallW();
	bool isWallE();

	void visit(Position const& pos);
	bool visited(Position const& pos) const;
	bool seen(Position const& pos) const;

	bool isVisibleWallN(Position const& pos) const;
	bool isVisibleWallS(Position const& pos) const;
	bool isVisibleWallW(Position const& pos) const;
	bool isVisibleWallE(Position const& pos) const;
};

