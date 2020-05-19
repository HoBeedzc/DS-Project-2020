/*
Author: Hobee (LZQ)
Date: 2019.5.19
Problem: 09 Quick Sort with Ascending Order
More info: https://github.com/HoBeedzc/ds_project
Website: http://blog.hobeedzc.cn/
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Quick Sort问题
// 1.请确保您的输入使问题有意义
// 2.输入的节点个数请不要超过9999
// 3.序列采用数组方式存储，且第零位为数据长度。

# include<stdio.h>

int Every_step_exchenge(int *A, int m, int n);
int Show(int *A);

int main()
{
    int A[9999] = {0};
    printf("Enter the length of list...\n");
    scanf("%d",&A[0]);
    printf("Enter the value of every node, splited by space...\n");
    for (int i = 1; i <= A[0];i++) scanf("%d", &A[i]);
    Every_step_exchenge(A, 1, A[0]);
    Show(A);
    return 0;
}

int Every_step_exchenge(int *A, int m, int n) //每步交换法
{
    int i = m, j = n, temp;
    if (i>=j) return 0;
    while(1)
    {
        while(A[i] <= A[j]) j--;
        if (i>=j)
        {
            Every_step_exchenge(A, m, i - 1);
            Every_step_exchenge(A, i + 1, n);
            return 0;
        }
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        while (A[i] <= A[j]) i++;
        if (i>=j)
        {
            Every_step_exchenge(A, m, j - 1);
            Every_step_exchenge(A, j + 1, n);
            return 0;
        }
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int Continuous_exchange(int *A) //持续交换法
{
    return 0;
}

int Left_right_exchange(int *A) //左右交换法
{
    return 0;
}

int Show(int *A)
{
    printf("After Sorting...\n");
    for (int i = 1; i <= A[0];i++) printf("%4d", A[i]);
    printf("\n");
    return 0;
}