#pragma once
#include "Maze.h"
#include "Builder.h"

class MazeGame {
public:
	MazeGame() {}
	Maze* CreateMaze(MazeBuilder& builder)
	{
		builder.BuildeMaze();

		builder.BuildeRoom(1);
		builder.BuildeRoom(2);
		builder.BuildeDoor(1, 2);

		return builder.GetMaze();
	}
};
