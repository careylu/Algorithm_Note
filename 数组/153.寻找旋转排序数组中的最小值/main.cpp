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

// 旋转后数组整体保持两半段有序，依然可以用二分查找解决，时间复杂度logn
int findMin(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < nums[r]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return nums[l];
}
