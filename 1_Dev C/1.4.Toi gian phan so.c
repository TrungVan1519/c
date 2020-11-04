#include<stdio.h>
#include<math.h>

int UCLN(int a, int b)
{
    int uoc;

    while(a != b)
    {
        if(a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    uoc = a;
    return uoc;
}

int main()
{
    int tu1, tu2, mau1, mau2;
    int tu, mau;
    printf("Nhap tu1, mau 1: ");
    scanf("%d%d", &tu1, &mau1);
    printf("Nhap tu2 mau 2: ");
    scanf("%d%d", &tu2, &mau2);

    if(mau1 == mau2)
    {
        tu = tu1 + tu2;
        mau = mau1;
    }
    else if(mau1 != mau2)
    {
        tu = tu1 * mau2 + tu2  *mau1;
        mau = mau1 * mau2;
    }
    int n = UCLN(tu, mau);

    tu = tu / n;
    mau = mau / n;

    printf("%d/%d", tu, mau);
    return 0;
}
