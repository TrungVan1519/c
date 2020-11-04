#include<stdio.h>

void nhapGiaTri()
{
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    //printf("%d %d %d %d\n", *a, *b, *c, *d);

    khoiTaoLaiGiaTri(a, b, c, d);
     printf("%d %d %d %d\n", a, b, c, d);
}

void khoiTaoLaiGiaTri(int a, int b, int c, int d)
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
     printf("%d %d %d %d", a, b, c, d);
}

void main()
{
    nhapGiaTri();
}

/// bien truyen tu ham main cho cac ham con su dung
/// khong nen truyen bien cho 1 ham con xong dung bien truyen tu ham con nay truyen cho ham con khac
