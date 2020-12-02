#pragma once

#include "Maze.h"

/////////////////////////////////////////////////////////////////
// 核心抽象
class MazeFactory {
public:
    MazeFactory() {}

    virtual Maze* MakeMaze() const { return new Maze(); }
    virtual Wall* MakeWall() const { return new Wall; }
    virtual Room* MakeRoom(int n) const { return new Room(n); }
    virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

// 不同实现
class EnchantedMazeFactory : public MazeFactory {
public:
    EnchantedMazeFactory() {}

    // Differ with Maze Factory
    virtual Room* MakeRoom(int n) const { return new EnhantedRoom(n); }
    virtual Door* MakeDoor(Room* r1, Room* r2) const { return new DoorNeedingSpell(r1, r2); }
};

class BombedMazeFactory : public MazeFactory {
public:
    BombedMazeFactory() {}

    virtual Wall* MakeWall() const { return new BombedWall; }
    virtual Room* MakeRoom(int n) const { return new BombedRoom(n); }
};