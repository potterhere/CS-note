// 21_MergeTwoSortedLists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = nullptr;

        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        else if (l1 == nullptr && l2 != nullptr)
        {
            root = new ListNode(l2->val, nullptr);
            mergeNext(root, nullptr, l2->next);
        }
        else if (l1 != nullptr && l2 == nullptr)
        {
            root = new ListNode(l1->val, nullptr);
            mergeNext(root, l1->next, nullptr);
        }
        else
        {
            if (l1->val < l2->val)
            {
                root = new ListNode(l1->val, nullptr);
                mergeNext(root, l1->next, l2);
            }
            else
            {
                root = new ListNode(l2->val, nullptr);
                mergeNext(root, l1, l2->next);
            }
        }

        return root;
    }

private:
    void mergeNext(ListNode*& cur, ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return;

        if (l1 == nullptr && l2 != nullptr)
        {
            cur->next = new ListNode(l2->val, nullptr);
            mergeNext(cur->next, l1, l2->next);
        }
        else if (l1 != nullptr && l2 == nullptr)
        {
            cur->next = new ListNode(l1->val, nullptr);
            mergeNext(cur->next, l1->next, nullptr);
        }
        else
        {
            if (l1->val < l2->val)
            {
                cur->next = new ListNode(l1->val, nullptr);
                mergeNext(cur->next, l1->next, l2);
            }
            else
            {
                cur->next = new ListNode(l2->val, nullptr);
                mergeNext(cur->next, l1, l2->next);
            }
        }
    }
};

void test()
{
    Solution solu;
    {
        ListNode* node1 = new ListNode(1, nullptr);
        ListNode* node2 = new ListNode(2, nullptr);
        ListNode* node4 = new ListNode(4, nullptr);
        node1->next = node2;
        node2->next = node4;

        ListNode* node1_ = new ListNode(1, nullptr);
        ListNode* node3_ = new ListNode(3, nullptr);
        ListNode* node4_ = new ListNode(4, nullptr);
        node1_->next = node3_;
        node3_->next = node4_;

        ListNode* listResult = solu.mergeTwoLists(node1, node1_);
    }

    {
        ListNode* listResult = solu.mergeTwoLists(nullptr, nullptr);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
