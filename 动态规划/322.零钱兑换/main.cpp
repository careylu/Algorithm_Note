// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

//题目描述
//
//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//
//你可以认为每种硬币的数量是无限的。

//解题思路：
//
//可以先想2维dp,dp[i][j]代表以第i位为底，凑成金额为j的最少硬币数。
//易得要么不拿，即dp[i - 1][j]，要么在dp[i][j - coin[i - 1]]的基础上再拿一个，凑成金额为j。也就是dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i - 1]])
//这时候可以画个表，横轴是i，纵轴是j，看一下dp[i][j]的递推式，容易看出来dp[i][j]是可以状态压缩的。
//每次i往前遍历一位，i之前的dp其实并没有用到，可以把i压缩掉，变成一维dp。


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j >= coins[i - 1]) { // 为什么是coins[i-1]是因为循环从1开始的，需要和数组的位序值比较
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);   // dp[j]代表凑成j需要的最少硬币数
                }
            }
        }
        if(dp[amount] == 1e9) return -1;
        return dp[amount];
    }
};
