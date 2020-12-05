#pragma once

class Room {
public:
    Room(int n) { }
};
class Wall {};

class Door {
public:
    Door(Room* r1, Room* r2) {}
};

class Maze {
public:
    void AddRoom(Room* r1) {}
};

/////////////////////////////////////////////////////////////////
class EnhantedRoom : public Room {
public:
    EnhantedRoom(int n) : Room(n) {
    }
};

class DoorNeedingSpell : public Door {
public:
    DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2) { }
};

class BombedWall : public Wall {};

class BombedRoom : public Room {
public:
    BombedRoom(int n) : Room(n) {}
};