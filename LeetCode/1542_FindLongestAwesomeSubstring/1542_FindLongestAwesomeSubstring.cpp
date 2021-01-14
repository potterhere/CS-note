// 1542_FindLongestAwesomeSubstring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <assert.h>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        
        int nCount = 0;
        string strMark;

        size_t nSize = s.size();
        for (size_t nBeginPos = 0; nBeginPos <= nSize; ++nBeginPos)
        {
            for (size_t nLen = 1; (nBeginPos+nLen) <= nSize; ++nLen)
            {
                string str_Sub = s.substr(nBeginPos, nLen);
                int nNew = strCounter(str_Sub);
                if (nNew > nCount)
                {
                    nCount = nNew;
                    strMark = str_Sub;
                }
            }
        }

        cout << "Input: " << s << " , target:"<< strMark << endl;

        return nCount;
    }

    int strCounter(string s)
    {
        vector<size_t> vecCounter;
        vecCounter.resize(10, 0);

        for (char c : s)
        {
            ++vecCounter[c - '0'];
        }

        int nCount = 0;
        for (size_t index = 0; index < 10; ++index)
        {
            nCount += (vecCounter[index] / 2 * 2);
        }

        for (size_t index = 0; index < 10; ++index)
        {
            if (vecCounter[index] % 2 == 1)
            {
                ++nCount;
                break;
            }
        }
        return nCount;
    }
};

void test()
{
    Solution solu;
    {
        string s = "3242415";
        int nActual = solu.longestAwesome(s);
        int nExpected = 5;

        assert(nActual == nExpected);
    }
    {
        string s = "12345678";
        int nActual = solu.longestAwesome(s);
        int nExpected = 1;

        assert(nActual == nExpected);
    }
    {
        string s = "213123";
        int nActual = solu.longestAwesome(s);
        int nExpected = 6;

        assert(nActual == nExpected);
    }
    {
        string s = "00";
        int nActual = solu.longestAwesome(s);
        int nExpected = 2;

        assert(nActual == nExpected);
    }
    {
        string s = "9498331";
        int nActual = solu.longestAwesome(s);
        int nExpected = 3;

        assert(nActual == nExpected);
    }
}

int main()
{
    test();
    std::cout << "finished!\n";
}
