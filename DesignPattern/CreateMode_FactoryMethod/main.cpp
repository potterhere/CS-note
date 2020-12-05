// CreateMode_AbstractFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/////////////////////////////////////////////////////////////////
#include "MazeGame.h"

int main()
{
    {
        MazeGame* game = new MazeGame();
        Maze* aMaze = game->CreateMaze(); 
    }

    {
        MazeGame* game = new EnchantedMazeGame();
        Maze* aMaze = game->CreateMaze();
    }

    {
        MazeGame* game = new BombedMazeGame();
        Maze* aMaze = game->CreateMaze();
    }
}