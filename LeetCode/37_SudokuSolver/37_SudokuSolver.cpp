// 37_SudokuSolver.cpp : 此文件包含 'main' 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), corner(9);
        for (size_t i = 0; i < board.size(); ++i)
        {
            size_t nColSize = board[i].size();
            for (size_t j = 0; j < nColSize; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                row[i] |= 1 << num;
                col[j] |= 1 << num;
                corner[(i/3)*3+j/3] |= 1 << num;
            }
        }

        Solver(0, 0, board, row, col, corner);
    }

private:
    bool Solver(int x, int y
        , vector<vector<char>>& board
        , vector<int>& row
        , vector<int>& col
        , vector<int>& conner)
    {
        if (y == 9)
        {
            y = 0;
            x += 1;
        }

        if (x == 9)
            return true;

        if (board[x][y] == '.')
        {
            for (int i = 1; i <= 9; ++i)
            {
                int nCornerPos = (x / 3) * 3 + y / 3;
                // not in && valid
                if ((row[x] & (1 << i))
                    || (col[y] & (1 << i))
                    || (conner[nCornerPos] & (1 << i)))
                {
                    continue;
                }

                row[x] |= (1 << i);
                col[y] |= (1 << i);
                conner[nCornerPos] |= (1 << i);

                board[x][y] = i + '0';
                if (Solver(x, y+1, board, row, col, conner))
                    return true;

                row[x] -= (1 << i);
                col[y] -= (1 << i);
                conner[nCornerPos] -= (1 << i);

                board[x][y] = '.';
            }
        }
        else
        {
            if (Solver(x, y+1, board, row, col, conner))
                return true;
        }
        return false;
    }
};

void test()
{
    Solution solu;
    {
        vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
            , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
            , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
            , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
            , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
            , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
            , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
            , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
            , {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

        vector<vector<char>> boardOut = { {'5', '3', '4', '6', '7', '8', '9', '1', '2'}
            , {'6', '7', '2', '1', '9', '5', '3', '4', '8'}
            , {'1', '9', '8', '3', '4', '2', '5', '6', '7'}
            , {'8', '5', '9', '7', '6', '1', '4', '2', '3'}
            , {'4', '2', '6', '8', '5', '3', '7', '9', '1'}
            , {'7', '1', '3', '9', '2', '4', '8', '5', '6'}
            , {'9', '6', '1', '5', '3', '7', '2', '8', '4'}
            , {'2', '8', '7', '4', '1', '9', '6', '3', '5'}
            , {'3', '4', '5', '2', '8', '6', '1', '7', '9'} };

        solu.solveSudoku(board);

        assert(board == boardOut);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
