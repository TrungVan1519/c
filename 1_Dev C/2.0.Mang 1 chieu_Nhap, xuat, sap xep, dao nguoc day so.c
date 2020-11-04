#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Input();
void Output();
void Sort();
void Reverse();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int* p;
    int n;
    int luachon;

    label:
    printf("\n");
    printf("\t ___________________________________________________\n");
    printf("\t|                     == MENU ==                    |\n");
    printf("\t|---------------------------------------------------|\n");
    printf("\t|       1. Nhap day so                              |\n");
    printf("\t|       2. Xuat day so                              |\n");
    printf("\t|       3. Sap xep day so                           |\n");
    printf("\t|       4. Dao nguoc day so                         |\n");
    printf("\t|       0. Thoat                                    |\n");
    printf("\t|___________________________________________________|\n");

    printf("Vui long nhap: ");
    scanf("%d", &luachon);
    switch(luachon)
    {
        case 1:
        {
            printf("Nhap so phan tu day: ");
            scanf("%d", &n);
            p = (int*)malloc(n * sizeof(int));
            Input(p, n);
            //free(p);          Khong dc free o ham nhap vi nhap -> free -> xuat ==> mat du lieu
            goto label;
        }
        case 2:
        {
            printf("Day so la:\n");
            Output(p, n);
            goto label;
        }
        case 3:
        {
            printf("Day so sau khi sap xep la:\n");
            Sort(p, n);
            Output(p, n);
            goto label;
        }
        case 4:
        {
            printf("Day so dao nguoc la:\n");
            Reverse(p, n);
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
    free(p);
}

void Input(int* p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Nhap: ");
        scanf("%d", &p[i]);
    }
    //free(p);               Khong dc free o ham nhap vi nhap -> free -> xuat ==> mat du lieu
}

void Output(int* p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%4d", p[i]);
    }
}

void Sort(int* p, int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        temp = p[i];
        while(j >= 0 && temp < p[j])
        {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = temp;
    }
}

void Reverse(int* p, int n)
{
    int i;
    for(i = n - 1; i >= 0; i--)
    {
        printf("%4d", p[i]);
    }
}
