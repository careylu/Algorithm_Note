// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/9/24
// 链表反转

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 解题思路一：迭代法(尾插法)

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode *cur = head, *pre= nullptr, *next = nullptr;
//        while (cur != nullptr)
//        {
//            next = cur->next;
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//        }
//        return pre;
//    }
//};

// 解题思路二：迭代法(尾插法,头结点为空的处理情况,不推荐)

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode *next,*cur;
//        cur = head->next;
//        head->next = nullptr;
//        while (cur != nullptr)
//        {
//            next = cur->next;
//            cur->next = head->next;
//            head->next = cur;
//            cur = next;
//        }
//        return head;
//    }
//};


// 解题思路三：递归法(不易理解)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* new_head = reverseList(head->next);
        head->next->next = head;    // 从后往前改变指针指向前一个节点
        head->next = nullptr;   // 相当于从后往前遍历,一直循环到第一个节点置空

        return new_head;
    }
};