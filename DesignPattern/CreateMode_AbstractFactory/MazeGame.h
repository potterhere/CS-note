#pragma once
#include "Maze.h"
#include "MazeFactory.h"

class MazeGame {
public:
	MazeGame() {}
	Maze* CreateMaze(MazeFactory* factory)
	{
		Maze* aMaze = factory->MakeMaze();

		Room* r1 = factory->MakeRoom(1);
		Room* r2 = factory->MakeRoom(2);
		Door* door = factory->MakeDoor(r1, r2);

		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		// ...

		return aMaze;
	}
};
