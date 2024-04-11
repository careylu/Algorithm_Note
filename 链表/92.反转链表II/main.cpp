// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/11/24

// 题目描述:
//
// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
// 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* cur = &dummy;
        for (int i = 1; i < left; ++i) {
            cur = cur->next;
        }

        ListNode* start = cur->next;
        ListNode* end = cur->next;
        for (int i = left; i < right; ++i) {
            end = end->next;
        }
        ListNode* next = end->next;
        end->next = nullptr;

        cur->next = reverseList(start);
        start->next = next;
        return dummy.next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
