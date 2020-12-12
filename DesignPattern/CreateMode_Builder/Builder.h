#pragma once

#include "Maze.h"

class MazeBuilder
{
public:
	virtual void BuildeMaze() { }
	virtual void BuildeRoom(int n) { }
	virtual void BuildeDoor(int r1, int r2) {  }

	virtual Maze* GetMaze() { return nullptr; }

protected:
	MazeBuilder() {}
};

class MazeBuilderStandard : public MazeBuilder
{
public:
	virtual void BuildeMaze() {
		_currentMaze = new Maze;
	}

	virtual Maze* GetMaze() { return _currentMaze; }

	virtual void BuildeRoom(int n) {
		if (!_currentMaze->RoomNo(n))
		{
			Room* newRoom = new Room(n);
			_currentMaze->AddRoom(newRoom);

			// 设置room的属性
		}
	}
	virtual void BuildeDoor(int n1, int n2) {
		Room* r1 = _currentMaze->RoomNo(n1);
		Room* r2 = _currentMaze->RoomNo(n2);
		Door* d = new Door(r1, r2);

		// 设置room的属性
	}

public:
	MazeBuilderStandard() { 
		_currentMaze = 0;
	}

	Maze* _currentMaze;
};


