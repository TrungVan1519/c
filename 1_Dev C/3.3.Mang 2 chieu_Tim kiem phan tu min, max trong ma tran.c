#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void Input();
void Output();
int Check_Min();
int Check_Max();
void Search_Min_Max_Only_Row();
void Search_Min_Max();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int a[MAX][MAX], n, m;
    int luachon;

    label:
        printf("\n");
        printf("\t _______________________________________________\n");
        printf("\t|                   == MENU ==                  |\n");
        printf("\t|-----------------------------------------------|\n");
        printf("\t|     1. Nhap, xuat ma tran                     |\n");
        printf("\t|     2. Tim kiem min, max cua tung hang        |\n");
        printf("\t|     3. Tim kiem min, max cua ca ma tran       |\n");
        printf("\t|     0. Thoat                                  |\n");
        printf("\t|_______________________________________________|\n");

    printf("Vui long lua chon: ");
    scanf("%d", &luachon);
    switch(luachon)
    {
        case 1:
        {
            printf("Nhap so hang va cot cua ma tran: ");
            scanf("%d%d", &n, &m);
            Input(a, n, m);
            printf("\nMa tran la:\n");
            Output(a, n, m);
            goto label;
        }
        case 2:
        {
            Search_Min_Max_Only_Row(a, n, m);
            goto label;
        }
        case 3:
        {
            Search_Min_Max(a, n, m);
            goto label;
        }
        case 0:
        {
            exit(0);
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

void Search_Min_Max_Only_Row(int a[][MAX], int n, int m)
{
    int i, j;
    int min, max;
    for(i = 0; i < n; i++)
    {
        min = a[i][0];
        max = a[i][0];
        for(j = 0; j < m; j++)
        {
            if(min > a[i][j])
            {
                min = a[i][j];
            }
            if(max < a[i][j])
            {
                max = a[i][j];
            }
        }
        printf("\n\nMin cua hang thu %d la %d", i + 1, min);
        printf("\nMax cua hang thu %d la %d", i + 1, max);
    }

}

void Search_Min_Max(int a[][MAX], int n, int m)
{
    int i, j;
    int min, max;
    min = a[0][0];
    max = a[0][0];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(min > a[i][j])
            {
                min = a[i][j];
            }
            if(max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    printf("\n\nMin cua ma tran la %d", min);
    printf("\nMax cua ma tran la %d", max);
}
