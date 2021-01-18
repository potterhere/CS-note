// 1291_SequentialDigits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
private:
    int GetNumberCount(int number)
    {
        int nCount = 0;
        while (number > 0)
        {
            number /= 10;
            ++nCount;
        }

        return nCount;
    }

    int GenOne_N(int nCount)
    {
        int nSum = 0;
        for (int i = 0; i < nCount; ++i)
        {
            nSum = nSum * 10 + 1;
        }
        return nSum;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        // Get low's number
        // Get high's number
        int nCountLow = GetNumberCount(low);
        int nCountHigh = GetNumberCount(high);
        
        vector<int> vecResult;
        for (int nIndex = nCountLow; nIndex <= nCountHigh; ++nIndex)
        {
            int nCount = 0, nBegin = 0;
            int nAdded = 1;
            while (nCount < nIndex)
            {
                nBegin = nBegin * 10 + nAdded;

                ++nAdded;
                if (nAdded > 10)
                    break;

                ++nCount;
            }

            if (nCount == nIndex && nBegin <= high)
            {
                if (nBegin >= low)
                {
                    vecResult.push_back(nBegin);
                }

                int nAdder = GenOne_N(nIndex);
                int nNext = nBegin;
                while (nNext % 10 < 9)
                {
                    nNext += nAdder;
                    if (nNext > high)
                        break;

                    if (nNext >= low)
                        vecResult.push_back(nNext);
                }
            }
        }

        return vecResult;
    }
};

void test()
{
    Solution solu;
    {
        int low = 100, high = 300;
        vector<int> vecResult = solu.sequentialDigits(low, high);
        vector<int> vecExpect = { 123, 234 };
        assert(vecResult == vecExpect);
    }
    {
        int low = 100, high = 456;
        vector<int> vecResult = solu.sequentialDigits(low, high);
        vector<int> vecExpect = { 123, 234, 345, 456};
        assert(vecResult == vecExpect);
    }
    {
        int low = 58, high = 155;
        vector<int> vecResult = solu.sequentialDigits(low, high);
        vector<int> vecExpect = { 123, 234, 345, 456 };
        assert(vecResult == vecExpect);
    }
    {
        int low = 1000, high = 24000;
        vector<int> vecResult = solu.sequentialDigits(low, high);
        vector<int> vecExpect = {1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456};
        assert(vecResult == vecExpect);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
