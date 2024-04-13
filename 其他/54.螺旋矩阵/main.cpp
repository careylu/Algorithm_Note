// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/13/24

//题目描述:(顺时针螺旋遍历多维数组)
//
//给你一个m行n列的矩阵matrix，请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
//子数组是数组中的一个连续部分。

//解题思路：
//状态机模拟题目，我们可以定义上下左右四个方向状态为1,2,3,4；一开始方向状态为右，当右碰到边界或者已经遍历过的元素了，就将状态变成下；当下走到边界或者已经遍历过的元素了，就将状态变成左，以此类推，当所有位置都遍历完了，就可以得到的答案。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int first = 0;  // 矩阵的高
        int second = 0; // 矩阵的宽
        int count = 0;  // 遍历的元素个数计数
        int direction = 2;// 1，2，3，4分别代表上右下左
        while (count < matrix.size() * matrix[0].size()) {
            res.push_back(matrix[first][second]);
            matrix[first][second] = 101;    // -100 <= matrix[i][j] <= 100, 标记已经遍历过
            count++;
            switch (direction) {
                case 1:
                    if (first == 0 && direction == 1) direction = 2;    // 碰到边界
                    else if (direction == 1 && matrix[first - 1][second] == 101) direction = 2; // 遍历过的元素
                    break;
                case 2:
                    if (direction == 2 && second == matrix[0].size() - 1) direction = 3;
                    else if (direction == 2 && matrix[first][second + 1] == 101) direction = 3;
                    break;
                case 3:
                    if (direction == 3 && first == matrix.size() - 1) direction = 4;
                    else if (direction == 3 && matrix[first + 1][second] == 101) direction = 4;
                    break;
                case 4:
                    if (direction == 4 && second == 0) direction = 1;
                    else if (direction == 4 && matrix[first][second - 1] == 101) direction = 1;
                    break;
            }
            switch (direction) {
                case 1: // 向上
                    first -= 1;
                    break;
                case 2: // 向右
                    second += 1;
                    break;
                case 3: // 向下
                    first += 1;
                    break;
                case 4: // 向左
                    second -= 1;
                    break;
            }
        }
        return res;
    }
};
