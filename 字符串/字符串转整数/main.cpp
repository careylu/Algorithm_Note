// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/7/24

// 方案1：
// 字符串转化为整数，atoi()函数实现
// 1. 指针为空
// 2. 空字符处理
// 3. 正负号处理
// 4. 溢出处理
// 5. 异常字符处理

//#include <iostream>
//enum ret { kvalid=0, kinvalid };    // 是否有非法输入的标记
//int status = kvalid;
//
//long long Strtointcode(const char* digit, bool minus)
//{
//    long long num = 0;
//    while (*digit != '\0')
//    {
//        if (*digit >= '0' && *digit <= '9')
//        {
//            int flag = minus ? -1 : 1;
//            num = num * 10 + flag * (*digit - '0');
//            // !、>、&& 运算符优先级由高到低排列，判断超过了num存储的最大值和最小值
//            if ((!minus&&num > 0x7FFFFFFF) || (minus&&num < (signed int)0x80000000))
//            {
//                num = 0;
//                break;
//            }
//            digit++;
//        }
//        else
//        {
//            num = 0;
//            break;
//        }
//    }
//
//    if (*digit == '\0')
//        status = kvalid;
//    return num;
//}
//int Strtoint(const char* str)
//{
//    status = kinvalid;
//    long long num = 0;
//    if (str != NULL && *str != '\0')
//    {
//        // 判断正负号
//        bool minus = false;
//        if (*str == '+')
//            str++;
//        else if (*str == '-')
//        {
//            str++;
//            minus = true;
//        }
//
//        if (*str != '\0')
//            num = Strtointcode(str, minus);
//    }
//    return (int)num;
//}
//
//int main()
//{
//    char arr[20];
//    int ret = 0;
//    printf("请输入您要转化的字符串：\n");
//    scanf("%s", arr);
//    ret = Strtoint(arr);
//    if (kvalid == status)
//    {
//        printf("%d\n", ret);
//    }
//    else
//    {
//        printf("输入非法\n");
//        printf("%d\n", ret);
//    }
//    return 0;
//}


// 方案2：
// 字符串转化为整数32位，atoi()函数实现, 假设字符串无异常字符，标准的整形字符串转化
// 1. 空字符处理
// 2. 正负号处理
// 3. 范围溢出处理


#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int idx = 0, n = s.size();
        while (idx < n && s[idx] == ' ') idx++;
        int sign = 1;
        if (s[idx] == '-') {
            sign = 0;
            idx++;
        } else if (s[idx] == '+') {
            idx++;
        }
        int ans = 0;
        while (idx < n && s[idx] >= '0' && s[idx] <= '9') {
            int cur = -(s[idx] - '0');
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && cur < INT_MIN % 10)) {
                ans = INT_MIN;
                break;
            }
            idx++;
            ans = 10 * ans + cur;
        }
        if (ans == INT_MIN && sign) return INT_MAX;
        if (sign) ans = -ans;
        return ans;
    }
};