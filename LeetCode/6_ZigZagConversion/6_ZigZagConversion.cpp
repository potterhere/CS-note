// 6_ZigZagConversion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <assert.h>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;

        stringstream ss;
        
        set<size_t> setHas;

        size_t nSize = s.size();
        size_t nOffset = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i)
        {
            size_t firstPos = i; 
            size_t firstPos_may = i;
            if ((numRows - i) > 1)
                firstPos_may = i + nOffset - 2 * i;
            while(firstPos < nSize || firstPos_may < nSize)
            {
                if (firstPos < nSize && setHas.find(firstPos) == setHas.end())
                {
                    ss << s[firstPos];
                    setHas.insert(firstPos);
                }
                if (firstPos_may < nSize && firstPos != firstPos_may)
                {
                    if (setHas.find(firstPos_may) == setHas.end())
                    {
                        ss << s[firstPos_may];
                        setHas.insert(firstPos_may);
                    }
                }

                firstPos += nOffset;
                firstPos_may += nOffset;
            }
        }

        return ss.str();
    }

    //string convert(string s, int numRows) {
    //    if (numRows == 1)
    //        return s;

    //    stringstream ss;

    //    set<size_t> setAll;
    //    size_t nSize = s.size();
    //    for (size_t i = 0; i < nSize; ++i)
    //    {
    //        setAll.insert(i);
    //    }
    //    
    //    set<size_t> setFirst = firstPos(s, numRows);
    //    for (auto nValue : setFirst)
    //    {
    //        // print
    //        // remove from setall
    //        ss << s[nValue];
    //        setAll.erase(nValue);
    //    }

    //    // use first, find next (front back search)
    //    while (!setAll.empty())
    //    {
    //        set<size_t> setNext = GetPos(setFirst, setAll, nSize);
    //        for (auto nValue : setNext)
    //        {
    //            // print
    //            // remove from setall
    //            ss << s[nValue];
    //            setAll.erase(nValue);
    //        }

    //        setFirst = setNext;
    //    }

    //    return ss.str();
    //}

    //set<size_t> firstPos(string s, int numRows)
    //{
    //    set<size_t> pos;

    //    int coeff = 2 * numRows - 2;
    //    size_t nSize = s.size();
    //    for (size_t i = 0; i < nSize; ++i)
    //    {
    //        if (i % coeff == 0)
    //            pos.insert(i);
    //    }

    //    return pos;
    //}

    //set<size_t> GetPos(const set<size_t>& setCurrent, set<size_t>& setAll, size_t nSize)
    //{
    //    set<size_t> setNext;
    //    for (auto nValue : setCurrent)
    //    {
    //        if (nValue > 0 
    //            && setAll.find(nValue-1) != setAll.end())
    //        {
    //            setNext.insert(nValue - 1);
    //        }

    //        if ((nValue + 1) < nSize 
    //            && setAll.find(nValue+1) != setAll.end())
    //        {
    //            setNext.insert(nValue + 1);
    //        }
    //    }
    //    return setNext;
    //}
};

void test()
{
    Solution solu;
    {
        // P   A   H   N
        // A P L S I I G
        // Y   I   R
        string s = "PAYPALISHIRING";
        string actual =  solu.convert(s, 3);
        string expect = "PAHNAPLSIIGYIR";

        assert(actual == expect);
    }
    {
        /*Input: s = "PAYPALISHIRING", numRows = 4
        Output : "PINALSIGYAHRPI"
        Explanation :
        P     I    N
        A   L S  I G
        Y A   H R
        P     I*/

        string s = "PAYPALISHIRING";
        string actual = solu.convert(s, 4);
        string expect = "PINALSIGYAHRPI";

        assert(actual == expect);
    }

    {
        /*Input: s = "A", numRows = 1
        Output : "A"
        Explanation :
        A*/

        string s = "A";
        string actual = solu.convert(s, 1);
        string expect = "A";

        assert(actual == expect);
    }

    {
        string s = "ABCD";
        string actual = solu.convert(s, 3);
        string expect = "ABDC";

        assert(actual == expect);
    }
}

int main()
{
    test();

    cout << "finished" << endl;
}

