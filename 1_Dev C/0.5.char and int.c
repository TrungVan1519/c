#include<stdio.h>

int main()
{
    char a;
    int b, c;
    scanf("%c", &a);
    if(a == 87)
    {
        scanf("%d", &b);
        printf("%d", b);
    }
    else if(a == 'b')
    {
        scanf("%d", &c);
        printf("%d", c);
    }
}

/// Khi nhap ky tu thi co the:
///     so sanh ky tu nhap vs ky tu trong bang ASCII
///     hoac so sanh ky tu nhap vs so tuong ung vs ky tu trong bang ASCII
