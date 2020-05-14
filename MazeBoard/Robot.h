#pragma once
#include "Position.h"

static size_t const minMazeXSize = 2;
static size_t const minMazeYSize = 2;
static size_t const maxMazeXSize = 256;
static size_t const maxMazeYSize = 256;

class Robot
{
public:

    virtual void teleport(Position const& position) = 0;

	virtual void forward() = 0;
	virtual void backward() = 0;
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;

	virtual bool isWallFront() const = 0;
	virtual bool isWallBack() const = 0;
	virtual bool isWallLeft() const = 0;
	virtual bool isWallRight() const = 0;

	virtual bool isInExit() const = 0;
};
