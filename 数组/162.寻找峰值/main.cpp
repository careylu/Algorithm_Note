// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 3/16/24
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

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if ((m == n - 1 || nums[m] > nums[m + 1]) && (m == 0 || nums[m - 1] > nums[m])) {
            r = m;
        } else if ((m == 0 || nums[m] > nums[m - 1]) && (m == n - 1 || nums[m + 1] > nums[m])) {
            l = m + 1;
        } else if ((m == 0 || nums[m] > nums[m - 1]) && (m == n - 1 || nums[m] > nums[m + 1])) {
            return m;
        } else {
            l++;
        }
    }
    return l;
}
