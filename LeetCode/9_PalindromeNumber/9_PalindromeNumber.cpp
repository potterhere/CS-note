// 9_PalindromeNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        //if (x >= 2147483647)

        /*std::string strNumOrigin = std::to_string(x);
        std::string strNum = std::to_string(x);
        std::reverse(strNum.begin(), strNum.end());

        if (strNum == strNumOrigin)
            return true;
        return false;*/


    }

    int GetLength(int x)
    {
        int nCount = 0;
        int y = x;
        while (y > 0)
        {
            y = y / 10;
        }
    }
};

void test()
{
    Solution solu;
    {
        int x = 121;
        bool bResult = solu.isPalindrome(x);
        assert(bResult == true);
    }
    {
        int x = -121;
        bool bResult = solu.isPalindrome(x);
        assert(bResult == false);
    }
    {
        int x = 10;
        bool bResult = solu.isPalindrome(x);
        assert(bResult == false);
    }
    {
        int x = -101;
        bool bResult = solu.isPalindrome(x);
        assert(bResult == false);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
