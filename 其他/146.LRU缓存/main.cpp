// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

// 题目描述
//
// 请你设计并实现一个满足 LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类： LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
// 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


// 解题思路：LRU缓存是考察数据结构能力的题目，它本质上由一个双端链表与一个hash表构成。
// 双端链表用于存放具体的键值对，hash表的作用是能根据key以O(1)的复杂度找到相应的键值对。注意一下链表的增删，容易在这里出错。

struct node{
    int key;
    int val;
    node* pre;
    node* next;
    node(int _key, int _val): key(_key), val(_val) {

    }
};
class LRUCache {
public:
    unordered_map<int, node*> hash;
    node* begin;
    node* end;
    int capacity;
    int size = 0;
    LRUCache(int _capacity) {
        // begin、end都为虚拟节点
        begin = new node(-1, -1);
        end = new node(-1, -1);
        begin->next = end;
        end->pre = begin;
        capacity = _capacity;
    }

    // 每次查询或者插入都表示最近使用，更新节点的位置靠前
    void add(node* pre, node* cur) {
        node* next = pre->next;
        pre->next = cur;
        cur->pre = pre;
        cur->next = next;
        next->pre = cur;
    }

    int get(int key) {
        if(!hash.count(key)) {
            return -1;
        }
        node* cur = hash[key];
        node* pre = cur->pre;
        node* next = cur->next;
        pre->next = next;
        next->pre = pre;
        add(begin, cur);
        return cur->val;
    }

    void put(int key, int value) {
        if(hash.count(key)) {
            hash[key]->val = value;
            get(key);
            return;
        }
        if(size >= capacity) {
            node* cur = end->pre;   // 删除尾节点
            node* pre = cur->pre;
            node* next = cur->next;
            pre->next = next;
            next->pre = pre;
            hash.erase(cur->key);
            size--;
        }
        node* cur = new node(key, value);
        add(begin, cur);
        hash[key] = cur;
        size++;
    }
};
