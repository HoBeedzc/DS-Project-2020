/*
Author: Hobee (LZQ)
Date: 2019.3.27
Problem: 04 Magic Square
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Magic Square问题
// 1.请确保输入的数据合法
// 2.本算法输入的n不要超过50

# include<stdio.h>
# include<stdlib.h>

# define MAX_SIZE 2500

typedef int *MagicSquare;

int Show(MagicSquare A, int n);
int Magic_square_left(MagicSquare A, int n);
int Magic_square_right(MagicSquare A, int n);

int main()
{
    int n;
    int A[MAX_SIZE] = {0};
    int B[MAX_SIZE] = {0};
    printf("Enter the order of the magic square...\n");
    scanf("%d", &n);
    if (n*n>MAX_SIZE)//防止数组越界
    {
        printf("Overflow!\n");
        return -1;
    }
    printf("Meet Magic Now!\n");
    Magic_square_left(A, n);
    Show(A, n);
    printf("or\n");
    Magic_square_right(B, n);
    Show(B, n);
    return 0;
}

int Show(MagicSquare A, int n)
{
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++) printf("%4d", A[i * n + j]);
        printf("\n");
    }
    return 0;
}

int Magic_square_left(MagicSquare A, int n)//向左上延申的方式
{
    int x = 0, y = n/2;
    int x_temp, y_temp;
    for (int cnt = 1; cnt <= n * n;cnt++)
    {
        A[x * n + y] = cnt;
        x_temp = x == 0 ? n - 1 : x - 1;
        y_temp = y == 0 ? n - 1 : y - 1;
        if (A[x_temp * n + y_temp] == 0)
        {
            x = x_temp;
            y = y_temp;
        }
        else x++;
    }
    return 0;
}

int Magic_square_right(MagicSquare A, int n)//向右上延伸的方式
{
    int x = 0, y = n/2;
    int x_temp, y_temp;
    for (int cnt = 1; cnt <= n * n;cnt++)
    {
        A[x * n + y] = cnt;
        x_temp = x == 0 ? n - 1 : x - 1;
        y_temp = y == n - 1 ? 0 : y + 1;
        if (A[x_temp * n + y_temp] == 0)
        {
            x = x_temp;
            y = y_temp;
        }
        else x++;
    }
    return 0;
}