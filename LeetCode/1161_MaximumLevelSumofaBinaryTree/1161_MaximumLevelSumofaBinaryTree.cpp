// 1161_MaximumLevelSumofaBinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0, level = 0, global_sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size(), tmp_sum = 0;
            while (count--) {
                TreeNode* tmp = q.front();
                q.pop();
                tmp_sum += tmp->val;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            level++;
            if (tmp_sum > global_sum) res = level;
            global_sum = max(tmp_sum, global_sum);
        }
        return res;
    }
};

void test()
{
    Solution solu;
    {
        TreeNode* root = new TreeNode(1);
        TreeNode* node_2_1 = new TreeNode(7);
        TreeNode* node_2_2 = new TreeNode(0);
        TreeNode* node_3_1 = new TreeNode(7);
        TreeNode* node_3_2 = new TreeNode(-8);

        root->left = node_2_1;
        root->right = node_2_2;

        node_2_1->left = node_3_1;
        node_2_1->right = node_3_2;

        int nResult = solu.maxLevelSum(root);
        int nExpected = 2;
        assert(nResult == nExpected);
    }
    {
        TreeNode* root = new TreeNode(989);
        TreeNode* node_2_2 = new TreeNode(10250);
        TreeNode* node_3_1 = new TreeNode(98693);
        TreeNode* node_3_2 = new TreeNode(-89388);
        TreeNode* node_4_1 = new TreeNode(-32127);

        root->right = node_2_2;
        node_2_2->left = node_3_1;
        node_2_2->right = node_3_2;
        node_3_2->right = node_4_1;

        int nResult = solu.maxLevelSum(root);
        int nExpected = 2;
        assert(nResult == nExpected);
    }
    {
        TreeNode* root = new TreeNode(989);
        
        int nResult = solu.maxLevelSum(root);
        int nExpected = 1;
        assert(nResult == nExpected);
    }
}

int main()
{
    test();
    std::cout << "Hello World!\n";
}
