//In bang ma ASCII
#include <stdio.h>
int main()
{
    int i;
    for (i = 65; i <= 90; i++)
    {
        printf("%4c", i);
    }
    printf(" \n");
    for (i = 97; i <= 122; i++)
    {
        printf("%4", i);
    }
    return 0;
}
