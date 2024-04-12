// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/11/24

//题目描述：
//
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。


//解题思路
//
//这道题也是一个考察链表操作的问题，两两交换节点就是以3个为一组进行操作，当剩下节点不足三个时，直接返回。链表操作中很多节点连接关系不注意就变化了，可以先把每个操作的节点存下来，这样不容易出错。具体操作如下：
//
//首先检查链表是否为空或只有一个元素，如果满足这些条件，则不需要进行任何交换，直接返回链表头节点。
//
//创建一个虚拟头节点 dummy，并将其 next 指针指向链表头节点。这样可以简化对头节点的处理。
//
//初始化一个指针 cur，指向虚拟头节点。用于遍历链表。
//
//使用一个循环来遍历链表，直到 cur 的下一个节点或下下个节点为空，表示已经处理完链表中的所有节点对。
//
//在循环内部，首先记录两个相邻节点的指针：even 指向当前 cur 的下一个节点，odd 指向当前 cur 的下下个节点。这里，我们需要交换 even 和 odd 指向的节点。
//更新 even 节点的 next 指针，使其指向 odd 节点的下一个节点。
//更新 cur 的 next 指针，使其指向 odd 节点。
//更新 odd 节点的 next 指针，使其指向 even 节点。
//将 cur 指针移动到 even 节点。因为 even 节点已经交换到了下一个节点对的前面，所以移动到这个位置准备处理下一个节点对。
//
//循环结束后，返回虚拟头节点 dummy 的 next 指针，即新链表的头节点。


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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // 必须声明一个虚拟节点指向头节点的前一个节点，方面对头节点之后节点操作
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        // 当不满足两个节点时，停止循环不再交换
        while (cur->next && cur->next->next) {
            ListNode* even = cur->next;
            ListNode* odd = cur->next->next;
            even->next = odd->next;
            cur->next = odd;
            odd->next = even;
            cur = even;
        }
        return dummy->next;
    }
};

