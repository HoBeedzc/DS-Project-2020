/*
Author: Hobee (LZQ)
Date: 2019.4.02
Problem: 0602 Knight Tour
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Knight Tour问题
// 1.请确保您的输入使问题有意义
// 2.n不要大于20

/*
由于老师没有给出具体题目，所以我再网上找了一个骑士旅行问题。
在一个N*N 格子的棋盘上，有一只国际象棋的骑士在棋盘的左下角，骑士只能根据象棋的规则进行移动，要么横向跳动一格纵向跳动两格，要么纵向跳动一格横向跳动两格。骑士从第一个格子出发，每个格子只能访问一次，能否访问完所有的格子， 请找到一个解决方案。
*/

# include<stdio.h>
# include<stdlib.h>

# define MAXSIZE 20

int Knight_tour(int n, int x, int y, int cnt);
int show(int map[MAXSIZE][MAXSIZE], int n);

int main()
{
    int n;
    printf("Enter the value of n...\n");
    scanf("%d", &n);
    if (Knight_tour(n, 0, 0, 1) == -1) printf("No such answer!\n");
    return 0;
}

int Knight_tour(int n, int x, int y, int cnt)
{
    static int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    static int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    static int map[MAXSIZE][MAXSIZE] = {0};
    int nextx, nexty;
    map[x][y] = cnt;
    if (cnt == n*n)
    {
        show(map, n);
        return 0;
    }
    for (int i = 0; i < 8;i++)
    {
        nextx = x + X[i];
        nexty = y + Y[i];
        if (nextx>=0&&nextx<n&&nexty>=0&&nexty<n&&(map[nextx][nexty]<=0||map[nextx][nexty]>=cnt))
        {
            if(Knight_tour(n, nextx, nexty, cnt + 1) == 0) return 0;
        }
    }
    map[x][y] = -1;
    //show(map, n);
    return -1;
}

int show(int map[MAXSIZE][MAXSIZE], int n)
{
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}