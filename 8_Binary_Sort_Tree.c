/*
Author: Hobee (LZQ)
Date: 2019.4.21
Problem: 08 Binary Sort Tree
More info: https://github.com/HoBeedzc/ds_project
Website: http://blog.hobeedzc.cn/
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Binary Sort Tree问题
// 1.请确保您的输入使问题有意义
// 2.请使用-1表示输入结束
// 3.输入的节点个数请不要超过9999.

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

# define SIZE sizeof(TNode)

struct node
{
    int Data;
    struct node *LChild;
    struct node *RChild;
};

typedef struct node TNode, *Tree;

int Creat(Tree *A);
int Show_by_inorder(Tree A);

int main()
{
    Tree A = 0;
    Creat(&A);
    Show_by_inorder(A);
    return 0;
}

int Creat(Tree *A)
{
    TNode *new = 0, *p = (*A), *q = p;
    int cur = 0;
    printf("Enter the vaules of Tree...\n");
    scanf("%d", &cur);
    new = (Tree)malloc(SIZE);
    new->Data = cur;
    new->LChild = 0;
    new->RChild = 0;
    *A = new;
    while (true)
    {
        scanf("%d", &cur);
        if (cur == -1) break;
        p = *A;
        new = (Tree)malloc(SIZE);
        new->Data = cur;
        new->LChild = 0;
        new->RChild = 0;
        while(p != 0)
        {
            q = p;
            if (p->Data < new->Data) p = p->RChild;
            else p = p->LChild;
        } 
        if (q->Data < new->Data) q->RChild = new;
        else q->LChild = new;
    }
    return 0;
}

int Show_by_inorder(Tree A)
{
    TNode *s[9999] = {0}, *p = A;
    int top = 0;
    while (p != 0 || top > 0)
    {
        if(p != 0)
        {
            s[++top] = p;
            p = p->LChild;
        }
        else
        {
            p = s[top--];
            printf("%3d", p->Data);
            p = p->RChild;
        }
    }
    printf("\n");
    return 0;
}
