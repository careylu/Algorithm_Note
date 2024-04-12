// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/12/24

// 题目描述：
//
// 给你链表的头节点head，每k个节点一组进行翻转，请你返回修改后的链表。k是一个正整数，它的值小于或等于链表的长度。
// 如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代法
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head, *temp;
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        while (count >= k) {
            // 每k个节点处理一次
            // prev 尾部节点指向
            // curr 头部节点指向
            for (int i = 1; i < k; i++) {
                temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
            prev = curr;    // prev指向已翻转部分的新尾节点
            curr = prev->next;  // curr指向下一K组未处理部分的头节点
            count -= k;
        }
        return dummy.next;
    }
};



//// 递归法
//class Solution {
//public:
//    ListNode* reverseKGroup(ListNode* head, int k) {
//        ListNode* cur = head;
//        int count = 0;
//        while (cur != nullptr && count < k) {
//            cur = cur->next;
//            count++;
//        }
//        // 结束后，cur指向第K个元素的后一个节点
//        if (count == k) {
//            ListNode* newHead = reverse(head, cur); // 将K个节点一组翻转
//            head->next = reverseKGroup(cur, k); // 继续翻转下一K组，cur即为下一个循环的头节点
//            return newHead; // 返回头节点
//        }
//        return head;    // 未形成K个节点一组，直接不翻转返回头节点
//    }
//
//    // start为头节点，end为翻转节点的尾节点的后一个节点
//    ListNode* reverse(ListNode* start, ListNode* end) {
//        ListNode* prev = nullptr, *curr = start;
//        while (curr != end) {
//            ListNode* next = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = next;
//        }
//        return prev;
//    }
//};

