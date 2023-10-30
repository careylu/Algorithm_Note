// Copyright 2023, Tencent Inc.
// Author: careylu
// Date: 10/29/23
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

int singleNumber(vector<int>& nums)
{
    int res = 0;
    for (int num : nums)
    {
        res ^= num;
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3, 4, 4};
    printf("res: %d", singleNumber(nums));
    return 0;
}