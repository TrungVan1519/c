#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Input();
void Output();
int Check();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int *p, n, m;
    int luachon;

    label:
        printf("\n");
        printf("\t ___________________________________________\n");
        printf("\t|               == MENU ==                  |\n");
        printf("\t|-------------------------------------------|\n");
        printf("\t|     1. Nhap, xuat day so                  |\n");
        printf("\t|     2. Kiem tra day co doi xung hay k     |\n");
        printf("\t|     0. Thoat                              |\n");
        printf("\t|___________________________________________|\n");
    printf("Vui long chon: ");
    scanf("%d", &luachon);

    switch(luachon)
    {
        case 1:
        {
            printf("Nhap so luong phan tu day: ");
            scanf("%d", &n);
            p = (int*)malloc(sizeof(int));
            Input(p, n);
            printf("Day so la:\n");
            Output(p, n);
            goto label;
        }
        case 2:
        {
            m = Check(p, n);
            if(m == 1)
            {
                printf("Day so doi xung");
            }
            else
            {
                printf("Day so khong doi xung");
            }
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

void Input(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Nhap: ");
        scanf("%d", &p[i]);
    }
}

void Output(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%4d", p[i]);
    }
}

int Check(int *p, int n)
{
    int i;
    for(i = 0; i < n / 2; i++)
    {
        if(p[i] != p[n - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}
