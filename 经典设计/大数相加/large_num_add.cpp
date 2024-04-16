// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 2024/4/16

// 1.两个超大正整数之和,范围无限大


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string addStr(string a, string b)
{
    int length_a = a.size();
    int length_b = b.size();
    // 比较两者长度，使两者长度一致，高位补充'0'
    if (length_a < length_b)
        a = string(length_b - length_a, '0') + a;
    else
        b = string(length_a - length_b, '0') + b;

    int high_loc = 0,value = 0;
    string s;
    int length = length_a > length_b ? length_a : length_b;
    // 从个位向高位计算进位
    for (int i = length; i > 0; i--)
    {
        value = (a[i-1]-'0') + (b[i-1]-'0') + high_loc; // 忘记加进位
        if (value > 9)
        {
            s += (value-10) + '0';
            high_loc = 1;
        }
        else
        {
            s += value + '0';
            high_loc = 0;
        }
    }
    reverse(s.begin(), s.end());
    // 最后一位进位单独处理s
    if (high_loc == 1)
        s = '1' + s;
    return s;
}

int main()
{
    string a = "1005";
    string b = "99";
    cout<< addStr(a, b)<<endl;
}