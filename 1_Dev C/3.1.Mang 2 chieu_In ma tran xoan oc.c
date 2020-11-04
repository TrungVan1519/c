#include<stdio.h>
#define MAX 100

void Input();
void Output();

int main()
{
    int a[MAX][MAX], n;
    printf("Nhap so hang va cot ma tran: ");
    scanf("%d", &n);
    Input(a, n);
    printf("Ma tran xoan oc la:\n");
    Output(a, n);
    return 0;
}

void Input(int a[MAX][MAX], int n)
{
    int giatri = 1;
    int top = 0, bot = n - 1, left = 0, right = n - 1;
    int i, j;
    while(giatri <= n * n)
    {
        for(j = left; j <= right; j++)
        {
            a[top][j] = giatri++;
        }
        top++;
        for(i = top; i <= bot; i++)
        {
            a[i][right] = giatri++;
        }
        right--;
        for(j = right; j >= left; j--)
        {
            a[bot][j] = giatri++;
        }
        bot--;
        for(i = bot; i >= top; i--)
        {
            a[i][left] = giatri++;
        }
        left++;
    }
}
 void Output(int a[MAX][MAX], int n)
 {
     int i, j;
     for(i = 0; i < n; i++)
     {
         for(j = 0; j < n; j++)
         {
             printf("%4d", a[i][j]);
         }
         printf("\n");
     }
 }
