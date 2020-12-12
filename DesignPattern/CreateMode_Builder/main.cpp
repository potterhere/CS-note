#include "MazeGame.h"
#include "Builder.h"

int main()
{
	MazeGame game;

	MazeBuilderStandard builder;
	game.CreateMaze(builder); // director���𹹼��Ĺ���

	Maze* maze = builder.GetMaze(); // �õ����յĲ�Ʒ

	return 1;
}