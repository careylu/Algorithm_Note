// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/8/24

// to_string()函数实现
#include <iostream>
using namespace std;
#define max 100
string to_String(int n)
{
    int m = n;
    char s[max];
    char ss[max];
    int i=0, j=0;
    if (n < 0)
    {
        m = -m;
        j = 1;
        ss[0] = '-';
    }
    while (m > 0)
    {
        s[i++] = m % 10 + '0';
        m = m / 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
        ss[j++] = s[i--];
    }
    ss[j] = '\0';
    return ss;
}

int main()
{
    cout << "请输入整数:";
    int m;
    cin >> m;
    string s = to_String(m) + "abc";
    cout << s << endl;
    return 0;
}