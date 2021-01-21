// 1387_SortIntegersbyThePowerValue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

//class Solution {
//public:
//    int getKth(int lo, int hi, int k) {
//        vector<node> vecNodes;
//        for (size_t i = lo; i <= hi; i++)
//        {
//            node _node;
//            _node.nValue = i;
//            _node.nPower = nCalPower(i);
//
//            vecNodes.push_back(_node);
//        }
//
//        sort(vecNodes.begin(), vecNodes.end());
//
//        return vecNodes[k - 1].nValue;
//    }
//
//private:
//    map<int, int> mapNum2Power;
//
//    struct node
//    {
//        int nValue;
//        int nPower;
//
//        bool operator<(const node& other)
//        {
//            if (nPower < other.nPower)
//                return true;
//            if (nPower == other.nPower
//                && nValue < other.nValue)
//                return true;
//            return false;
//        }
//    };
//
//    int nCalPower(int x)
//    {
//        if (mapNum2Power.find(x) != mapNum2Power.end())
//            return mapNum2Power[x];
//
//        if (x == 1)
//            return 0;
//
//        int x_next = 0;
//        if (x % 2 == 0)
//            x_next = x / 2;
//        else
//            x_next = 3 * x + 1;
//
//        int nPower = 1 + nCalPower(x_next);
//        mapNum2Power[x] = nPower;
//
//        return nPower;
//    }
//};

class Solution {
public:
    int getPower(int i) {
        if (i == 1)
            return 0;
        int x = (i % 2) ? getPower(i * 3 + 1) + 1 : getPower(i >> 1) + 1;
        return x;
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> s;
        for (; lo <= hi; ++lo) {
            s.emplace_back(make_pair(getPower(lo), lo));
        }

        std::sort(s.begin(), s.end());
        return s[k - 1].second;
    }
};

void test()
{
    {
        Solution solu;

        int lo = 12, hi = 15, k = 2;
        int nResult = solu.getKth(lo, hi, k);
        int nExpect = 13;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int lo = 1, hi = 1, k = 1;
        int nResult = solu.getKth(lo, hi, k);
        int nExpect = 1;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int lo = 7, hi = 11, k = 4;
        int nResult = solu.getKth(lo, hi, k);
        int nExpect = 7;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int lo = 10, hi = 20, k = 5;
        int nResult = solu.getKth(lo, hi, k);
        int nExpect = 13;
        assert(nResult == nExpect);
    }
    {
        Solution solu;
        int lo = 1, hi = 1000, k = 777;
        int nResult = solu.getKth(lo, hi, k);
        int nExpect = 570;
        assert(nResult == nExpect);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
