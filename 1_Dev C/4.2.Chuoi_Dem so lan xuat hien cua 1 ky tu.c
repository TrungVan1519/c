#include<stdio.h>
#define MAX 200
int main()
{
    char a[MAX];
    char b;
    int c = 0,i;
    gets(a);
    printf("Nhap ky tu can xet: ");
    scanf("%c", &b);
    for(i = 0; i < MAX; i++)
    {
       if(a[i] == b)
       {
           c = c + 1;
       }
    }
    printf("So lan xuat hien cua ky tu %c la: %d", b, c);
    return 0;
}
