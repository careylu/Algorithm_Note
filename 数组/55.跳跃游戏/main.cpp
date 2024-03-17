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

bool canJump(vector<int>& nums) {
    int maxDis = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > maxDis) {
            return false;
        }
        maxDis = max(maxDis, i + nums[i]);
    }
    return true;
}
