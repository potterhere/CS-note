// 35_SearchInsertPosition.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};

void test()
{
    {
        Solution solu;
        vector<int> nums = { 1, 3, 5, 6 };
        int nPos = solu.searchInsert(nums, 5);
        assert(nPos == 2);
    }
    {
        Solution solu;
        vector<int> nums = { 1, 3, 5, 6 };
        int nPos = solu.searchInsert(nums, 2);
        assert(nPos == 1);
    }
    {
        Solution solu;
        vector<int> nums = { 1, 3, 5, 6 };
        int nPos = solu.searchInsert(nums, 7);
        assert(nPos == 4);
    }
    {
        Solution solu;
        vector<int> nums = { 1, 3, 5, 6 };
        int nPos = solu.searchInsert(nums, 0);
        assert(nPos == 0);
    }
    {
        Solution solu;
        vector<int> nums = { 1 };
        int nPos = solu.searchInsert(nums, 0);
        assert(nPos == 0);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
