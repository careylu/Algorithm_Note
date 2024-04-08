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

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
// 这道题的思路是滑动窗口或双指针，窗口内维持的是内部没有出现重复字符，
// 我们可用一个hash表保存窗口内最长无重复子串中出现字符的下标，如果滑动到一个新的r碰到在窗口内出现的字符，
// 那么l肯定就要往前滑动到之前出现的字符下标的下一位来保证l到r之间没有重复出现的字符。算法复杂度O(n)。

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
