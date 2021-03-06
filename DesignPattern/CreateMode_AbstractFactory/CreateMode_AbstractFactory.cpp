﻿// CreateMode_AbstractFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/////////////////////////////////////////////////////////////////
#include "MazeGame.h"

int main()
{
    {
        MazeGame game;
        MazeFactory* factory = new EnchantedMazeFactory();

        Maze* aMaze = game.CreateMaze(factory); 
    }

    {
        MazeGame game;
        MazeFactory* factory = new BombedMazeFactory();

        Maze* aMaze = game.CreateMaze(factory);
    }
}