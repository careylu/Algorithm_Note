// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/11/24

// 题目描述:
//
//给你一个链表的头节点 head ，判断链表中是否有环。
//
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。

//解题思路
//
//采用快慢指针法。步骤如下：
//
//初始化两个指针 slow 和 fast，都指向链表头节点 head。
//同时移动这两个指针，slow 指针每次移动一步，fast 指针每次移动两步。
//如果链表中存在环，那么快慢指针最终会相遇。如果快指针遇到 null，说明链表没有环。
//如果快慢指针相遇，返回 true，表示链表中存在环；否则，返回 false。


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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) {
            return false;
        }
        ListNode* fast = head -> next, *slow = head;
        while(fast != slow) {
            if(fast == nullptr || fast->next == nullptr) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};