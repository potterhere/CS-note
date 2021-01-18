// 20_ValidParentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> stackContent;
        for (char ch : s)
        {
            if (stackContent.empty())
            {
                stackContent.push(ch);
                continue;
            }

            char cTop = stackContent.top();
            if ((cTop == '(' && ch == ')')
                || (cTop == '[' && ch == ']')
                || (cTop == '{' && ch == '}'))
            {
                stackContent.pop(); // consume one
            }
            else
            {
                stackContent.push(ch);
            }
        }

        if (stackContent.empty())
            return true;
        return false;
    }
};

void test()
{
    Solution solu;
    {
        string s = "()";
        bool bR = solu.isValid(s);
        bool bA = true;
        assert(bR == bA);
    }
    {
        string s = "()[]{}";
        bool bR = solu.isValid(s);
        bool bA = true;
        assert(bR == bA);
    }
    {
        string s = "(]";
        bool bR = solu.isValid(s);
        bool bA = false;
        assert(bR == bA);
    }
    {
        string s = "([)]";
        bool bR = solu.isValid(s);
        bool bA = false;
        assert(bR == bA);
    }
    {
        string s = "{[]}";
        bool bR = solu.isValid(s);
        bool bA = true;
        assert(bR == bA);
    }
    {
        string s = "{[]}";
        bool bR = solu.isValid(s);
        bool bA = true;
        assert(bR == bA);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
