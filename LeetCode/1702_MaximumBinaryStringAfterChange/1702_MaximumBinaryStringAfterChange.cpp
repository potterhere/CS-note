// 1702_MaximumBinaryStringAfterChange.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        string result = string(n, '1');
        int zero_count = count(binary.begin(), binary.end(), '0');
        if (zero_count == 0) {
            return result;
        }
        int first_zero = binary.find('0');
        result[first_zero + zero_count - 1] = '0';
        return result;
    }
};

void test()
{
    Solution solu;
    {
        string binary = "000110";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "111011";
        assert(strResult == strExpect);
    }
    {
        string binary = "01";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "01";
        assert(strResult == strExpect);
    }
    {
        string binary = "0001";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "1101";
        assert(strResult == strExpect);
    }
    {
        string binary = "00010";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "11101";
        assert(strResult == strExpect);
    }
    {
        string binary = "0";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "0";
        assert(strResult == strExpect);
    }
    {
        string binary = "1";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "1";
        assert(strResult == strExpect);
    }
    {
        string binary = "01110";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "10111";
        assert(strResult == strExpect);
    }
    {
        string binary = "01111001100000110010";
        string strResult = solu.maximumBinaryString(binary);
        string strExpect = "11111111110111111111";
        assert(strResult == strExpect);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
