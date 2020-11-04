// chuyen ky tu hoa thanh thuong va nguoc lai
#include <stdio.h>
int main()
{
    int kytu;
    printf("Nhap ky tu bat ky: ");
    scanf("%c", &kytu);
    if (kytu >=65 && kytu <= 90)// hoac if(kytu >= 'A' && kytu <= 'Z')
    {
        printf("%c", kytu + 32);
    }
    else if (kytu >= 97 && kytu <= 122)// hoac if (kytu >= 'a' && kytu <= 'z')
    {
        printf("%c", kytu - 32);
    }
    else
    return 0;
}
