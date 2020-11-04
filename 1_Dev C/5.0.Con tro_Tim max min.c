#include<stdio.h>
#include <stdlib.h>
#define MAX 100

int* Input_Array (int *pn)
{
    int *p;
    int i;
    scanf("%d",pn);
    p = (int*)malloc ((*pn)*sizeof(int));
    for (i=0; i<*pn; i++)
    {
        scanf("%d",p+i);
    }
    return p;
}

void Output_Array (int* p, int n)
{
    int i;
    printf("\t");
    for (i=0; i<n; i++)
        printf("%5d",*(p+i));
    printf("\n");
}

void Max_Pos (int* p, int n, int* pmax, int* ppos)
{
    int i;
    *pmax = *p;
    *ppos = 0;
    for (i=1; i<n; i++)
    {
        if (*(p+i)>*pmax)       //a[i] > max
        {
            *pmax = *(p+i);
            *ppos = i;
        }
    }
}

//void tim_kiem(int* a, int* n)
//{
//    int max, vitri, i;
//    vitri = 0;
//    max = a[0];
//    for(i = 1; i < n; i++)
//    {
//        if(max < a[i])
//        {
//            max = a[i];
//            vitri += 1;
//        }
//    }
//}
int main()
{
    int* p = NULL;
    int n;
    int max, pos;
    p = Input_Array(&n);
    printf("\tMang vua nhap la: \n");
    Output_Array(p,n);
    Max_Pos(p,n,&max,&pos);
    printf("\tGia tri MAX la %d tai vi tri thu %d\n",max,pos);
//    tim_kiem(a, &n);
//    printf("MAX = %d", max);
//    printf("Vi tri cua max trong day la: %d", vitri);
    return 0;
}
