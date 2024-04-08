// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/8/24

#include <iostream>
using namespace std;
typedef int ElemType;
void AdjustDown(ElemType A[], int k, int len)
{
    int select = A[k];  // rc为需要筛选的值
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1]) // i为左右孩子中较大的一个
            i++;
        if (select >= A[i]) // 筛选完毕，找到插入位置
            break;
        A[k] = A[i];
        k = i;
    }
    A[k] = select;  // 插入
}

void BuildMaxHeap(ElemType A[], int len)
{
    for (int i = len / 2; i > 0; i--)
        AdjustDown(A, i, len);
}

void HeapSort(ElemType A[], int len)
{
    BuildMaxHeap(A, len);
    for (int i = len; i > 1; i--) {
        swap(A[i], A[1]);
        AdjustDown(A, 1, i - 1);
    }
}

int main()
{
    // 该算法只排序1...n位置的值，不对a[0]排序
    int a[] = {-1,8,3,6,4,0, 11,1};
    int n = sizeof(a)/sizeof(a[0]);
    HeapSort(a, n-1);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<endl;
    }
    return 0;
}