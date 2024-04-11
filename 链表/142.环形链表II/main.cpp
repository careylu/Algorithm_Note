// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/11/24

//题目描述：
//
//给定一个链表的头节点 head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。


//解题思路
//
//快慢指针的思路如下，建议直接记住做法。
//
//首先，检查输入的链表是否为空，或者只有一个元素。如果满足这两个条件之一，直接返回 nullptr，因为这种情况下链表中不可能存在环。
//定义两个指针，fast 和 slow，都初始化为指向链表头结点。fast 指针每次移动两个节点，slow 指针每次移动一个节点。
//在一个循环中，同时移动 fast 和 slow 指针。如果链表中存在环，fast 和 slow 指针最终会相遇。如果在移动过程中，fast 指针遇到了空节点，说明链表没有环，此时返回 nullptr。
//当 fast 和 slow 相遇时，说明链表中存在环。为了找到环的起始节点，将 fast 指针重新指向链表头结点，保持 slow 指针不变。
//再次开始一个循环，同时移动 fast 和 slow 指针，但这次每次都只移动一个节点。当 fast 和 slow 再次相遇时，相遇点即为环的起始节点。
//返回环的起始节点。

// 求环入口：由相遇点可以得出X、Y、L之间的关系，进而求解（见博客）

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
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast != slow) {
            return nullptr;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
