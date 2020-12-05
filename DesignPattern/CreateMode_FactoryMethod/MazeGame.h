#pragma once
#include "Maze.h"

class MazeGame {
public:
	MazeGame() {}
	Maze* CreateMaze()
	{
		Maze* aMaze = MakeMaze();

		Room* r1 = MakeRoom(1);
		Room* r2 = MakeRoom(2);
		Door* door = MakeDoor(r1, r2);

		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		// ...

		return aMaze;
	}

	virtual Maze* MakeMaze() const { return new Maze(); }
	virtual Wall* MakeWall() const { return new Wall; }
	virtual Room* MakeRoom(int n) const { return new Room(n); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

// 不同实现
class EnchantedMazeGame : public MazeGame {
public:
	EnchantedMazeGame() {}

	// Differ with Maze Factory
	virtual Room* MakeRoom(int n) const { return new EnhantedRoom(n); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const { return new DoorNeedingSpell(r1, r2); }
};

class BombedMazeGame : public MazeGame {
public:
	BombedMazeGame() {}

	virtual Wall* MakeWall() const { return new BombedWall; }
	virtual Room* MakeRoom(int n) const { return new BombedRoom(n); }
};
