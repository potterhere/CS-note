// 18_4Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <assert.h>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return vector<vector<int>>();

        vector<vector<int>> results;

        std::sort(nums.begin(), nums.end());

        int i = 0;
        while (i < (int)nums.size() - 3)
        {
            int j = i + 1;
            while (j < nums.size() - 2)
            {
                int jj = j + 1;
                int k = nums.size() - 1;

                while (jj < k)
                {
                    const int sum = nums[i] + nums[j] + nums[jj] + nums[k];
                    int nBias = (sum - target);
                    if (nBias == 0)
                    {
                        results.push_back({ nums[i], nums[j], nums[jj], nums[k] });
                        do
                        {
                            ++jj;
                        } while (jj < k && nums[jj - 1] == nums[jj]);
                        do
                        {
                            --k;
                        } while (jj < k && nums[k + 1] == nums[k]);
                    }
                    else if (nBias > 0)
                    {
                        --k;
                    }
                    else // nBias < 0
                    {
                        ++jj;
                    }
                }

                do
                {
                    ++j;
                } while (nums[j - 1] == nums[j] && j < (int)nums.size() - 2);
            }

            do
            {
                ++i;
            } while (nums[i - 1] == nums[i] && i < (int)nums.size() - 3);
        }

        return results;
    }
};

void test()
{
    Solution solu;
    {
        vector<int> nums = { 1, 0, -1, 0, -2, 2 };
        int target = 0;
        vector<vector<int>> vecExpected = { {-2, -1, 1, 2},{-2, 0, 0, 2},{-1, 0, 0, 1} };

        vector<vector<int>> vecActual = solu.fourSum(nums, target);

        assert(vecActual == vecExpected);
    }
    {
        vector<int> nums = { 0, 0, 0, 0 };
        int target = 0;
        vector<vector<int>> vecExpected = { {0, 0, 0,0} };

        vector<vector<int>> vecActual = solu.fourSum(nums, target);

        assert(vecActual == vecExpected);
    }
    {
        vector<int> nums = {};
        int target = 0;
        vector<vector<int>> vecExpected = {};

        vector<vector<int>> vecActual = solu.fourSum(nums, target);

        assert(vecActual == vecExpected);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
