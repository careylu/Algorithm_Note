// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/12/24

// 题目描述：
//
//给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。
//第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
//你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

//解题思路
//
//特殊情况处理：如果链表为空，直接返回空指针。
//初始化指针：使用两个指针 odd 和 even 分别指向链表的第一个节点（奇数头节点）和第二个节点（偶数头节点）。同时，用一个额外的指针 evenHead 保存偶数头节点的位置，以便最后将奇数节点的尾部与偶数节点的头部相连。
//遍历链表：使用一个循环遍历链表，直到 even 节点为空或 even->next 节点为空。在每次循环中，我们将当前的奇数节点 odd 的 next 指针指向下一个奇数节点（即 odd->next->next），并将当前的偶数节点 even 的 next 指针指向下一个偶数节点（即 even->next->next）。然后更新 odd 和 even 节点为它们的下一个奇数节点和偶数节点。
//连接奇数节点和偶数节点：当遍历完成后，奇数节点的尾部和偶数节点的头部还没有连接。将奇数节点的尾部（odd）的 next 指针指向偶数头节点（evenHead）。
//返回结果：返回链表的头节点（head），此时链表已经将奇数位置的节点和偶数位置的节点分离。


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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // 记录偶节点的首节点，方便后续连接奇节点的尾节点

        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
