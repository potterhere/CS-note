#pragma once

class Room{
public:
    Room() {}
    Room(int n) { }
    virtual Room* clone() const {
        return new Room(*this);
    }

private:
    int nNum = 0;
};
class Wall {
public:
    virtual Wall* clone() const {
        return new Wall(*this);
    }
};

class Door{
public:
    Door() {}
    Door(Room* r1, Room* r2) {}
    virtual Door* clone() const {
        return new Door(*this);
    }

private:
    Room* _r1 = nullptr;
    Room* _r2 = nullptr;
};

class Maze{
public:
    void AddRoom(Room* r1) {}
    virtual Maze* clone() const{
        return new Maze(*this);
    }
};

/////////////////////////////////////////////////////////////////
// clone on subclass
class EnhantedRoom : public Room {
public:
    EnhantedRoom(int n) : Room(n) {
    }

    virtual Room* clone() const {
        return new EnhantedRoom(*this);
    }
};

class DoorNeedingSpell : public Door {
public:
    DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2) { }

    virtual Door* clone() const{
        return new DoorNeedingSpell(*this);
    }
};

class BombedWall : public Wall {
public:
    virtual Wall* clone() const {
        return new BombedWall(*this);
    }
};

class BombedRoom : public Room {
public:
    BombedRoom(int n) : Room(n) {}

    virtual Room* clone() const {
        return new BombedRoom(*this);
    }
};
