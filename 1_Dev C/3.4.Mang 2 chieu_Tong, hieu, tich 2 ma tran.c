#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void Input();
void Output();
void Tong();
void Hieu();
void Tich();
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
        printf("\t ____________________________________________________\n");
        printf("\t|                   == MENU ==                       |\n");
        printf("\t|----------------------------------------------------|\n");
        printf("\t|    1. Tong 2 ma tran                               |\n");
        printf("\t|    2. Hieu 2 ma tran                               |\n");
        printf("\t|    3. Tich 2 ma tran                               |\n");
        printf("\t|    0. Thoat                                        |\n");
        printf("\t|____________________________________________________|\n");

        printf("Vui long lua chon: ");
        scanf("%d", &luachon);
        switch(luachon)
        {
            case 1:
            {
                printf("CHU Y: SO HANG VA COT CUA 2 MA TRAN PHAI BANG NHAU\n");

                printf("Nhap so hang so cot cua ma tran 1: ");
                scanf("%d%d", &n, &m);

                printf("\nNhap so hang va cot cua ma tran 2: ");
                scanf("%d%d", &x, &y);
                if(n == x && m == y)
                {
                    printf("Nhap phan tu cua ma tran 1:\n");
                    Input(a1, n, m);

                    printf("Nhap phan tu cua ma tran 2:\n");
                    Input(a2, x, y);

                    printf("Ma tran 1 la: \n");
                    Output(a1, n, m);

                    printf("\n\nMa tran 2 la:\n");
                    Output(a2, x, y);

                    printf("\nMa tran tong la:\n");
                    Tong(a1, a2, n, m, x, y);
                }
                else
                {
                    printf("Ban nhap sai chu y. Vui long nhap lai!");
                }
                goto label;
            }
            case 2:
            {
                printf("CHU Y: SO HANG VA COT CUA 2 MA TRAN PHAI BANG NHAU\n");

                printf("Nhap so hang so cot cua ma tran 1: ");
                scanf("%d%d", &n, &m);

                printf("\nNhap so hang va cot cua ma tran 2: ");
                scanf("%d%d", &x, &y);
                if(n == x && m == y)
                {
                    printf("Nhap phan tu cua ma tran 1:\n");
                    Input(a1, n, m);

                    printf("Nhap phan tu cua ma tran 2:\n");
                    Input(a2, x, y);

                    printf("Ma tran 1 la: \n");
                    Output(a1, n, m);

                    printf("\nMa tran 2 la:\n");
                    Output(a2, x, y);

                    printf("\nMa tran hieu la:\n");
                    Hieu(a1, a2, n, m, x, y);
                }
                else
                {
                    printf("Ban nhap sai chu y. Vui long nhap lai!");
                }
                goto label;
            }
            case 3:
            {
                printf("CHU Y: SO COT CUA MA TRAN 1 PHAI BANG SO HANG CUA MA TRAN 2 THI MOI NHAN DC!!!\n");
                printf("Nhap so hang va cot cua ma tran 1: ");
                scanf("%d%d", &n, &m);
                printf("Nhap so hang va cot cua ma tran 2: ");
                scanf("%d%d", &x, &y);
                if(m == x)
                {
                    printf("Nhap phan tu ma tran 1:\n");
                    Input(a1, n, m);

                    printf("Nhap phan tu ma tran 2:\n");
                    Input(a2, x, y);

                    printf("Ma tran 1 la: \n");
                    Output(a1, n, m);

                    printf("\n\nMa tran 2 la:\n");
                    Output(a2, x, y);

                    printf("Ma tran tich la:\n");
                    Tich(a1, a2, n, m, x, y);
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

void Tong(int a1[][MAX], int a2[][MAX], int n, int m, int x, int y)
{
    int a3[MAX][MAX];
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            a3[i][j] = a1[i][j] + a2[i][j];
            printf("%4d", a3[i][j]);
        }
        printf("\n");
    }
}

void Hieu(int a1[][MAX], int a2[][MAX], int n, int m, int x, int y)
{
    int a3[MAX][MAX];
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            a3[i][j] = a1[i][j] - a2[i][j];
            printf("%4d", a3[i][j]);
        }
        printf("\n");
    }
}

void Tich(int a1[][MAX], int a2[][MAX], int n, int m, int x, int y)
{
    int a3[MAX][MAX];
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < y ; j++)
        {
            a3[i][j] = 0;
            for(k = 0; k < m; k++)
            {
                a3[i][j] += a1[i][k] * a2[k][j];

            }
            printf("%4d", a3[i][j]);
        }
        printf("\n");
    }

//    for(r = 0; r < n ; r++)
//    {
//        for(c = 0; c < m; c++)
//        {
//            printf("%4d", a3[r][c]);
//        }
//        printf("\n");
//    }
}
