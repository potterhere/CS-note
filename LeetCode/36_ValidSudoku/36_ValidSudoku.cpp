// 36_ValidSudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), corner(9);
        for (size_t i = 0; i < board.size(); ++i)
        {
            size_t nColSize = board[i].size();
            for (size_t j = 0; j < nColSize; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                if (row[i] & (1 << num)
                    || col[j] & (1 << num)
                    || (corner[(i / 3) * 3 + j / 3] & (1 << num)))
                    return false;

                row[i] |= 1 << num;
                col[j] |= 1 << num;
                corner[(i / 3) * 3 + j / 3] |= 1 << num;
            }
        }
        return true;
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

        bool bResult = solu.isValidSudoku(board);

        assert(bResult);
    }
    {
        vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}
            , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
            , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
            , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
            , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
            , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
            , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
            , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
            , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        bool bResult = solu.isValidSudoku(board);

        assert(bResult == false);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
