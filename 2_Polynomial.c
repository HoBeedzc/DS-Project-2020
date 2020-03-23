/*
Author: Hobee (LZQ)
Date: 2019.3.23
Problem: 02 Polynomial
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Josephu问题
// 1.数据的储存方式选取普通链表
// 2.链表设置头节点,头节点Data储存链表长度，Exp储存常量NULL
// 3.输入时请按指数递增顺序输入
// 4.请确保您的输入使问题有意义。

# include<stdio.h>
# include<stdlib.h>

# define SIZE sizeof(LNode)
# define NULL 0

struct node
{
    int Data;
    int Exp;
    struct node *Link;
};

typedef struct node LNode, *Polynomial;

int Creat_by_value(Polynomial A, int n);
int Add(Polynomial *A, Polynomial *B);
int Show(Polynomial A);

int main()
{
    int n;
    Polynomial A = (Polynomial)malloc(SIZE);
    A->Link = 0;
    A->Data = 0;
    A->Exp = NULL;
    printf("Enter the length of the first Polynomial...\n");
    scanf("%d", &n);
    Creat_by_value(A, n);
    Polynomial B = (Polynomial)malloc(SIZE);
    B->Link = 0;
    B->Data = 0;
    B->Exp = NULL;
    printf("Enter the length of the second Polynomial...\n");
    scanf("%d", &n);
    Creat_by_value(B, n);
    Add(&A, &B);
    Show(A);
    return 0;
}

int Creat_by_value(Polynomial A, int n)
{
    LNode *p = A;
    int data,exp;
    printf("Enter the value and index of the Polynomial, splited by space...\n");
    for (int i = 0; i < n;i++)
    {
        scanf("%d %d", &data, &exp);
        LNode *new = (Polynomial)malloc(SIZE);
        new->Data = data;
        new->Exp = exp;
        new->Link = 0;
        p->Link = new;
        p = p->Link;
        A->Data += 1;
    }
    return 0;
}

int Add(Polynomial *A, Polynomial *B)
{
    Polynomial C = (Polynomial)malloc(SIZE);
    C->Link = 0;
    C->Data = 0;
    C->Exp = NULL;
    LNode *p = C, *q;
    q = (*A);
    (*A) = (*A)->Link;
    free(q);
    q = (*B);
    (*B) = (*B)->Link;
    free(q);
    while((*A)!=0 && (*B)!=0)
    {
        if((*A)->Exp < (*B)->Exp)
        {
            p->Link = (*A);
            (*A) = (*A)->Link;
            p = p->Link;
            C->Data += 1;
        }
        else if ((*A)->Exp > (*B)->Exp)
        {
            p->Link = (*B);
            (*B) = (*B)->Link;
            p = p->Link;
            C->Data += 1;
        }
        else
        {
            LNode *new = (Polynomial)malloc(SIZE);
            new->Data = (*A)->Data + (*B)->Data;
            new->Exp = (*A)->Exp;
            new->Link = 0;
            q = (*A);
            (*A) = (*A)->Link;
            free(q);
            q = (*B);
            (*B) = (*B)->Link;
            free(q);
            if (new->Data)
            {
                p->Link = new;
                p = p->Link;
                C->Data += 1;
            }
            else
            {
                p = p->Link;
                free(new);
            }
        }
    }
    while(*A)
    {
        p->Link = (*A);
        p = p->Link;
        (*A) = (*A)->Link;
        C->Data += 1;
    }
    while(*B)
    {
        p->Link = (*B);
        p = p->Link;
        (*B) = (*B)->Link;
        C->Data += 1;
    }
    (*A) = C;
    return 0;
}

int Show(Polynomial A)
{
    int n = A->Data;
    printf("\nf(x) = ");
    A = A->Link;
    for (int i = 0; i < n;i++)
    {
        printf("%dx1^%d+", A->Data, A->Exp);
        A = A->Link;
    }
    printf("\b \n");
    return 0;
}