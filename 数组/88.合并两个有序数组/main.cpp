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


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int last = m + n - 1;
    m--;
    n--;
    while(m>=0 && n>=0)
    {
        if (nums1[m] > nums2[n])
            nums1[last--] = nums1[m--];
        else
            nums1[last--] = nums2[n--];
    }
    // 如果nums2先调整完毕，剩下的nums1自然递增有序，不需要额外操作
    // 如果nums1先调整完毕，需要把nums2剩下的元素依次调整到nums1中
    while(n>=0)
    {
        nums1[last--] = nums2[n--];
    }
}