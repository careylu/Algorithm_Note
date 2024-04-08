// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/8/24
#include <iostream>
using namespace std;
typedef int ElemType;

int Partition(ElemType A[], int low, int high)
{
    ElemType pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low]= pivot;
    return low;
}
void QuickSort(ElemType A[], int low, int high)
{
    if (low < high)
    {
        int pivot_pos = Partition(A, low, high);
        QuickSort(A, low, pivot_pos-1);
        QuickSort(A, pivot_pos+1, high);
    }
}

int main()
{
    int a[] = {2,8,3,6,4,0, 11, 1};
    int n = sizeof(a)/sizeof(a[0]);
    QuickSort(a, 0, n-1);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<endl;
    }
    return 0;
}