// 131_PalindromePartitioning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vecResult.clear();

        vector<string> vecbegin;
        partition(s, vecbegin);

        return vecResult;
    }

    void partition(string s, vector<string>& vecCurrent)
    {
        if (s.size() == 0)
        {
            vecResult.push_back(vecCurrent);
            return;
        }

        size_t nSize = s.size();
        for (size_t i = 1; i <= nSize; i++)
        {
            string strSub = s.substr(0, i);
            if (!bIsPalidrome(strSub))
            {
                continue;
            }

            vecCurrent.push_back(strSub);

            string strNext = s.substr(i);
            partition(strNext, vecCurrent);

            vecCurrent.pop_back();
        }
    }

private:
    bool bIsPalidrome(const string &s)
    {
        size_t nBegin = 0;
        size_t nEnd = s.size() - 1;
        while (nBegin < nEnd)
        {
            if (s[nBegin] == s[nEnd])
            {
                ++nBegin;
                --nEnd;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }

    vector<vector<string>> vecResult;
};

void test()
{
    {
        Solution solu;

        string s = "aab";
        vector<vector<string>> vecResult = solu.partition(s);
        vector<vector<string>> vecExpected = { {"a", "a", "b"}, {"aa", "b"} };
        assert(vecResult == vecExpected);
    }
    {
        Solution solu;

        string s = "a";
        vector<vector<string>> vecResult = solu.partition(s);
        vector<vector<string>> vecExpected = { {"a"} };
        assert(vecResult == vecExpected);
    }
    {
        Solution solu;

        string s = "aaaaa";
        vector<vector<string>> vecResult = solu.partition(s);
        vector<vector<string>> vecExpected = {{"a", "a", "a", "a", "a"}
            , {"a", "a", "a", "aa"}
            , {"a", "a", "aa", "a"}
            , {"a", "a", "aaa"}
            , {"a", "aa", "a", "a"}
            , {"a", "aa", "aa"}
            , {"a", "aaa", "a"}
            , {"a", "aaaa"}
            , {"aa", "a", "a", "a"}
            , {"aa", "a", "aa"}
            , {"aa", "aa", "a"}
            , {"aa", "aaa"}
            , {"aaa", "a", "a"}
            , {"aaa", "aa"}
            , {"aaaa", "a"}
            , {"aaaaa"}};
        assert(vecResult == vecExpected);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
