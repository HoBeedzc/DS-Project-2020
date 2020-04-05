/*
Author: Hobee (LZQ)
Date: 2019.4.02
Problem: 0601 Eight Queens
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Eight Queens问题
// 1.请确保您的输入使问题有意义

/*
这个问题的解决方案我先在这里写一下吧，不然一会就忘了...
首先要明确的是肯定每行只有一个皇后，所以可以使用一个长度为8的列表，列表的每一项代表第i行的皇后所在的位置。
然后进行回溯，并输出。
*/
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

int Eight_queens(int cur);
int show(int *pos);

int main()
{
    Eight_queens(0);
    return 0;
}

int Eight_queens(int cur)
{
    static int pos[8] = {0};
    if (cur == 8)
    {
        show(pos);
        return 0;
    }
    for (int i = 0; i < 8;i++)
    {
        bool flag = true;
        pos[cur] = i;
        for (int j = 0; j < cur;j++)
        {
            if(pos[j]==pos[cur]||abs(pos[j]-pos[cur])==abs(cur-j))
            {
                flag = false;
                break;
            }
        }
        if (flag) Eight_queens(cur + 1);
    }
}

int show(int *pos)
{
    static int cnt = 1;
    printf("No.%d\n", cnt++);
    for (int i = 0; i < 8;i++)
    {
        for(int j = 0; j < 8;j++)
        {
            if (j == pos[i]) printf("Q ");
            else printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}