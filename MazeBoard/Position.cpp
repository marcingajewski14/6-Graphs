#include <ostream>
#include "Position.h"

Position::Position(size_t const x, size_t const y)
{
	_x = x;
	_y = y;
}

bool Position::operator==(Position const& position)const
{
	return _x == position._x && _y == position._y;
}

std::ostream& operator<<(std::ostream & stream, Position const& position)
{
	stream << "(" << position._x << "," << position._y << ")";
	return stream;
}