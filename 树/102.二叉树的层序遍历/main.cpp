// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

//题目描述
//
//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。（即逐层地，从左到右访问所有节点）。

//解题思路
//
//层序遍历一般都用迭代来处理：
//
//定义一个双端队列 q，将根节点 root 入队。同时定义一个当前节点指针 cur，一个临时数组 tmp，以及一个结果数组 ans。
//
//判断根节点是否为空。如果根节点为空，说明树为空，直接返回结果数组 ans。
//
//进入循环，当队列不为空时，执行以下步骤：
//
//a. 获取当前队列的大小 sz，这表示当前层的节点数量。
//
//b. 清空临时数组 tmp。
//
//c. 遍历当前层的所有节点，执行以下操作：
//
//从队列头部取出节点（队首），将其值添加到临时数组 tmp 中。
//如果当前节点的左子节点不为空，将左子节点加入队列尾部（队尾）。
//如果当前节点的右子节点不为空，将右子节点加入队列尾部（队尾）。
//d. 将临时数组 tmp 添加到结果数组 ans 中。
//
//循环结束后，返回结果数组 ans。

#include <iostream>
#include <queue>
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

// 迭代(广度优先遍历)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

//// 递归（深度优先遍历）
//class Solution {
//public:
//    vector <vector<int>> res;
//
//    vector <vector<int>> levelOrder(TreeNode *root) {
//        res.clear();
//        dfs(root, 0);
//        return res;
//    }
//
//    void dfs(TreeNode *root, int level) {
//        if (root) {
//            if (res.size() == level) {
//                res.push_back({});
//            }
//            res[level].push_back(root->val);
//            dfs(root->left, level + 1);
//            dfs(root->right, level + 1);
//        }
//    }
//};
