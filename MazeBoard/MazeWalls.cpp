#include <stdexcept>
#include "Robot.h"
#include "MazeWalls.h"

MazeWalls::MazeWalls()
{
}

MazeWalls::MazeWalls(size_t xSize, size_t ySize)
{
	init(xSize, ySize);
}

void MazeWalls::init(size_t xSize, size_t ySize)
{
	_verticalWalls.clear();
    if (xSize<minMazeXSize || xSize>maxMazeXSize || ySize<minMazeYSize || ySize>maxMazeYSize)
		throw std::invalid_argument("Invalid maze size");
	_verticalWalls.reserve(xSize - 1);
	for (size_t x = 0; x < xSize - 1; ++x)
	{
		_verticalWalls.push_back(std::vector<bool>());
		_verticalWalls[x].reserve(ySize);
		for (size_t y = 0; y < ySize; ++y)
			_verticalWalls[x].push_back(false);
	}
	_horizontalWalls.clear();
	_horizontalWalls.reserve(xSize);
	for (size_t x = 0; x < xSize; ++x)
	{
		_horizontalWalls.push_back(std::vector<bool>());
		_horizontalWalls[x].reserve(ySize - 1);
		for (size_t y = 0; y < ySize - 1; ++y)
			_horizontalWalls[x].push_back(false);
	}
}

size_t MazeWalls::xSize() const
{
	return size_t(_horizontalWalls.size());
}

size_t MazeWalls::ySize() const
{
	return size_t(_verticalWalls[0].size());
}

void MazeWalls::setWallN(Position const position)
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if(position._y >= (size_t)1)
		_horizontalWalls[position._x][position._y - 1] = true;
}

void MazeWalls::setWallS(Position const position)
{
	if (position._x < 0 || position._x >= xSize() || position._y < 0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if(position._y < ySize() - 1)
		_horizontalWalls[position._x][position._y] = true;
}

void MazeWalls::setWallW(Position const position)
{
	if (position._x < 0 || position._x >= xSize() || position._y < 0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if(position._x >= (size_t)1)
		_verticalWalls[position._x -1][position._y] = true;
}

void MazeWalls::setWallE(Position const position)
{
	if (position._x < 0 || position._x >= xSize() || position._y < 0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if (position._x < xSize() - 1)
		_verticalWalls[position._x][position._y] = true;
}

bool MazeWalls::isWallN(Position const position) const
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if (position._y == 0)
		return true;
	return _horizontalWalls[position._x][position._y - 1];
}
bool MazeWalls::isWallS(Position const position) const
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if (position._y == ySize() - 1)
		return true;
	return _horizontalWalls[position._x][position._y];
}
bool MazeWalls::isWallW(Position const position) const
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if (position._x == 0)
		return true;
	return _verticalWalls[position._x - 1][position._y];
}
bool MazeWalls::isWallE(Position const position) const
{
	if (position._x < (size_t)0 || position._x >= xSize() || position._y < (size_t)0 || position._y >= ySize())
		throw std::invalid_argument("Invalid position.");
	if (position._x == xSize() - 1)
		return true;
	return _verticalWalls[position._x][position._y];
}
