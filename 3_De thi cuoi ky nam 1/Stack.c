#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct
{
    int pTop;
    int Data[MAX];
}Stack;

void Create_Stack(Stack *x)
{
    x->pTop = 0;
}

int IsEmpty(Stack *x)
{
    x ->pTop = 0;
    return (x ->Data == 0);
}

//int Is_full (Stack* Stack)
//{
//    return (Stack->pTop == MAX);
//}
//
//void Push (Stack* Stack, int x)
//{
//    if (!Is_full(Stack))
//    {
//        Stack->Data[Stack->pTop] = x;
//        Stack->pTop++;
//    }
//}
void Push(Stack *x, int y)
{
    if(!IsEmpty(x))
    {
        x ->Data[x ->pTop] = y;
        x ->pTop++;
    }
}

void CoSo2(Stack *x, int n)
{
    while(n > 0)
    {
        Push(x, n%2);
        n = n / 2;
    }
}

void CoSo8(Stack *x, int n)
{
    while(n > 0)
    {
        Push(x, n%8);
        n = n / 8;
    }
}

void CoSo16(Stack *x, int n)
{
    while(n > 0)
    {
        Push(x, n%16);
        n = n / 16;
    }
}

void Output_Stack(Stack *x)
{
    int i;
    for(i = x->pTop-1; i >= 0; i--)
    {
        printf("%d",x->Data[i]);
    }
}
void Menu()
{
    Stack x;
    int n, chon;
    Create_Stack(&x);

    label:
        printf("\n");
        printf("1. Nhap n\n");
        printf("2. Doi co so 2\n");
        printf("3. Doi sang co so 8\n");
        printf("4. Doi sang co so 16\n");
        printf("0. Thoat\n");

        printf("\nVui long chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                {
                    printf("Nhap so n: ");
                    scanf("%d", &n);
                    goto label;
                }
            case 2:
                {
                    printf("%d(10) = ", n);
                    CoSo2(&x, n);
                    Output_Stack(&x);
                    printf("(2)");
                    goto label;
                }
            case 3:
                {
                    printf("%d(10) = ", n);
                    CoSo8(&x, n);
                    Output_Stack(&x);
                    printf("(8)");
                    goto label;
                }
            case 4:
                {
                    printf("%d(10) = ", n);
                    CoSo16(&x, n);
                    Output_Stack(&x);
                    printf("(16)");
                    goto label;
                }
            case 0:
                {
                    break;
                }
        }
}

void main()
{
    Menu();
}
