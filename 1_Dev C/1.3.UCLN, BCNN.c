#include<stdio.h>

void UCLN();
void BCNN();

int main()
{
    int n, a, b;
    int ucln, bcnn;
    printf("Nhap 2 so a va b: ");
    scanf("%d%d", &a, &b);
    n = a * b;

    UCLN(a, b, &ucln);
    printf("UCLN cua a va b la: %d", ucln);
    BCNN(n, &ucln, &bcnn);
    printf("\nBCNN cua a va b la: %d", bcnn);
    return 0;
}

void UCLN(int x, int y, int* ucln)
{
    while(x != y)
    {
        if(x > y)
            x = x - y;
        else
            y = y - x;
    }
    *ucln = x;
}

void BCNN(int n, int* ucln, int* bcnn)
{
    *bcnn = n / *ucln;
}

/// #Cach 1:    Khoi tao bien UCLN o ham con 1 ---> truyen tham tri 2 bien a, b de tim UCLN ---> return UCLN
///             Tao bien n o ham main() de nhan gia tri UCLN ---> truyen tham tri tich (a * b) va gia tri n = UCLN cho ham con 2 de tinh BCNN
///             return BCNN o ham main() va tao bien m = BCNN

/// #Cach 2:    Tao bien UCLN va BCNN o ham main() sau do truyen tham chieu 2 bien *UCLN va *BCNN cho ham con
///             Ham con 1 truyen tham chieu *UCLN de tinh *UCLN
///             Ham con 2 truyen tham chieu *BCNN, *UCLN, tich (a * b) de tinh *BCNN
