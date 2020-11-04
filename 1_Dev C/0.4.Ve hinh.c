#include<stdio.h>
#include<stdlib.h>

void Rectangle();
void Square();
void Triangle();
void Hollow_Rectangle();
void Hollow_Square();
void Hollow_Triangle();
void Isosceles_Triangle();
void Hollow_Isosceles_Triangle();
void Menu();

int  main()
{
    Menu();
    return 0;
}

void Menu()
{
    int hang, cot;
    int luachon;

    label:
    printf("\n");
    printf("\t _____________________________________________\n");
    printf("\t|                  == MENU ==                 |\n");
    printf("\t|---------------------------------------------|\n");
    printf("\t|     1. Ve hinh chu nhat dac                 |\n");
    printf("\t|     2. Ve hinh vuong dac                    |\n");
    printf("\t|     3. Ve hinh tam giac vuong dac           |\n");
    printf("\t|---------------------------------------------|\n");
    printf("\t|     4. Ve hinh chu nhat rong                |\n");
    printf("\t|     5. Ve hinh vuong rong                   |\n");
    printf("\t|     6. Ve hinh tam giac vuong rong          |\n");
    printf("\t|---------------------------------------------|\n");
    printf("\t|     7. Ve hinh tam giac can dac             |\n");
    printf("\t|     8. Ve hinh tam giac can rong            |\n");
    printf("\t|---------------------------------------------|\n");
    printf("\t|     0. Thoat                                |\n");
    printf("\t|_____________________________________________|\n");

    printf("Vui long chon: ");
    scanf("%d", &luachon);

    switch(luachon)
    {
        case 1:
        {
            Rectangle(hang, cot);
            goto label;
        }
        case 2:
        {
            Square(hang);
            goto label;
        }
        case 3:
        {
            Triangle(hang);
            goto label;
        }
        case 4:
        {
            Hollow_Rectangle(hang, cot);
            goto label;
        }
        case 5:
        {
            Hollow_Square(hang);
            goto label;
        }
        case 6:
        {
            Hollow_Triangle(hang);
            goto label;
        }
        case 7:
        {
            Isosceles_Triangle(hang);
            goto label;
        }
        case 8:
        {
            Hollow_Isosceles_Triangle(hang);
            goto label;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            printf("Ban nhap sai. Vui long nhap lai!");
        }
    }
}

void Rectangle(int n, int m)
{
    int i, j;
    printf("Nhap so hang va cot: ");
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%2s", "*");
        }
        printf("\n");
    }
}

void Square(int n)
{
    int i, j;
    printf("Nhap do dai hinh vuong: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%2s", "*");
        }
        printf("\n");
    }
}

void Triangle(int n)
{
    int i, j;
    printf("Nhap do dai tam giac: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("%2s", "*");
        }
        printf("\n");
    }
}

void Hollow_Rectangle(int n, int m)
{
    int i, j;
    printf("Nhap so hang va cot: ");
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                printf("%2s", "*");
            }
            else
            {
                printf("%2s", " ");
            }
        }
        printf("\n");
    }
}

void Hollow_Square(int n)
{
    int i, j;
    printf("Nhap do dai canh hinh vuong: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                printf("%2s", "*");
            }
            else
            {
                printf("%2s", " ");
            }
        }
        printf("\n");
    }
}

void Hollow_Triangle(int n)
{
    int i, j;
    printf("Nhap do dai canh tam giac: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(i == 0 || i == n - 1 || j == 0 || j == i)
            {
                printf("%2s", "*");
            }
            else
            {
                printf("%2s", " ");
            }
        }
        printf("\n");
    }
}

void Isosceles_Triangle(int h)
{
    int i, j;
    printf("Nhap chieu cao cua tam giac: ");
    scanf("%d", &h);
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < 2 * h; j++)
        {
            if(j >= (h - 1 - i) && j <= (h - 1 + i))
            {
                printf("%2s", "*");
            }
            else
            {
                printf("%2s", " ");
            }
        }
        printf("\n");
    }
}

void Hollow_Isosceles_Triangle(int h)
{
    int i, j;
    printf("Nhap chieu cao cua tam giac: ");
    scanf("%d", &h);
    for(i = 0; i < h - 1; i++)
    {
        for(j = 0; j < 2 * h - 1; j++)
        {
            if(j == (h - 1 - i) || j == (h - 1 + i))
            {
                printf("%2s", "*");
            }
            else
            {
                printf("%2s", " ");
            }
        }
        printf("\n");
    }
    for(i = 0; i < 2 * h - 1; i++)
        printf("%2s","*");
}
