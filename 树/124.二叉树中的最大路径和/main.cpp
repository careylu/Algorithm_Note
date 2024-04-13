// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

//题目描述
//
//路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。路径和 是路径中各节点值的总和。
//
//给你一个二叉树的根节点 root ，返回其最大路径和 。

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int left = dfs(node->left);
            int right = dfs(node->right);
            // 当前节点的最大子树和
            int maxSubtreeSum = max({left, right, 0}) + node->val;
            // 当前节点的最大路径和, 等于当前节点值 + 左子树最大子树和 + 右子树最大子树和
            int maxPathSum = node->val + max({left, 0}) + max({right, 0});
            ans = max(ans, maxPathSum);
            return maxSubtreeSum;
        };
        dfs(root);
        return ans;
    }
};
