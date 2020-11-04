#include<stdio.h>

int kiem_tra(int a)
{
    int i;
    if (a < 2)
        return 0;
    for(i = 2; i < a; i++)
    {
        if(a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,m;
    int i;
    scanf("%d", &n);
    m = kiem_tra(n);
    if(m == 1)
        printf("La snt\n");
    else if(m == 0)
        printf("Ko la snt\n");
    for(i = 0; i < n; i++)
    {
        kiem_tra(i) ? printf("%4d", i) : printf("");
    }
    return 0;
}
