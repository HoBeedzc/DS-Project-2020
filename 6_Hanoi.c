/*
Author: Hobee (LZQ)
Date: 2019.4.02
Problem: 06 Hanoi
More info: https://github.com/HoBeedzc/ds_project
©copyright 1999-2020 Hobee. All rights reserved.
Never Settle
*/

// 本程序基于以下假设实现Hanoi问题
// 1.根据汉诺塔最初传说，我建议n不要超过64
// 2.请确保您的输入使问题有意义

# include<stdio.h>
# include<stdlib.h>

typedef char Plate;

int Hanoi(Plate a, Plate b, Plate c, int n);

int main()
{
    int n;//盘子的个数
    Plate a = 'A', b = 'B', c = 'C';
    printf("Enter the number of plate(s)...\n");
    scanf("%d", &n);
    Hanoi(a, b, c, n);
    return 0;
}

int Hanoi(Plate a, Plate b, Plate c, int n)//表示将n个盘子从a塔借助b塔移到c塔
{
    static int cnt = 1;//建立静态变量，储存总步数
    if (n == 1) printf("%d : %c -> %c \n", cnt++, a, c);//指第cnt步是将a最上面的盘子移到c上
    else
    {
        Hanoi(a, c, b, n - 1);
        Hanoi(a, b, c, 1);
        Hanoi(b, a, c, n - 1);
    }
    return 0;
}