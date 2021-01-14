// 14._LongestCommonPrefix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <assert.h>
#include <set>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        size_t min_index = 0;
        size_t nMinLen = numeric_limits<size_t>::max();
        for (size_t index = 0; index < strs.size(); ++index)
        {
            size_t nSize = strs[index].size();
            if (nSize < nMinLen)
            {
                nMinLen = nSize;
                min_index = index;
            }
        }

        string min_str = strs[min_index];
        for (size_t index = 0; index < min_str.size(); ++index)
        {
            bool bAllHas = true;
            char char_current = min_str[index];
            for (size_t i = 0; i < strs.size(); ++i)
            {
                if (strs[i][index] != char_current)
                {
                    bAllHas = false;
                    break;
                }
            }

            if (bAllHas == false)
            {
                if (index == 0)
                    return "";
                return min_str.substr(0, index);
            }
        }
        return min_str;
    }
};

void test()
{
    Solution solu;
    {
        vector<string> strs = { "flower", "flow", "flight" };
        string result =  solu.longestCommonPrefix(strs);
        string expexcted = "fl";
        assert(result == expexcted);
    }

    {
        vector<string> strs = {"dog", "racecar", "car"};
        string result = solu.longestCommonPrefix(strs);
        string expexcted = "";
        assert(result == expexcted);
    }

    {
        vector<string> strs = {};
        string result = solu.longestCommonPrefix(strs);
        string expexcted = "";
        assert(result == expexcted);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
