#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Input();
void Output();
void Check_Chanle();
int Check_Nguyento();
void Check_Chinhphuong();
//void Search_Divisor();
void Check_Hoanchinh();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int n, m;
    int luachon;
    printf("Nhap so n: ");
    scanf("%d", &n);

    label:
    printf("\t _________________________________________________ \n");
    printf("\t|                  == MENU ==                     |\n");
    printf("\t|-------------------------------------------------|\n");
    printf("\t|         1. Kiem tra tinh chan le                |\n");
    printf("\t|         2. Kiem tra so nguyen to                |\n");
    printf("\t|         3. Kiem tra so chinh phuong             |\n");
    printf("\t|         4. Kiem tra so hoan chinh               |\n");
    printf("\t|         0. Thoat                                |\n");
    printf("\t|_________________________________________________|\n");

    printf("Vui long chon: ");
    scanf("%d", &luachon);

    switch(luachon)
    {
        case 1:
        {
            Check_Chanle(n);
            goto label;
        }
        case 2:
        {
            m = Check_Nguyento(n);
            if(m == 1)
                printf("n la so nguyen to\n");

            else if(m == 0)
                printf("n khong phai la so nguyen to\n");
            goto label;
        }
        case 3:
        {
            Check_Chinhphuong(n);
            goto label;
        }
        case 4:
        {
            Check_Hoanchinh(n);
            goto label;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            printf("Ban nhap sai. Vui long nhap lai!\n");
            goto label;
        }
    }
}

void Check_Chanle(int n)
{
    if(n %2 == 0)
        printf("n la so chan\n");
    else
        printf("n la so le\n");
}

int Check_Nguyento(int n)
{
    int i;
    if(n < 2)
        return 0;
    else
    {
        for(i = 2; i <= n / 2; i++)
        {
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
}

void Check_Chinhphuong(int n)
{
    if(sqrt(n) * sqrt(n) == n)
        printf("n la so chinh phuong\n");
    else
        printf("n khong phai la so chinh phuong\n");
}

void Check_Hoanchinh(int n)
{
    int i;
    int tong = 0;
    for(i = 1; i < n; i++)
    {
        if(n % i == 0)
            tong += i;
    }
    if(tong == n)
        printf("n la so hoan chinh\n");
    else
        printf("n khong phai la so hoan chinh\n");
}
