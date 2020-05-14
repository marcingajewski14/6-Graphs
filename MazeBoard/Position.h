#pragma once
#include <ostream>

enum Direction { N, S, W, E };

class Position
{
public:
	Position(size_t const x, size_t const y);

	bool operator==(Position const& position)const;

	size_t _x;
	size_t _y;
};

std::ostream& operator<<(std::ostream& stream, Position const& position);