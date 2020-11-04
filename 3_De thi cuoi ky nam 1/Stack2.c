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
    if(x ->pTop == 0)
        return 1;
}


int IsFull (Stack* Stack)
{
    return (Stack->pTop == MAX);
}

void Push(Stack *x, int sodu)
{
    if(!IsFull(x))
    {
        x ->Data[x ->pTop] = sodu;
        x ->pTop++;
    }
}

//void DoiCoSo(Stack *x, int n, int chon)
//{
//    int sodu;
//    if(chon == 2)
//    {
//        while(n > 0)
//        {
//            //sodu = n % 2;
//            Push(x, n % 2);
//            n = n / 2;
//        }
//    }
//    else if(chon == 3)
//    {
//        while(n > 0)
//        {
//            //sodu = n % 8;
//            Push(x, n % 8);
//            n = n / 8;
//        }
//    }
//    else if(chon == 4)
//    {
//        while(n > 0)
//        {
//            //sodu = n % 16;
//            Push(x, n % 16);
//            n = n / 16;
//        }
//    }
//}
void CoSo2(Stack *x, int n)
{
    while(n > 0)
    {
        Push(x, n%2);
        //n = n / 2;
        n/=2;
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

void Pop(Stack *x)
{
    int i;
    for(i = x ->pTop - 1; i >= 0; i--)
    {
        printf("%d", x ->Data[i]);
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
                    //DoiCoSo(&x, n, chon);
                    CoSo2(&x, n);
                    Pop(&x);
                    Create_Stack(&x);
                    goto label;
                }
            case 3:
                {
                    printf("%d(10) = ", n);
                    //DoiCoSo(&x, n, chon);
                    CoSo8(&x, n);
                    Pop(&x);
                    Create_Stack(&x);
                    goto label;
                }
            case 4:
                {
                    printf("%d(10) = ", n);
                    //DoiCoSo(&x, n, chon);
                    CoSo16(&x, n);
                    Pop(&x);
                    Create_Stack(&x);
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
