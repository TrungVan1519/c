#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Input();
void Ouput();
void PT_bac_1();
void PT_bac_2();
void He_PT();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int luachon;

    label:
        printf("\n");
        printf("\t _______________________________________________\n");
        printf("\t|                == MENU ==                     |\n");
        printf("\t|-----------------------------------------------|\n");
        printf("\t|      1. Bien luan PT bac 1                    |\n");
        printf("\t|      2. Bien luan PT bac 2                    |\n");
        printf("\t|      3. Bien luan he PT                       |\n");
        printf("\t|      0. Thoat                                 |\n");
        printf("\t|_______________________________________________|\n");

    printf("Vui long chon: ");
    scanf("%d", &luachon);
    switch(luachon)
    {
        case 1:
        {
            PT_bac_1();
            goto label;
        }
        case 2:
        {
            PT_bac_2();
            goto label;
        }
        case 3:
        {
            He_PT();
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

void PT_bac_1()
{
    int a, b;
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);
    if(a == 0)
    {
        if(b == 0)
        {
            printf("PT vo so nghiem");
        }
        if(b != 0)
        {
            printf("PT vo nghiem");
        }
    }
    else
    {
        printf("PT co nghiem duy nhat x = %.2f", (float)(-b) / a);
    }
}

void PT_bac_2()
{
    int a, b, c;
    float delta, x1, x2;
    printf("Nhap a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    delta = (b * b) - 4 * a * c;
    x1 = ((-b) + sqrt(delta)) / (2 * a);
    x2 = ((-b) - sqrt(delta)) / (2 * a);
    if(a == 0)
    {
        PT_bac_1(b, c);
    }
    else
    {
        if(delta < 0)
        {
            printf("PT vo nghiem");
        }
        else if(delta == 0)
        {
            printf("PT co 1 nghiem duy nhat x = %.2f", (float)(-b) / (2 * a));
        }
        else
        {
            printf("PT co 2 nghiem phan biet:\n");
            printf("x1 = %.2f", x1);
            printf("\nx2 = %.2f", x2);
        }
    }
}

void He_PT()
{
    int a1, b1, c1, a2, b2, c2;
    int d, dx, dy;
    printf("Nhap cac he so a1, b1, c1: ");
    scanf("%d%d%d", &a1, &b1, &c1);
    printf("Nhap cac he so a2, b2, c2: ");
    scanf("%d%d%d", &a2, &b2, &c2);
    d = a1 * b2 - a2 * b1;
    dx = c1 * b2 - c2 * b1;
    dy = a1 * c2 - a2 * c1;
    if(d == dx == dy == 0)
    {
        printf("He PT vo so nghiem");
    }
    else if(d != 0)
    {
        float x = dx / d;
        float y = dy/ d;
        printf("He PT co 1 nghiem duy nhat: (x, y) = (%.2f, %.2f)", x, y);

    }
    else if((d == 0 && dx != 0) || (d == 0 && dy != 0))
    {
        printf("He PT vo nghiem");
    }
}
