/*Thuư viện <string.h>
khai báo string chuoi = "hiep";
các hàm trong string.h
        strcat(s1, s2)
VD: string chuoi1 = "Trần";
    string chuoi2 = "Hoàn";
    strcat(chuoi1, chuoi2);-------> in ra chuỗi 1
Dùng string để ghép chuỗi
*/
#include <string.h>
#include <stdio.h>
#define MAX 20
int main()
{
    char chuoi1[MAX] = "Van";
    char chuoi2[MAX] = " Trung";
    char a[MAX], a1[MAX], a2[2 * MAX];
    strcat(chuoi1, chuoi2);
    puts(chuoi1);

    printf("Nhap ho: ");
    fflush(stdin);
    gets(a);
    printf("Ho cua sinh vien la: ");
    puts(a);

    printf("Nhap ten: ");
    fflush(stdin);
    gets(a1);
    printf("Ten cua sinh vien la: ");
    puts(a1);

    strcpy(a2, strcat(a, a1));
    printf("Ho va ten sinh vien sau khi ghep la: ");
    puts(a2);
    return 0;
}
