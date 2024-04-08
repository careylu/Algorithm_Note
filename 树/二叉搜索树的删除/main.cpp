// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/8/24

// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
// 返回二叉搜索树（有可能被更新）的根节点的引用。

//当需要在二叉搜索树中删除一个节点时，我们需要考虑以下几种情况：

//1. 节点不存在：如果树为空，或者没有找到要删除的节点，什么也不做，直接返回 null 或原节点。
//2. 节点为叶子节点或只有一个子节点：这种情况比较简单。
//如果要删除的节点没有左子树，我们可以直接用其右子树替代该节点。
//如果没有右子树，则用左子树替代。
//这实质上是将要删除节点的父节点直接连接到要删除节点的子节点上。
//3. 节点既有左子树又有右子树：这种情况稍微复杂一点。
//首先，找到要删除节点右子树中的最小节点（或左子树中的最大节点），这个节点将替代要删除的节点。
//然后，将要删除节点的值替换为找到的最小（或最大）节点的值。
//最后，删除原右子树中的最小节点（或左子树中的最大节点），因为它已经被移动到了要删除的节点的位置。
//
//
//deleteNode(TreeNode root, int key) 方法是主要的逻辑实现，它递归地在二叉树中查找并删除指定值的节点。
//
//如果找到了需要删除的节点 root.val == key，根据上面的情况进行处理：
//
//1. 如果节点的左子树或右子树为空，直接用存在的子树替换当前节点。
//
//2. 如果节点既有左子树又有右子树，则需要找到右子树的最小节点（通过 findMinNode(TreeNode node) 方法），用这个最小节点的值替换当前节点的值，然后删除右子树中的这个最小节点。
//
//3. 如果当前节点的值小于需要删除的值，则在右子树中继续查找；如果大于，则在左子树中查找。
//
//
//findMinNode(TreeNode node) 方法用于找到以 node 为根的子树中的最小值节点。由于二叉搜索树的性质，这个最小值节点肯定在最左边，因此通过不断访问左子节点直到 null 即可找到最小值节点。


// 删除二叉搜索树中的节点（ LeetCode 450 ）:https://leetcode-cn.com/problems/delete-node-in-a-bst/
#include <iostream>
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
// LeetCode450 题解
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // root->val == key
        if(root->left == nullptr && root->right == nullptr)
            return nullptr;
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        // root->left != nullptr && root->right != nullptr(左右节点都在)
        TreeNode* successor = root->right;
        while(successor->left)
        {
            successor = successor->left;
        }
        root->right = deleteNode(root->right, successor->val);
        successor->left = root->left;
        successor->right = root->right;
        return successor;
    }
};

// 程序员小灰文章解法
//class Solution {
//public:
//    TreeNode deleteNode(TreeNode root, int key) {
//
//        // 1、如果 root 为空，那么直接返回空
//        if (root == NULL) return NULL;
//
//        // 2、如果 root 的节点值等于需要删除的值，那么需要根据以下几种情况进行处理
//        if (root.val == key) {
//
//            // 情况 1：当前节点的左子树为空，那么当前节点 root 由 root 的右子树占位就行
//            // 比如 key 为 7
//            //       6
//            //     /   \
//            //    2     7
//            //           \
//            //            8
//            // 直接将以 8 作为根节点的二叉树挪到 7 的位置
//            //       6
//            //     /   \
//            //    2     8
//            if (root.left == NULL) return root.right;
//
//            // 情况 2：当前节点的右子树为空，那么当前节点 root 由 root 的左子树占位就行
//            // 比如 key 为 2
//            //       6
//            //     /   \
//            //    2     7
//            //   /
//            //  1
//            // 直接将以 1 作为根节点的二叉树挪到 2 的位置
//            //       6
//            //     /   \
//            //    1     7
//            if (root.right == NULL) return root.left;
//
//            // 情况 3：被删除节点既有左子树，又有右子树
//            // 比如 key 为 2
//            //          5
//            //       /     \
//            //      2       6
//            //    /   \       \
//            //   1     4       7
//            //        /
//            //       3
//            // 需要找到右子树最小的值，或者左子树中最大的值
//            // 这里我们去找右子树最小的值，为 3
//            TreeNode minNodeOfRight = findMinNode(root.right);
//
//            // 找到右子树最小的值之后，修改当前节点 root 的值为右子树最小的值
//            root.val = minNodeOfRight.val;
//
//            // 同时，记得删除掉 root 的右子树最小的值之
//            // 删除操作就是以 root 作为根节点，key 为右子树最小的值进行删除
//            root.right = deleteNode(root.right, minNodeOfRight.val);
//
//            // 3、如果 root 的节点值小于需要删除的值，那么就在 root 的右子树中去查找
//        } else if (root.val < key) {
//            // 在 root 的右子树中去查找并删除 key
//            root.right = deleteNode(root.right, key);
//
//            // 4、如果 root 的节点值大于需要删除的值，那么就在 root 的左子树中去查找
//        } else if (root.val > key) {
//            // 在 root 的左子树中去查找并删除 key
//            root.left = deleteNode(root.left, key);
//        }
//
//        // 最后返回需要已经删除了 key 的二叉树的根节点
//        return root;
//    }
//
//    // 通过 findMinNode ，可以找到二叉搜索树中最小的元素
//    TreeNode findMinNode(TreeNode node) {
//
//        // 由于二叉搜索树，左子树所有元素的值都小于根节点的值
//        // 所以可以不断的查找，直到为叶子节点，那么就找到了
//        while (node.left != NULL) {
//            // 不断的去查找当前节点的左子树
//            node = node.left;
//        }
//
//        // 返回当前二叉搜索树中最小的元素
//        return node;
//    }
//};