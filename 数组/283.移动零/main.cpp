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

void moveZeroes(vector<int>& nums) {
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] != 0) {
            nums[l++] = nums[r];
        }
    }
    while (l < nums.size()) {
        nums[l++] = 0;
    }
    return;
}
