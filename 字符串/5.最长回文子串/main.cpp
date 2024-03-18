// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 3/18/24
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

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            string s1 = isPalding(s, i, i);
            string s2 = isPalding(s, i, i + 1);
            if (s1.length() > res.length()) {
                res = s1;
            }
            if (s2.length() > res.length()) {
                res = s2;
            }
        }
        return res;
    }

    string isPalding(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1, right-1-left);
    }
};
