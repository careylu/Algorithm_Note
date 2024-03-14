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

// 题目描述：
// 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

// 解题思路：
// 异或经典题目，两个数相同，异或为0。
// 运算规则：0^0=0；   0^1=1；   1^0=1；   1^1=0；
// 所以把所有数全异或一遍，剩下的就是只出现一次的数。
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