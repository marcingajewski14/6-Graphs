#pragma once
#include <vector>
#include "Position.h"

class MazeWalls
{
public:
	MazeWalls();
	MazeWalls(size_t const xSize, size_t const ySize);
	void init(size_t const xSize, size_t const ySize);

	size_t xSize() const;
	size_t ySize() const;

	void setWallN(Position const position);
	void setWallS(Position const position);
	void setWallW(Position const position);
	void setWallE(Position const position);

	bool isWallN(Position const position) const;
	bool isWallS(Position const position) const;
	bool isWallW(Position const position) const;
	bool isWallE(Position const position) const;
private:
	std::vector<std::vector<bool>> _verticalWalls;
	std::vector<std::vector<bool>> _horizontalWalls;
};

