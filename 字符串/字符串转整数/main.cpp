// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/7/24

// 字符串转化为整数，atoi()函数实现
// 1. 指针为空
// 2. 空字符处理
// 3. 正负号处理
// 4. 溢出处理
// 5. 异常字符处理

#include <iostream>
enum ret { kvalid=0, kinvalid };    // 是否有非法输入的标记
int status = kvalid;

long long Strtointcode(const char* digit, bool minus)
{
    long long num = 0;
    while (*digit != '\0')
    {
        if (*digit >= '0' && *digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');
            // !、>、&& 运算符优先级由高到低排列，判断超过了num存储的最大值和最小值
            if ((!minus&&num > 0x7FFFFFFF) || (minus&&num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }

    if (*digit == '\0')
        status = kvalid;
    return num;
}
int Strtoint(const char* str)
{
    status = kinvalid;
    long long num = 0;
    if (str != NULL && *str != '\0')
    {
        // 判断正负号
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            str++;
            minus = true;
        }

        if (*str != '\0')
            num = Strtointcode(str, minus);
    }
    return (int)num;
}

int main()
{
    char arr[20];
    int ret = 0;
    printf("请输入您要转化的字符串：\n");
    scanf("%s", arr);
    ret = Strtoint(arr);
    if (kvalid == status)
    {
        printf("%d\n", ret);
    }
    else
    {
        printf("输入非法\n");
        printf("%d\n", ret);
    }
    return 0;
}


