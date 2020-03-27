/*
Author: Hobee (LZQ)
Date: 2019.3.27
Problem: 03 Transpose of Sparse Matrix
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Transpose of Sparse Matrix问题
// 1.请确保输入的数据合法
// 2.矩阵均以三元组形式储存
// 3.按矩阵形式输出时不占用额外空间
// 4.本算法单个三元组最大储存元素个数不要超过332个

# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define MAX_SIZE 999

typedef int *Triple;

int Input_for_triple(Triple A);
int Transpose_by_triple(Triple A, Triple B);
int Show_triple_in_matrix(Triple A);
int Show_triple(Triple A);

int main()
{
    int A[MAX_SIZE], B[MAX_SIZE];
    Input_for_triple(A);
    printf("Triple is...\n");
    Show_triple(A);
    printf("Sparse matrix is...\n");
    Show_triple_in_matrix(A);
    Transpose_by_triple(A, B);
    printf("After transposing, triple is...\n");
    Show_triple(B);
    printf("After transposing, sparse matrix is...\n");
    Show_triple_in_matrix(B);
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

int Transpose_by_triple(Triple A,Triple B)
{
    int num[A[0]],pos[A[0]];
    pos[0] = 1;
    memset(num, 0, A[0] * sizeof(int));
    for (int i = 1; i <= A[2];i++) num[A[i * 3 + 1] - 1]++; //寻找每行非零元素的个数
    for (int i = 1; i < A[0];i++) pos[i] = num[i - 1] + pos[i - 1];
    B[0] = A[1];
    B[1] = A[0];
    B[2] = A[2];
    for (int i = 1; i <= A[2];i++)
    {
        B[pos[A[i * 3 + 1] - 1] * 3 + 1] = A[i * 3 + 0];
        B[pos[A[i * 3 + 1] - 1] * 3 + 0] = A[i * 3 + 1];
        B[pos[A[i * 3 + 1] - 1]++ * 3 + 2] = A[i * 3 + 2];
    }
    return 0;
}

int Show_triple_in_matrix(Triple A)
{
    int cur = 1;
    for (int i = 1; i <= A[0];i++)
    {
        for (int j = 1; j <= A[1];j++)
        {
            if (cur - 1 == A[2]) cur--;//防止越界
            if (i == A[cur*3+0] && j == A[cur*3+1]) printf("%3d ", A[cur++ * 3 + 2]);
            else printf("%3d ", 0);
        }
        printf("\n");
    }
        return 0;
}

int Show_triple(Triple A)
{
    printf("    | %3d %3d %3d\n", A[0], A[1], A[2]);
    printf("-----------------\n");
    for (int i = 1; i <= A[2];i++) printf("%3d | %3d %3d %3d\n", i, A[i * 3 + 0], A[i * 3 + 1], A[i * 3 + 2]);
    return 0;
}