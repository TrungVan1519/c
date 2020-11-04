#include<stdio.h>

int main()
{
    int i, n;
    int count = 0;
    printf("Nhap so n: ");
    scanf("%d", &n);
    while(n > 0)
    {
        count++;
        n = n/ 10;
    }
    printf("So chu so cua so n la: %d", count);
}
