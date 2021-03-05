// 32_LongestValidParentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    struct ST_INFO {
        char ch;
        int pos;
    };

    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;

        stack<ST_INFO> stackCount;

        for (size_t nIndex = 0; nIndex < s.size(); ++nIndex)
        {
            ST_INFO stInfoCurrent;
            stInfoCurrent.ch = s[nIndex];
            stInfoCurrent.pos = (int)nIndex;

            // 不空，且能消除，否则入栈
            if (!stackCount.empty())
            {
                ST_INFO& stInfoTop = stackCount.top();
                if (stInfoTop.ch == '(' && stInfoCurrent.ch == ')')
                {
                    stackCount.pop();
                    continue;
                }
            }

            stackCount.push(stInfoCurrent);
        }

        return GetLongestValue(stackCount, (int)s.size());
    }

private:
    int GetLongestValue(stack<ST_INFO>& stackCount, int nStringSize)
    {
        if (stackCount.empty())
            return  nStringSize;

        vector<int> vecInfo;
        {
            vecInfo.push_back(nStringSize);
        }

        while (!stackCount.empty())
        {
            ST_INFO info = stackCount.top();
            stackCount.pop();

            vecInfo.insert(vecInfo.begin(), info.pos);
        }

        {
            vecInfo.insert(vecInfo.begin(), -1);
        }

        int nMaxGap = 0;
        for (size_t nIndex = 0; nIndex < vecInfo.size()-1; ++nIndex)
        {
            int stPrev = vecInfo[nIndex];
            int stNext = vecInfo[nIndex + 1];
            int nGap = stNext - stPrev - 1;
            nMaxGap = max(nMaxGap, nGap);
        }
        return nMaxGap;
    }
};

void test()
{
    {
        Solution solu;
        string s = "())";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 2;
        assert(nResult == nExpexted);
    }
    {
        Solution solu;
        string s = ")()())";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 4;
        assert(nResult == nExpexted);
    }
    {
        Solution solu;
        string s = "(()";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 2;
        assert(nResult == nExpexted);
    }
    {
        Solution solu;
        string s = "";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 0;
        assert(nResult == nExpexted);
    }
    {
        Solution solu;
        string s = "(()(()))";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 8;
        assert(nResult == nExpexted);
    }
    {
        Solution solu;
        string s = "()()(((()))";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 6;
        assert(nResult == nExpexted);
    }
    {
        Solution solu;
        string s = "()()(((())))";
        int nResult = solu.longestValidParentheses(s);
        int nExpexted = 12;
        assert(nResult == nExpexted);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
