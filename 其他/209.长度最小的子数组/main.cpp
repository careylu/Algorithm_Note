// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

//题目描述（双指针滑动窗口）
//
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0;
        int length = nums.size();
        int sum = 0;
        int result = length + 1;    // 整个数组都不符合条件
        for (int j = 0; j < length; j++) {
            sum += nums[j];
            while (sum >= target) {
                int subLength = j - i + 1;
                if (subLength < result)
                    result = subLength;
                sum -= nums[i];
                i++;
            }
        }

        if (result == length + 1)
            return 0;
        else
            return result;
    }
};

