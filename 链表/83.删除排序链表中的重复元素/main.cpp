// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/12/24

//题目描述：
//
//给定一个已排序的链表的头head，删除所有重复的元素，使每个元素只出现一次。返回已排序的链表。


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//迭代法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

//// 递归法
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//
//        head->next = deleteDuplicates(head->next);
//
//        if (head->val == head->next->val) {
//            head = head->next;
//        }
//
//        return head;
//    }
//};
