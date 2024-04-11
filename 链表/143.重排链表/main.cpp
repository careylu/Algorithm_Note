// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/10/24

// 题目描述：

//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//
//L0 → L1 → … → L~n - 1~ → Ln 请将其重新排列后变为：
//
//L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → … 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//这道题实际是三道题目综合：
//
//1. 找到链表的中点：
//使用快慢指针法，创建两个指针 slow 和 fast，初始时都指向链表头节点 head。
//同时移动这两个指针，slow 指针每次移动一步，fast 指针每次移动两步。当 fast 指针到达链表尾部时，slow 指针恰好位于链表的中点。
//2. 反转链表的后半部分：
//从中点节点 slow 开始，将链表后半部分反转。可以使用迭代或递归方法进行反转。
//反转后，slow 指针指向新的子链表头节点。
//3. 合并两个链表：
//初始化两个指针 p1 和 p2，分别指向原始链表的头节点 head 和反转后链表的头节点 slow。
//依次从两个链表中取出一个节点，将它们按照题目要求的顺序连接起来。
//不断重复上述过程，直到两个链表中的节点都被连接完毕。


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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        // 找到链表中点并将后半部分链表翻转
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        mid = reverse(mid);

        // 将前半部分链表和翻转后的后半部分链表交替合并
        ListNode *p1 = head, *p2 = mid;
        while(p1 != nullptr && p2 != nullptr) {
            ListNode *tmp1 = p1->next, *tmp2 = p2->next;
            // 等同操作：
            // L0 → Ln → L1
            // L1 → Ln-1 → L2
            // L2 → Ln-2 → L3
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr, *next = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
