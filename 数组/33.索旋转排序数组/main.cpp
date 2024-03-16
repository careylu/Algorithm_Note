// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 3/15/24
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


// 题目描述：
// 整数数组nums按升序排列，数组中的值互不相同。
// 在传递给函数之前，nums在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，使数组变为
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标从0开始计数）。
// 例如，[0,1,2,4,5,6,7] 在下标3处经旋转后可能变为[4,5,6,7,0,1,2]。
// 给你旋转后的数组nums和一个整数target，如果nums中存在这个目标值target，则返回它的下标，否则返回 -1 。


// 解题思路：
// 二分的经典题目，时间复杂度就是O(logn)

class Solution {
public:
    int search_binary(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            // 目标值在前半段有序数组中找
            if (target > nums[n - 1]) {
                // m值还没到前半段有序数组（无脑冲，因为前面的if条件判定target值一定在前半段有序数组中）
                // 或者已经到了前半段但是m值还在target值的右边，需要往左折半缩进
                if (nums[m] <= nums[n - 1] || nums[m] >= target) {
                    r = m;
                } else {  // m值已经到了前半段有序数组，且m值在target值的左边，需要往右折半缩进
                    l = m + 1;
                }
            } else {  // 目标值在后半段有序数组中找
                // m值在后半段有序数组中，且m值在target值的右边，需要向左缩进
                if (nums[m] <= nums[n - 1] && nums[m] >= target) {
                    r = m;
                } else {    // m值还在前半段有序数组，或者m值在target值左边，需要向右折半缩进
                    l = m + 1;
                }
            }
        }//_while
        if (nums[l] == target)
            return l;
        else
            return -1;
    }//_search_binary
};