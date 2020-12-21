#pragma once
#include "Maze.h"

class MazeFactory {
public:
	virtual Maze* MakeMaze() const { return new Maze(); }
	virtual Wall* MakeWall() const { return new Wall; }
	virtual Room* MakeRoom(int n) const { return new Room(n); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

class MazeFactoryPrototype : public MazeFactory
{
public:
	MazeFactoryPrototype(Maze* maze, Wall* wall, Room* room, Door* door) 
		: _prototypeMaze(maze)
		, _prototypeRoom(room)
		, _prototypeWall(wall)
		, _prototypeDoor(door)
	{
	}

	virtual Maze* MakeMaze() const { return _prototypeMaze->clone(); }
	virtual Wall* MakeWall() const { return _prototypeWall->clone(); }
	virtual Room* MakeRoom(int n) const { return _prototypeRoom->clone(); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const { return _prototypeDoor->clone(); }
private:
	Maze* _prototypeMaze;
	Room* _prototypeRoom;
	Wall* _prototypeWall;
	Door* _prototypeDoor;
};

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

		return aMaze->clone();
	}


};
