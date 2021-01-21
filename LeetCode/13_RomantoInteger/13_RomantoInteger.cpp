// 13_RomantoInteger.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    int romanToInt(string s) {
        int nSum = 0;
        while (!s.empty())
        {
            if (s.size() >= 2)
            {
                bool bConsumeTwo = true;
                if (s[0] == 'C' && s[1] == 'M')
                    nSum += 900;
                else if (s[0] == 'C' && s[1] == 'D')
                    nSum += 400;
                else if (s[0] == 'X' && s[1] == 'L')
                    nSum += 40;
                else if (s[0] == 'X' && s[1] == 'C')
                    nSum += 90;
                else if (s[0] == 'I' && s[1] == 'V')
                    nSum += 4;
                else if (s[0] == 'I' && s[1] == 'X')
                    nSum += 9;
                else
                {
                    bConsumeTwo = false;
                    if (s[0] == 'I')
                        nSum += 1;
                    else if (s[0] == 'V')
                        nSum += 5;
                    else if (s[0] == 'X')
                        nSum += 10;
                    else if (s[0] == 'L')
                        nSum += 50;
                    else if (s[0] == 'C')
                        nSum += 100;
                    else if (s[0] == 'D')
                        nSum += 500;
                    else if (s[0] == 'M')
                        nSum += 1000;
                    else
                        nSum += 0;

                    s = s.substr(1);
                }

                if (bConsumeTwo)
                    s = s.substr(2);
            }
            else
            {
                if (s[0] == 'I')
                    nSum += 1;
                else if (s[0] == 'V')
                    nSum += 5;
                else if (s[0] == 'X')
                    nSum += 10;
                else if (s[0] == 'L')
                    nSum += 50;
                else if (s[0] == 'C')
                    nSum += 100;
                else if (s[0] == 'D')
                    nSum += 500;
                else if (s[0] == 'M')
                    nSum += 1000;
                else
                    nSum += 0;

                s = s.substr(1);
            }
        }

        return nSum;
    }
};

void test()
{
    {
        Solution solu;
        int nResult = solu.romanToInt("III");
        int nExpect = 3;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int nResult = solu.romanToInt("IV");
        int nExpect = 4;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int nResult = solu.romanToInt("IX");
        int nExpect = 9;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int nResult = solu.romanToInt("LVIII");
        int nExpect = 58;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int nResult = solu.romanToInt("MCMXCIV");
        int nExpect = 1994;
        assert(nResult == nExpect);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
