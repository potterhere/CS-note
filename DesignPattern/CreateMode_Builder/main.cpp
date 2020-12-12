#include "MazeGame.h"
#include "Builder.h"

int main()
{
	MazeGame game;

	MazeBuilderStandard builder;
	game.CreateMaze(builder); // director负责构件的过程

	Maze* maze = builder.GetMaze(); // 得到最终的产品

	return 1;
}