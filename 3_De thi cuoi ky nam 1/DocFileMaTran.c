#include<stdio.h>
#define MAX 50


void Nhap(int a[][MAX], int n, int m, FILE* f)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }
}

void Xuat(int a[][MAX], int n, int m, FILE* f)
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

//void Xuat1(int a[][MAX], int n, int m, FILE* f)
//{
//    int i, j;
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < m; j++)
//        {
//            fprintf(f, "%4d", a[i][j]);
//        }
//        printf("\n");
//    }
//}
void Tong(int a[][MAX], int b[][MAX], int c[][MAX], int n, int m, FILE* f)
{
    int i, j;
    for(i = 0; i < n;i++)
    {
        for(j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%4d", c[i][j]);
            fprintf(f, "%4d", c[i][j]);
        }
        printf("\n");
        fprintf(f, "\n");
    }
}
void main()
{
    FILE* f;
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int n, m;
    f = fopen("C:\\Users\\admin\\Desktop\\DocMaTran.txt", "r");
    fscanf(f, "%d%d", &n, &m);
    printf("Ma tran A la:\n");

    Nhap(a, n, m, f);
    Xuat(a, n, m, f);
    fscanf(f,"%d%d",&n, &m);
    printf("\nMa tran B la:\n");
    Nhap(b, n, m, f);
    Xuat(b, n, m, f);
    printf("Ma tran C la:\n");
    //Tong(a, b, c, n, m,f);
    fclose(f);

    f = fopen("C:\\Users\\admin\\Desktop\\DocMaTran.txt", "a");
    fprintf(f, "Ma tran tong:\n");
    Tong(a, b, c, n, m, f);
    //Xuat1(c, n, m, f);
    fclose(f);
}
