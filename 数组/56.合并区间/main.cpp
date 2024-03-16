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


vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> t = {intervals[0][0], intervals[0][1]};
    for (int i = 1; i < intervals.size(); i++) {
        if (t[1] >= intervals[i][0]) {
            t[1] = max(t[1], intervals[i][1]);
        } else {
            ans.emplace_back(t);
            t[0] = intervals[i][0];
            t[1] = intervals[i][1];
        }
    }//_for
    ans.emplace_back(t);
    return ans;
}