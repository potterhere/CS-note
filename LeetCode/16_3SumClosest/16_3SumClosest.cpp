// 16_3SumClosest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int nMinBias = std::numeric_limits<int>::max();
        int nThisSum = std::numeric_limits<int>::max();

        int i = 0;
        while (i < nums.size() - 2)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                const int sum = nums[i] + nums[j] + nums[k];
                int nBias = (sum - target);
                if (abs(nBias) <= nMinBias)
                {
                    nMinBias = abs(nBias);
                    nThisSum = sum;
                }

                if (nBias == 0)
                {
                    return nThisSum;
                }
                else if (nBias > 0)
                {
                    do
                    {
                        --k;
                    } while (j < k && nums[k + 1] == nums[k]);
                }
                else // nBias < 0
                {
                    do
                    {
                        ++j;
                    } while (j < k && nums[j - 1] == nums[j]);
                }
            }
            do
            {
                ++i;
            } while (nums[i - 1] == nums[i] && i < (int)nums.size() - 2);
        }

        return nThisSum;
    }
};

void test()
{
    {
        Solution solu;
        vector<int> nums = { -1,2,1,-4,2,3,45,61,-23,-24 };
        int target = 1;

        int nCloesetResult = solu.threeSumClosest(nums, target);
        int nCloesetExpexcted = 1;
        assert(nCloesetExpexcted == nCloesetResult);
    }
    {
        Solution solu;
        vector<int> nums = { -1, 2, 1, -4 };
        int target = 1;

        int nCloesetResult = solu.threeSumClosest(nums, target);
        int nCloesetExpexcted = 2;
        assert(nCloesetExpexcted == nCloesetResult);
    }
    
    {
        Solution solu;
        vector<int> nums = { -1,2,1,-4,2,3,45,61,-23,-24 };
        int target = 1;

        int nCloesetResult = solu.threeSumClosest(nums, target);
        int nCloesetExpexcted = 1;
        assert(nCloesetExpexcted == nCloesetResult);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
