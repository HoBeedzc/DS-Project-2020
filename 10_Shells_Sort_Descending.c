/*
Author: Hobee (LZQ)
Date: 2019.5.19
Problem: 10 Shell's Sort with Descending Qrder
More info: https://github.com/HoBeedzc/ds_project
Website: http://blog.hobeedzc.cn/
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Shell's Sort问题
// 1.请确保您的输入使问题有意义
// 2.输入的节点个数请不要超过9999.
// 3.序列采用数组方式存储，且第零位为数据长度。

# include<stdio.h>

int Show(int *A);
int Shell_with_bubble(int *A);

int main()
{int A[9999] = {0};
    printf("Enter the length of list...\n");
    scanf("%d",&A[0]);
    printf("Enter the value of every node, splited by space...\n");
    for (int i = 1; i <= A[0];i++) scanf("%d", &A[i]);
    Shell_with_bubble(A);
    Show(A);
    return 0;
}

int Shell_with_insertion(int *A) //内嵌插排的希尔排序
{
    return 0;
} 

int Shell_with_bubble(int *A) //内嵌冒泡的希尔排序
{
    int n = A[0], d = n, flag = 1, temp;
    while(d!=1)
    {
        d = d / 2;
        flag = 1;
        for (int i = 1; i <= n - d;i++)
        {
            if (A[i]<A[i + d])
            {
                temp = A[i];
                A[i] = A[i + d];
                A[i + d] = temp;
                flag = 0;
            }
        }
        if (flag) break;
    }
    return 0;
}

int Show(int *A)
{
    printf("After Sorting...\n");
    for (int i = 1; i <= A[0];i++) printf("%4d", A[i]);
    printf("\n");
    return 0;
}