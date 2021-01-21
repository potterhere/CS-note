// 104_MaximumDepthofBinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../global.h"

 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return GetDepth(root);
    }

private:
    int GetDepth(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        return max(GetDepth(node->left), GetDepth(node->right)) + 1;
    }
};

void test()
{

}

int main()
{
    std::cout << "Hello World!\n";
}
