/*
Author: Hobee (LZQ)
Date: 2019.4.02
Problem: 07 Infix to Suffix
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Infix to Suffix问题
// 1.请确保您的输入使问题有意义
// 2.输入的中缀表达式长度不建议超过999个字符
// 3.请使用#表示表达式结束

# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

# define MAXSIZE 999

typedef char *Expression;

int Show(Expression A);
int Compare(char a, char b);
int turn(Expression A, Expression B);

int main()
{
    char A[MAXSIZE], M[MAXSIZE] = {0};
    printf("Enter the expression...\n");
    gets(A);
    turn(A, M);
    printf("The suffix expression is...\n");
    Show(M);
    return 0;
}

int turn(Expression A, Expression B)//A是中缀表达式，B用来存放转换后的后缀表达式。
{
    char sym[MAXSIZE] = {'#'};
    int top = 0;
    while(*A)
    {
        switch (*A)
        {
            case '+':
            case '-':
            case '*':
            case '%':
            case '/':
            case '^': 
            case '(':
            {
                while(Compare(sym[top],*A))
                {
                    *B = ' ';
                    B++;
                    *B = sym[top--];
                    B++;
                }
                sym[++top] = *A;
                *B = ' ';
                B++;
                break;
            }
            case ')':
            {
                while(sym[top]!='(')
                {
                    *B = ' ';
                    B++;
                    *B = sym[top--];
                    B++;
                }
                top--;
                *B = ' ';
                B++;
                break;
            }
            case '#':
            {
                while(sym[top]!='#')
                {
                    *B = ' ';
                    B++;
                    *B = sym[top--];
                    B++;
                }
                *B = ' ';
                B++;
                break;
            }
            default:
            {
                *B = *A;
                B++;
                break;
            }
        };
        A++;
    }
    return 0;
}

int Show(Expression A)
{
    bool flag = 1;
    while(*A)
    {
        if (flag) putchar(*A);
        if (*(A + 1) == ' ' && *(A) == *(A + 1)) flag = 0;
        else flag = 1;
        A++;
    }
    return 0;
}

int Compare(char a, char b)
{
    int instack = 0,outstack = 0;
    switch (a)
    {
        case '+':
        case '-': {instack = 1;break;}
        case '*':
        case '/':
        case '%': {instack = 2;break;}
        case '^': {instack = 3;break;}
        case '(':
        case ')': {instack = 0;break;}
        default:  {instack = 0;break;}
    }
    switch (b)
    {
        case '+':
        case '-': {outstack = 1;break;}
        case '*':
        case '/':
        case '%': {outstack = 2;break;}
        case '^': {outstack = 4;break;}
        case '(': {outstack = 5;break;}
        case ')': {outstack = 0;break;}
        default:  {outstack = 0;break;}
    }
    if (instack < outstack) return 0;
    else return 1;
}