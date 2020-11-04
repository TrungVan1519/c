#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 20

void Input();
void Output();
void Merge();
void Merge_Sort();
void Devide();
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int *pa1, *pa2, *pa3, *pa4;
    int pa5[MAX], pa6[MAX];
    int na1, na2, na3, na4, na5, na6;
    int luachon;

    label:
        printf("\n");
        printf("\t __________________________________________________________\n");
        printf("\t|                           == MENU ==                     |\n");
        printf("\t|----------------------------------------------------------|\n");
        printf("\t|      1. Nhap , xuat day so                               |\n");
        printf("\t|      2. Ghep day so thanh 1 day so                       |\n");
        printf("\t|      3. Ghep day so thanh 1 day so (da sap xep luon)     |\n");
        printf("\t|      4. Tach 1 day so thanh 1 day chan, 1 day le         |\n");
        printf("\t|      0. Thoat                                            |\n");
        printf("\t|__________________________________________________________|\n");

        printf("Vui long chon: ");
        scanf("%d", &luachon);
        switch(luachon)
        {
            case 1:
            {

                printf("Nhap so phan tu day 1:\n ");
                scanf("%d", &na1);
                pa1 = (int*)malloc(na1 * sizeof(int));
                Input(pa1, na1);
                printf("\nDay 1 la: ");
                Output(pa1, na1);
                printf("\nNhap so phan tu day 2:\n ");
                scanf("%d", &na2);
                pa2 = (int*)malloc(na2 * sizeof(int));

                Input(pa2, na2);
                printf("\nDay 2 la: ");
                Output(pa2, na2);
                goto label;
            }
            case 2:
            {
                na3 = na1 + na2;
                pa3 = (int*)malloc(na3 * sizeof(int));
                printf("Day 3 = Day 1 + Day 2 la:\n ");
                Merge(pa1, pa2, pa3, na1, na2, na3);
                Output(pa3, na3);
                goto label;
            }
            case 3:
            {
                na3 = na2 + na1;
                pa3 = (int*)malloc(na3 * sizeof(int));
                printf("Day 3 = Day 1 + Day 2 la: \n");
                Merge_Sort(pa1, pa2, pa3, na1, na2);
                Output(pa3, na3);
                goto label;
            }
            case 4:
            {
                na5 = na6 = 0;
                printf("Nhap so phan tu day 4: ");
                scanf("%d", &na4);
                pa4 = (int*)malloc(na4 * sizeof(int));
                Input(pa4, na4);
                printf("\nDay 4 la:\n");
                Output(pa4, na4);
                Devide(pa4, pa5, pa6, na4, na5, na6);

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
    for( i = 0; i < n; i++)
    {
        printf("Nhap: ");
        scanf("%d", &p[i]);
    }
}

void Output(int* p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%4d", p[i]);
    }
}

void Merge(int* p1, int *p2, int* p3, int n1, int n2, int n3)
{
    int i;
    for(i = 0; i < n3; i++)
    {
        if(i < n1)
        {
            p3[i] = p1[i];
        }
        else
        {
            p3[i] = p2[i - n1];
        }
    }
}

void Merge_Sort(int* p1, int* p2, int* p3, int n1, int n2)
{
    int i, j, k;
    i = 0; j = 0; k = 0;
    while(i < n1 || j < n2)
    {
        if(i < n1 && j < n2)
        {
            if(p1[i] < p2[j])
            {
                p3[k++] = p1[i++];
            }
            else
            {
                p3[k++] = p2[j++];
            }
        }
        else
        {
            if(i < n1 && j >= n2)
            {
                p3[k++] = p1[i++];
            }
            else
            {
                p3[k++] = p2[j++];
            }
        }
    }
}

void Devide(int* p4, int* p5, int* p6, int n4, int n5, int n6)
{
    int i, j, k;
    n5 = 0; n6 = 0;
    i = 0; j = 0; k = 0;
    while(k < n4)
    {
        if(p4[k] % 2 == 0)
        {
            p5[i++] =  p4[k++];
            n5 += 1;
        }
        else
        {
            p6[j++] =  p4[k++];
            n6 += 1;
        }
    }
    printf("\nDay 5 = Day 4 (chan) la:\n");
    Output(p5, n5);
    printf("\nDay 6 = Day 4 (le) la:\n");
    Output(p6, n6);
}


