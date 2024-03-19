// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 3/19/24
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include<limits.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int n = s.size();
    int l = 0, ans = 0;
    for (int r = 0; r < n; ++r) {
        if (hash.count(s[r])) {
            int last = hash[s[r]];
            for (int j = l; j < last; ++j) {
                hash.erase(s[j]);
            }
            l = last + 1;
        }
        hash[s[r]] = r;
        ans = max(ans, r-l+1);
    }
    return ans;
}
