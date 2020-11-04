#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 5

int binh_phuong(int x)
{
    return x*x;
}
void sinh_so_ngnhien(int* x, int* y)       // sinh ra toa do 2 nhan vat ngau nhien
{
    srand(time(NULL));
    *x = rand()%5;
    *y = rand()%5;
}
int ktr_vi_tri(int x1, int y1, int x2, int y2)              // kiem tra vi tri 2 nhan vat
{
//    {
        if(binh_phuong(x1-x2) + binh_phuong(y1-y2)<=2)      // neu trung nhau hoac cach 1 tra ve gia tri 0 la sai
            return 0;
        else                                                // neu ko trung nhau hoac khoang cach 2 nhan vat > 1  tra ve 1 la dung
            return 1;

//    }
}
int main()
{
    int x1, x2, y1, y2;
    int m;
    sinh_so_ngnhien(&x1, &y1);
    sinh_so_ngnhien(&x2, &y2);
    while (1)                                       // vong lap sinh toa do 2 nhan vat ngau nhien va kiem tra toa do cua chung
    {
        m = ktr_vi_tri(x1, y1, x2, y2);
        if (m==0)
            sinh_so_ngnhien(&x2, &y2);
        else
            break;
    }
    printf("Toa do nhan vat 1: A(%d,%d)\n", x1, y1);                // in ra toa do cua 2 nhan vat
    printf("Toa do nhan vat 2: B(%d,%d)", x2, y2);

}
