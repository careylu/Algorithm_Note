// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

// 题目描述：
//
// 给定一个已排序的链表的头head，删除所有重复的元素，返回已排序的链表。


//解题思路
//
//使用一个辅助指针遍历链表，同时维护一个指针指向当前不重复节点的最后一个节点。以下是详细的步骤：
//
//1、创建一个虚拟头节点 dummy，令 dummy.next = head。这样可以简化对头节点的处理。
//
//2、初始化两个指针 prev 和 cur，分别指向虚拟头节点 dummy 和头节点 head。
//
//3、遍历链表，直到 cur 为 None：
//
//使用一个循环，检查当前节点 cur 和下一个节点 cur.next 是否具有相同的值。如果相同，将 cur 向前移动，跳过具有相同值的节点。
//
//如果 prev.next 与 cur 不相等，说明 prev.next 和 cur 之间存在重复的节点，需要将这些重复节点删除。将 prev.next 指向 cur.next，这样就跳过了这些重复节点。
//
//如果 prev.next 与 cur 相等，说明当前节点不重复，将 prev 指向 cur。
//
//移动 cur 指针，指向下一个节点 cur.next。
//
//4、遍历结束后，返回 dummy.next，即为新链表的头节点。

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur) {
            // 跳过重复的元素
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            // 处理prev指针，
            if (prev->next != cur) {
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
