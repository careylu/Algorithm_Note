// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 9/20/24

// 题目描述：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        ListNode* p1 = list1, *p2 = list2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        cur->next = p1 != nullptr ? p1 : p2;
        return dummy.next;
    }
};
