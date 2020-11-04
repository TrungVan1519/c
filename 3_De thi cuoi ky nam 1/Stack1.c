#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct NODE
{
    int Data;
    struct NODE* pNext;
}NODE;

typedef struct
{
    NODE* pTop;
}Stack;

NODE* Create_NODE()
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL)
    {
        printf("Khong du bo nho!");
    }
    p ->pNext = NULL;
    return p;
}

void Create_Tlist(Stack *x)
{
    x ->pTop = NULL;
}

int IsEmpty(Stack *x)
{
    if(x ->pTop == NULL)
    {
        return 1;
    }
    return 0;
}

void Push(Stack *x, NODE* p)
{
    if(IsEmpty(&x) == 1)
    {
        x ->pTop = p;
    }
    else
    {
        p ->pNext  =x ->pTop;
        x ->pTop = p;
    }
}

void Pop(Stack *x, int *y)
{
    if(IsEmpty(&x) == 1)
    {
        printf("Stack chua co phan tu nao");
        return;
    }
    NODE* p = x ->pTop;
    x ->pTop = x ->pTop ->pNext;
    *y = p ->Data;
    return;
}

void CoSo2(Stack *x, int n)
{
    while(n > 0)
    {
        NODE* p = Create_NODE();
        p ->Data = n %2;
        Push(&x, p);
        n /= 2;
    }
}
void CoSo8(Stack *x, int n)
{
    while(n > 0)
    {
        NODE* p = Create_NODE();
        p ->Data = n %8;
        Push(&x, p);
        n /= 8;
    }
}
void CoSo16(Stack *x, int n)
{
    while(n > 0)
    {
        NODE* p = Create_NODE();
        p ->Data = n %16;
        Push(&x, p);
        n /= 16;
    }
}
void Output_Stack(Stack *x)
{
    while()
}
