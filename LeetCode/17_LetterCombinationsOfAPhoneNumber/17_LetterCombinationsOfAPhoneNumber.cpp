// 17_LetterCombinationsOfAPhoneNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // DFS
        if (digits.size() == 0)
            return {};

        vector<string> vecResult;

        ConsumeOne(digits, 0, "", vecResult);

        return vecResult;
    }

    void ConsumeOne(string& digits, int index, string strCompose, vector<string>& vecResult)
    {
        if (index >= digits.size())
        {
            vecResult.push_back(strCompose);
            strCompose = "";
            return;
        }

        string sCur = mapping(digits[index]);
        for (auto s : sCur)
        {
            ConsumeOne(digits, index + 1, strCompose + s, vecResult);
        }
    }

private:
    string mapping(char ch)
    {
        switch (ch)
        {
        case '1':
            return "";
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
            break;
        }
    }
};


void test()
{
    {
        Solution solu;
        string digits = "23";
        vector<string> vecResult = solu.letterCombinations(digits);
        vector<string> vecExpected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        assert(vecExpected == vecResult);
    }
    {
        Solution solu;
        string digits = "";
        vector<string> vecResult = solu.letterCombinations(digits);
        vector<string> vecExpected = {  };
        assert(vecExpected == vecResult);
    }
    {
        Solution solu;
        string digits = "2";
        vector<string> vecResult = solu.letterCombinations(digits);
        vector<string> vecExpected = { "a","b","c" };
        assert(vecExpected == vecResult);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
