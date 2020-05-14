#pragma once
#include "MazeWalls.h"
class Maze : public MazeWalls
{
public:
	Maze(size_t const xSize, size_t const ySize);
	void setVisited(Position const& position);
	bool isVisited(Position const& position) const;
	void setSeen(Position const& position);
	bool isSeen(Position const& position) const;
private:
	class FieldInfo
	{
	public:
		bool _visited;
		bool _seen;
		FieldInfo();
	};
	std::vector<std::vector<FieldInfo>> _fields;
};

