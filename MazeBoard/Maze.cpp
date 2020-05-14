#include <stdexcept>
#include "Maze.h"

Maze::Maze(size_t const xSize, size_t const ySize):MazeWalls(xSize, ySize)
{
	_fields.reserve(xSize);
	for (size_t x = 0; x < xSize; ++x)
	{
		_fields.push_back(std::vector<FieldInfo>());
		_fields[x].reserve(ySize);
		for (size_t y = 0; y < ySize; ++y)
			_fields[x].push_back(FieldInfo());
	}
}

void Maze::setVisited(Position const& position)
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	_fields[position._x][position._y]._visited = true;
	_fields[position._x][position._y]._seen = true;
}

bool Maze::isVisited(Position const& position) const
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	return _fields[position._x][position._y]._visited;
}

void Maze::setSeen(Position const& position)
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	_fields[position._x][position._y]._seen = true;
}

bool Maze::isSeen(Position const& position) const
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	return _fields[position._x][position._y]._seen;
}

Maze::FieldInfo::FieldInfo()
{
	_visited = false;
	_seen = false;
}
