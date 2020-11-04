#include<stdio.h>
#define MAX 20
typedef struct
{
    char hoten[25];
    int tuoi;
    float diem;
}sinhvien;

sinhvien nhap()
{
    sinhvien sv;
    printf("Nhap ho va ten: ");
    fflush(stdin);
    gets(sv.hoten);
    printf("Nhap tuoi: ");
    scanf("%d", &sv.tuoi);
    printf("Nhap diem: ");
    scanf("%f", &sv.diem);

    return sv;

}
void xuat(sinhvien sv)
{
    printf("Ho va ten: ");
    printf("%s\n", sv.hoten);
    printf("Tuoi: ");
    printf("%d\n", sv.tuoi);
    printf("Diem: ");
    printf("%0.2f", sv.diem);
}
int main()
{
    sinhvien sv;
    sv = nhap(sv);
    xuat(sv);
    return 0;
}
