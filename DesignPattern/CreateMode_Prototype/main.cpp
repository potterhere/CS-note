// CreateMode_AbstractFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/////////////////////////////////////////////////////////////////
#include "MazeGame.h"

int main()
{
    {
        MazeGame* game = new MazeGame();

        MazeFactoryPrototype mazePrototype(new Maze, new Wall, new Room, new Door);

        Maze* aMaze = game->CreateMaze(&mazePrototype);
    }
}