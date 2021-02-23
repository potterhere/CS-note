// 41_FirstMissingPositive.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0)
            return 1;

        set<int> setNums;
        for (auto num : nums)
        {
            if (num > 0)
            {
                setNums.insert(num);
            }
        }

        auto itBegin = setNums.begin();
        if (*itBegin > 1)
        {
            return 1;
        }
        
        int nBeginElement = *itBegin + 1;
        while (setNums.find(nBeginElement) != setNums.end())
        {
            ++nBeginElement;
        }
        return nBeginElement;
    }
};

void test()
{
    {
        Solution solu;
        vector<int> nums = {};
        int nResult = solu.firstMissingPositive(nums);
        int nExpected = 1;
        assert(nExpected == nResult);
    }
    {
        Solution solu;
        vector<int> nums = { 1,2 };
        int nResult = solu.firstMissingPositive(nums);
        int nExpected = 3;
        assert(nExpected == nResult);
    }
    {
        Solution solu;
        vector<int> nums = { 1,2,0 };
        int nResult = solu.firstMissingPositive(nums);
        int nExpected = 3;
        assert(nExpected == nResult);
    }
    {
        Solution solu;
        vector<int> nums = { 3,4,-1,1 };
        int nResult = solu.firstMissingPositive(nums);
        int nExpected = 2;
        assert(nExpected == nResult);
    }
    {
        Solution solu;
        vector<int> nums = { 7,8,9,11,12};
        int nResult = solu.firstMissingPositive(nums);
        int nExpected = 1;
        assert(nExpected == nResult);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
