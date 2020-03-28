/*
Author: Hobee (LZQ)
Date: 2019.3.28
Problem: 05 Addition of Sparse Matrix
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Addition of Sparse Matrix问题
// 1.请确保输入的数据合法
// 2.矩阵均以三元组形式储存
// 3.本算法单个三元组最大储存元素个数不要超过332个

# include<stdio.h>
# include<stdlib.h>

# define MAX_SIZE 999

typedef int *Triple;

int Input_for_triple(Triple A);
int Add_of_triple(Triple A, Triple B, Triple C);
int Show_triple(Triple A);

int main()
{
    int A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE];
    printf("Enther infomation of the first tirple...\n");
    Input_for_triple(A);
    printf("Enter infomation of the second tirple...\n");
    Input_for_triple(B);
    Add_of_triple(A, B, C);
    printf("Show the result...\n");
    Show_triple(C);
    return 0;
}

int Input_for_triple(Triple A)
{
    printf("Enter the sparse matrix row, col and the number of non-zero elements, splited by space...\n");
    scanf("%d %d %d", &A[0], &A[1], &A[2]);
    printf("Enter every element row, col and value...\n");
    for (int i = 1; i <= A[2];i++)
    {
        printf("%2d : ",i);
        scanf("%d %d %d", &A[i * 3 + 0], &A[i * 3 + 1], &A[i * 3 + 2]);
    }
    return 0;
}

int Add_of_triple(Triple A,Triple B,Triple C)
{//传入两个三元组A，B，进行加法运算并把结果传到C中
    int cnt_a = 1, cnt_b = 1, cnt_c = 1;
    if(A[0] != B[0] || A[1] != B[1]) return -1;//A,B矩阵维数不同，无法相加（在数学领域不合法）
    C[0] = A[0];
    C[1] = A[1];
    while(cnt_a<=A[2] && cnt_b<=B[2])
    {
        if(A[cnt_a*3+0] < B[cnt_b*3+0])
        {
            for (int i = 0; i < 3;i++) C[cnt_c * 3 + i] = A[cnt_a * 3 + i];
            cnt_a++;
            cnt_c++;
        }
        else if (A[cnt_a*3+0] == B[cnt_b*3+0])
        {
            if(A[cnt_a*3+1] < B[cnt_b*3+1])
            {
                for (int i = 0; i < 3;i++) C[cnt_c * 3 + i] = A[cnt_a * 3 + i];
                cnt_a++;
                cnt_c++;
            }
            else if (A[cnt_a*3+1] == B[cnt_b*3+1])//AB矩阵相同位置元素相加
            {
                if(A[cnt_a*3+2] == -B[cnt_b*3+2])
                {
                    cnt_a++;
                    cnt_b++;
                }
                else
                {
                    for (int i = 0; i < 2;i++) C[cnt_c * 3 + i] = A[cnt_a * 3 + i];
                    C[cnt_c * 3 + 2] = A[cnt_a * 3 + 2]+B[cnt_b * 3 + 2];
                    cnt_a++;
                    cnt_b++;
                    cnt_c++;
                }
            }
            else
            {
                for (int i = 0; i < 3;i++) C[cnt_c * 3 + i] = B[cnt_b * 3 + i];
                cnt_b++;
                cnt_c++;
            }
        }
        else
        {
            for (int i = 0; i < 3;i++) C[cnt_c * 3 + i] = B[cnt_b * 3 + i];
            cnt_b++;
            cnt_c++;
        }
    }
    while(cnt_a<=A[2])//将A中剩余元素写入C中
    {
        for (int i = 0; i < 3;i++) C[cnt_c * 3 + i] = A[cnt_a * 3 + i];
        cnt_a++;
        cnt_c++;
    }
    while(cnt_b<=B[2])//将B中剩余元素写入C中
    {
        for (int i = 0; i < 3;i++) C[cnt_c * 3 + i] = B[cnt_b * 3 + i];
        cnt_b++;
        cnt_c++;
    }
    C[2] = --cnt_c;
    return 0;
}

int Show_triple(Triple A)
{
    printf("    | %3d %3d %3d\n", A[0], A[1], A[2]);
    printf("-----------------\n");
    for (int i = 1; i <= A[2];i++) printf("%3d | %3d %3d %3d\n", i, A[i * 3 + 0], A[i * 3 + 1], A[i * 3 + 2]);
    return 0;
}