#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void Input();
void Output();
void Add();
void Del();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int a[MAX], n;
    int vitri, giatri;
    int luachon;

    label:
        printf("\n");
        printf("\t ______________________________________________ \n");
        printf("\t|                  == MENU ==                  |\n");
        printf("\t|----------------------------------------------|\n");
        printf("\t|    1. Nhap, xuat day so                      |\n");
        printf("\t|    2. Them phan tu cho day so                |\n");
        printf("\t|    3. Xoa phan tu cua day so                 |\n");
        printf("\t|    0. Thoat                                  |\n");
        printf("\t|______________________________________________|\n");

    printf("Vui long chon: ");
    scanf("%d", &luachon);
    switch(luachon)
    {
        case 1:
        {
            printf("Nhap so phan tu day: ");
            scanf("%d", &n);
            Input(a, n);
            printf("\nDay so la: ");
            Output(a, n);
            goto label;
        }
        case 2:
        {
            printf("Nhap gia tri muon them: ");
            scanf("%d", &giatri);
            printf("Nhap vi tri muon them: ");
            scanf("%d", &vitri);
            Add(a, &n, giatri, vitri);
            printf("\nDay so sau khi them la:\n");
            Output(a, n);
            goto label;
        }
        case 3:
        {
            printf("Nhap vi tri muon xoa: ");
            scanf("%d", &vitri);
            Del(a, &n, vitri);
            printf("\nDay so sau khi xoa la:\n");
            Output(a, n);
            goto label;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            printf("Ban nhap sai. Vui long nhap lai!");
            goto label;
        }
    }
}

void Input(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Nhap: ");
        scanf("%d", &a[i]);
    }
}

void Output(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

void Add(int a[], int *n, int giatri, int vitri)
{
    int i;
    if(vitri >= 0 && vitri < *n)
    {
        *n += 1;
        for(i = *n - 1 ; i >= vitri; i--)
        {
            a[i + 1] = a[i];
        }
        a[vitri] = giatri;
    }
    else
    {
        printf("Khong ton tai vi tri nay!\n");
    }
}

void Del(int a[], int *n, int vitri)
{
    int i;
    if(vitri >= 0 && vitri < *n)
    {

        for(i = vitri ; i < *n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        *n -= 1;
    }
    else
    {
        printf("Khong ton tai vi tri nay!\n");
    }
}
