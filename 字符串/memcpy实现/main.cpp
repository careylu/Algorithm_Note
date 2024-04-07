// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/7/24
#include<iostream>
using namespace std;

// memcpy中dst和src中的区域不能重叠，否则会出现未知结果。
// 函数没做任何内存的处理，内存是否重叠由程序员自己控制。

// 实现memcpy库函数
void* memcpy(void *dst, const void *src, size_t count)
{
    // 容错处理
    if (dst == NULL || src == NULL)
        return NULL;
    unsigned char *pdst = (unsigned char *)dst;
    const unsigned char *psrc = (const unsigned char *)src;
    // 判断内存是否重叠
    bool flag1 = (pdst >= psrc && pdst < psrc + count);
    bool flag2 = (psrc >= pdst && psrc < pdst + count);
    if (flag1 || flag2) {
        cout<<"内存重叠"<<endl;
        return NULL;
    }
    // 拷贝
    while (count--) {
        *pdst = *psrc;
        pdst++;
        psrc++;
    }
    return dst;
}

int main() {
    char c1[] = "hello world";
    memcpy(c1+3, c1, 9);
    cout<<"memcpy result:"<<c1<<endl;
    char c2[] = "love you";
    memcpy(c1, c2, 8);
    cout<<"memcpy result:"<<c1<<endl;
}