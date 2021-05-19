// 64_MinimumPathSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../global.h"
#include <iostream>

//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int nValue = 0;
//        
//        size_t nColSize = grid.size();
//        size_t nRowSize = grid[0].size();
//        size_t nMoveStep = nColSize + nRowSize - 1;
//        
//        int nFirstRight = MoveRight(grid, 0, 0);
//        int nFirstDown = MoveDown(grid, 0, 0);
//        return std::min(nFirstRight, nFirstDown);
//    }
//
//private:
//    // Value
//    int MoveRight(vector<vector<int>>& grid, int nCurCol, int nCurRow)
//    {
//        size_t nColSize = grid.size();
//        size_t nRowSize = grid[0].size();
//
//        if (nCurRow == (nRowSize - 1)
//            && nCurCol == (nColSize - 1))
//        {
//            return grid[nCurCol][nCurRow];
//        }
//
//        if (nCurCol > (nColSize - 1))
//        {
//            --nCurCol;
//            return grid[nCurCol][nCurRow] + MoveDown(grid, nCurCol , nCurRow + 1);
//        }
//        else
//        {
//            int nValue1 = grid[nCurCol][nCurRow] + MoveRight(grid, nCurCol + 1, nCurRow);
//            int nValue2 = grid[nCurCol][nCurRow] + MoveDown(grid, nCurCol, nCurRow + 1);
//            return std::min(nValue1, nValue2);
//        }
//    }
//
//    int MoveDown(vector<vector<int>>& grid, int nCurCol, int nCurRow)
//    {
//        size_t nColSize = grid.size();
//        size_t nRowSize = grid[0].size();
//
//        if (nCurRow == (nRowSize - 1)
//            && nCurCol == (nColSize - 1))
//        {
//            return grid[nCurCol][nCurRow];
//        }
//
//        if (nCurRow > (nRowSize - 1))
//        {
//            --nCurRow;
//            return MoveRight(grid, nCurCol + 1, nCurRow);
//        }
//        else
//        {
//            int nValue1 = grid[nCurCol][nCurRow] + MoveRight(grid, nCurCol + 1, nCurRow);
//            int nValue2 = grid[nCurCol][nCurRow] + MoveDown(grid, nCurCol, nCurRow + 1);
//            return std::min(nValue1, nValue2);
//        }
//    }
//};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < m; i++)
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        return sum[m - 1][n - 1];
    }
};

void test()
{
    Solution solu;
    {
        vector<vector<int>> grid = { {1, 3, 1},{1, 5, 1},{4, 2, 1 } };
        int nResult = solu.minPathSum(grid);
        assert(7 == nResult);
    }
    {
        vector<vector<int>> grid = { {1, 2, 3},{4, 5, 6} };
        int nResult = solu.minPathSum(grid);
        assert(12 == nResult);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}

