/*
Author: Hobee (LZQ)
Date: 2019.3.23
Problem: 01 Josephu
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Josephu问题
// 1.数据的储存方式选取单向循环链表
// 2.循环链表不设头节点
// 3.Josephu()函数可实现完整过程，main()函数仅起演示作用
// 4.请确保您的输入使问题有意义。

# include<stdio.h>
# include<stdlib.h>

# define SIZE sizeof(LNode)

struct node 
{
    int Data;
    struct node *Link;
};

typedef struct node LNode, *CLinkList;

int Creat_by_number(CLinkList *H, int n);
int Josephu(CLinkList *H, int n, int m, int k);

int main()
{
    int n, m, k;
    CLinkList H = 0;
    printf("Enter the vulue of n...\n");
    scanf("%d", &n);
    printf("Enter the value of m...\n");
    scanf("%d", &m);
    printf("Enter the value of k...\n");
    scanf("%d", &k);
    Creat_by_number(&H, n);
    Josephu(&H, n, m, k);
    return 0;
}

int Creat_by_number(CLinkList *H, int n)
{
    LNode *p = (CLinkList)malloc(SIZE);
    *H = p;
    p->Data = 1;
    p->Link = p;
    for (int i = 2; i <= n;i++)
    {
        LNode *new = (CLinkList)malloc(SIZE);
        new->Data = i;
        p->Link = new;
        p = p->Link;
        p->Link = *H;
    }
    return 0;
}

int Josephu(CLinkList *H,int n, int m, int k)
{
    LNode *p = (*H), *q;
    printf("The order of poping is...\n");
    for (int i = 1; i < n+k-1;i++) p = p->Link;//找到第一个要报数的人的前面的人
    while ((*H)->Link != *H) //一直循环到只剩一个节点
    {
        for (int i = 1; i < m;i++) p = p->Link;//找到要报m的人（因为要把它删了，所以要在它报数之前停止）
        q = p->Link;
        p->Link = q->Link;
        if ((*H) == q) (*H) = (*H)->Link;//要是头节点被删除，将改变头节点
        printf("%5d", q->Data);
        if ((*H) != q) free(q);//如果在执行过77行后依然有*H == q，则代表表中只有一个元素了，此时就不要free了，不然会出现非法访问的错误
    }
    printf("%5d", (*H)->Data);
    free(*H);
    return 0;
}