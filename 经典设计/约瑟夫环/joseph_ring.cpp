// Copyright 2024, Tencent Inc.
// Author: careylu
// Date: 4/9/24

//描述：共有n个人报数，报到m号的人删除

// 公式法
//解法步骤：
//1，计算数组下标公式：i =（i + m-1）％n，其中i表示删除的下标号;
//2，将i到n之间的元素向前移动一位，将i位置对应的元素放到a [n-1]
//3，利用reverse()函数将数组翻转后输出

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int i,j,n,m,a[1000],t,len;
//    cout<<"please input n(总人数) and m(删除的数):";
//    cin>>n>>m;
//    len = n;
//    for(i=0;i<n;i++)
//        a[i] = i+1;
//    i=0;
//    while(n>1)
//    {
//        i = (i+m-1)%n;//计算需要移动的节点
//        t = a[i];
//        for(j=i;j<n-1;j++)//移动i后面的节点
//            a[j]=a[j+1];
//        a[j]=t;// 将i放到新数组的末尾
//        n--;
//    }
//    reverse(a,a+len);
//    cout<<"删除序列:"<<endl;
//    for(i=0;i<len;i++)
//        cout<<a[i]<<" ";
//    return 0;
//}



// 辅助数组实现

#include<iostream>
using namespace std;

int main()
{
    int a[1000], b[1000], n = 5, m = 2, i, k = 0, j = 0;
    for (i = 0; i < n; i++)
        a[i] = i + 1;
    while (j != n) {
        for (i = 0; i < n; i++) {
            if (a[i] == 0) continue;    // 跳过已经出队的元素
            k++;
            if (k != m) continue;
            // k == m 的处理逻辑
            b[j++] = a[i];  // b数组存储出队顺序
            a[i] = 0;   // 出队后，该元素置为0
            k = 0;      // 重置k值，循环计算到m
        }
    }
    for (i = 0; i < n; i++)
        cout << b[i] << " ";
    return 0;
}


