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
int Continuous_exchange(int *A, int m, int n);
int Left_right_exchange(int *A, int m, int n);
int Show(int *A);

int main()
{
    int A[9999] = {0}, B[9999] = {0}, C[9999] = {0};
    printf("Enter the length of list...\n");
    scanf("%d",&A[0]);
    printf("Enter the value of every node, splited by space...\n");
    for (int i = 1; i <= A[0];i++) scanf("%d", &A[i]);
    for (int i = 0; i <= A[0];i++) B[i] = A[i];
    for (int i = 0; i <= A[0];i++) C[i] = A[i];
    Every_step_exchenge(A, 1, A[0]);
    Continuous_exchange(B, 1, B[0]);
    Left_right_exchange(C, 1, C[0]);
    printf("Using every step exchenge...\n");
    Show(A);
    printf("\n");
    printf("Using continuous exchenge...\n");
    Show(B);
    printf("\n");
    printf("Using left right exchenge...\n");
    Show(C);
    printf("\n");
    return 0;
}

int Every_step_exchenge(int *A, int m, int n) //每步交换法
{
    int i = m, j = n, temp;
    if (i>=j) return 0;
    while(1)
    {
        while(i<j && A[i] <= A[j]) j--;
        if (i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        while (i<j && A[i] <= A[j]) i++;
        if (i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        if(i==j)
        {
            Every_step_exchenge(A, m, j - 1);
            Every_step_exchenge(A, j + 1, n);
            return 0;
        }
    }
}

int Continuous_exchange(int *A, int m, int n) //持续交换法
{
    int i = m, j = n, temp = A[m];
    if (i>=j) return 0;
    while(1)
    {
        while(i<j && temp <= A[j]) j--;
        if (i<j) A[i] = A[j];
        while (i<j && A[i] <= temp) i++;
        if (i<j) A[j] = A[i];
        if (i==j)
        {
            A[i] = temp;
            Continuous_exchange(A, m, j - 1);
            Continuous_exchange(A, j + 1, n);
            return 0;
        }
    }
}

int Left_right_exchange(int *A, int m, int n) //左右交换法
{
    int i = m + 1, j = n, temp;
    if (i>j) return 0;
    while(1)
    {
        while(i<j && A[m] <= A[j]) j--;
        while (i<j && A[i] <= A[m]) i++;
        if (i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        if (i==j)
        {
            if (n == m + 1 && A[m] < A[n]) i = m;
            else if (A[m] < A[i]) i--;
            temp = A[m];
            A[m] = A[i];
            A[i] = temp;
            Left_right_exchange(A, m, i - 1);
            Left_right_exchange(A, i + 1, n);
            return 0;
        }
    }
}

int Show(int *A)
{
    printf("After Sorting...\n");
    for (int i = 1; i <= A[0];i++) printf("%4d", A[i]);
    printf("\n");
    return 0;
}