#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void Input();
void Output();
void Merge();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int a1[MAX][MAX], a2[MAX][MAX];
    int n, m, x, y;
    int luachon;

    label:
        printf("\n");
        printf("\t _______________________________________________\n");
        printf("\t|                   == MENU ==                  |\n");
        printf("\t|-----------------------------------------------|\n");
        printf("\t|    1. Nhap ma tran                            |\n");
        printf("\t|    2. Xuat ma tran                            |\n");
        printf("\t|    3. Ghep ma tran                            |\n");
        printf("\t|    0. Thoat                                   |\n");
        printf("\t|_______________________________________________|\n");

    printf("Vui long lua chon: ");
    scanf("%d", &luachon);
    switch(luachon)
    {
        case 1:
        {
            printf("Nhap so hang so cot cua ma tran 1: ");
            scanf("%d%d", &n, &m);
            Input(a1, n, m);

            printf("\nNhap so hang va cot cua ma tran 2: ");
            scanf("%d%d", &x, &y);
            Input(a2, x, y);

            goto label;
        }
        case 2:
        {
            printf("Ma tran 1 la: \n");
            Output(a1, n, m);

            printf("\n\nMa tran 2 la:\n");
            Output(a2, x, y);

            goto label;
        }
        case 3:
        {
            printf("Chu y: So hang cua 2 ma tran phai bang nhau!!!\n");

            printf("Nhap so hang va cot cua ma tran 1: ");
            scanf("%d%d", &n, &m);

            printf("Nhap so hang va cot cua ma tran 2: ");
            scanf("%d%d", &x, &y);

            if(n == x)
            {
                printf("Nhap phan tu cua ma tran 1:\n");
                Input(a1, n, m);

                printf("\nNhap so phan tu cua ma tran 2:\n");
                Input(a2, x, y);

                printf("Ma tran ghep la:\n");
                Merge(a1, a2, n, m, x, y);
            }
            else
            {
                printf("Ban nhap sai chu y. Vui long nhap lai!");
            }
            goto label;
        }
        case 0:
        {
            exit(1);
        }
        default:
        {
            printf("Ban da nhap sai. Vui long nhap lai!\n");
            goto label;
        }

    }
}

void Input(int a[][MAX], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("Nhap: ");
            scanf("%d", &a[i][j]);
        }
    }
}

void Output(int a[][MAX], int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void Merge(int a1[][MAX], int a2[][MAX], int n, int m, int x, int y)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%4d", a1[i][j]);
        }
        for(j = 0; j < y; j++)
        {
            printf("%4d", a2[i][j]);
        }
        printf("\n");
    }
}
