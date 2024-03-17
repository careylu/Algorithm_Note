// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 3/17/24
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include<limits.h>
using namespace std;

// 优先队列做法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (q.size() < k) {
                q.push(nums[i]);
            } else {
                if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        return q.top();
    }
};


// 快速排序
int partition(vector<int>& nums, int left, int right) {
    int cl =  left, cr = right;
    int idx = left;
    while (idx < cr) {
        if (nums[idx] > nums[right]) {
            swap(nums[idx++], nums[++cl]);
        } else if (nums[idx] < nums[right]) {
            swap(nums[idx], nums[--cr]);
        } else {
            idx++;
        }
    }
    swap(nums[cr++], nums[right]);
    return cl - left + 1;
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = n-1;
    while (left < right) {
        int randIdx = rand() % (right - left + 1);
        swap(nums[left+randIdx], nums[right]);
        // 左边部分的个数
        int cnt = partition(nums, left, right) + 1;
        if (cnt > k) {
            right = left + cnt - 1;
        } else if (cnt < k) {
            left = left + cnt;
            k -= cnt;
        } else {
            return nums[left + cnt - 1];
        }
    }
    return nums[left];
}