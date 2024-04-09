// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/8/24

// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

// 主要思路是利用单调栈（monotonic stack）来解决问题。单调栈是一种数据结构，它的特点是栈中元素始终保持单调性（本例中是单调递减）
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        int n = temperatures.size();
        std::vector<int> ans(n, 0);
        std::stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                int idx = st.top();
                ans[idx] = i - idx;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
