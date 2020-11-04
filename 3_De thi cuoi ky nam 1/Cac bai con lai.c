#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void BCNN(int a, int b)
{
    int ucln, bcnn;
    int n;
    n = a * b;
    while(a != b)
    {
        if(a < b)
        {
            b = b - a;
        }
        else
        {
            a = a - b;
        }
    }
    ucln = a;
    bcnn = n / ucln;
    printf("BCNN = %d", bcnn);
}

void hePT()
{
    int a1, b1, c1;
    int a2, b2, c2;
    float d, dx, dy;

    printf("Nhap he so 1: ");
    scanf("%d%d%d", &a1, &b1, &c1);
    printf("Nhap he so 2: ");
    scanf("%d%d%d", &a2, &b2, &c2);

    d = a1 * b2 - a2 * b1;
    dx = c1 * b2 - c2 * b1;
    dy = a1 * c2 - a2 * c1;

    if(d == dx == dy == 0)
    {
        printf("He VSN");
    }
    if(d != 0)
    {
        printf("He co nghiem duy nhat x = %.2f, y = %.2f", dx / d, dy /d);
    }
    if(d == 0 && (dx != 0 || dy != 0))
    {
        printf("He VN");
    }
}

void tangTruong()
{
    int nam;
    float GDP2014, GDP, tocdo;
    nam = 2014;
    printf("Nhap GDP nam 2014: ");
    scanf("%f", &GDP2014);
    GDP = GDP2014;
    printf("Nhap toc do tang truong GDP: ");
    scanf("%f", &tocdo);
    printf("%4s %s", "Nam", "GDP");
    printf("\n%4.1f %d", GDP2014, nam);
    while(GDP < (2 * GDP2014))
    {
        GDP = GDP + (GDP * tocdo / 100);
        nam++;
        printf("\n%4.1f %d", GDP, nam);
    }
}

void inNam()
{
    int thang, nam;
    printf("Nhap thang, nam: ");
    scanf("%d%d", &thang, &nam);
    switch(thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        {
            printf("Thang %d nam %d co 31 ngay", thang, nam);
            break;
        }
    case 4: case 6: case 9: case 11:
        {
            printf("Thang %d nam %d co 30 ngay", thang, nam);
            break;
        }
    case 2:
        {
        if(nam % 400 == 0 || nam % 4 == 0 && nam % 100 != 0)
        {
            printf("Thang 2 nam %d co 29 ngay", nam);
        }
        else
        {
            printf("Thang 2 nam %d co 28 ngay", nam);
        }
        break;
        }
    default:
        {
            printf("Khong co thang nay!");
        }
    }
}

void maTran()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

    int i, j, k;
    int chon;
    label:
        printf("\n");
        printf("1. Tong 2 ma tran\n");
        printf("2. Tich 2 ma tran\n");
        printf("3. In ma tran xoan oc\n");
        printf("0. Thoat");
    printf("\nChon: ");
    scanf("%d", &chon);
    switch(chon)
    {
    case 1:
        {
            int n, m;
            int i, j;
            printf("Nhap so hang, cot 2 ma tran: ");
            scanf("%d%d", &n, &m);
            printf("Nhap ma tran 1:\n");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    printf("Nhap: ");
                    scanf("%d", &a[i][j]);
                }
            }
            printf("Nhap ma tran 2:\n");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    printf("Nhap: ");
                    scanf("%d", &b[i][j]);
                }
            }
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            printf("\nMa tran tong la:\n");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    printf("%4d", c[i][j]);
                }
                printf("\n");
            }
            goto label;
        }
    case 2:
        {
            int n, m, l;
            int i, j, k;
            printf("Nhap so hang va cot cua ma tran 1: ");
            scanf("%d%d", &n, &m);
            printf("Nhap so cot cua ma tran 2: ");
            scanf("%d", &l);
            printf("Nhap ma tran 1:\n");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    printf("Nhap: ");
                    scanf("%d", &a[i][j]);
                }
            }
            printf("Nhap ma tran 2:\n");
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < l; j++)
                {
                    printf("Nhap: ");
                    scanf("%d", &b[i][j]);
                }
            }
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < l; j++)
                {
                    c[i][j] = 0;
                    for(k = 0; k < m; k++)
                    {
                        c[i][j] += a[i][k] * b[k][j];

                    }
                    printf("%4d", c[i][j]);
                }
                printf("\n");
            }
            goto label;
        }
    case 3:
        {
            int a[MAX][MAX];
            int n;
            printf("Nhap kich thuoc cua ma tran: ");
            scanf("%d", &n);
            int giatri = 1;
            int left = 0, right = n - 1, top = 0, bot = n - 1;
            int i, j;
//            printf("Nhap kich thuoc cua ma tran: ");
//            scanf("%d", &n);
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
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    printf("%4d", a[i][j]);
                }
                printf("\n");
            }
            goto label;
        }
    case 0:
        {
            break;
        }
    default:
        {
            printf("Ban nhap sai. Hay nhap lai!");
            goto label;
        }
    }
}

void Menu()
{
    int luachon;
    label:
        printf("\n");
        printf("1. Tim BCNN cua 2 so\n");
        printf("2. Bien luan he PT\n");
        printf("3. Tang truong GDP\n");
        printf("4. In so ngay trong thang, nam\n");
        printf("5. Ma tran\n");
        printf("0. Thoat\n");
    printf("Vui long chon: ");
    scanf("%d", &luachon);
    switch(luachon)
    {
    case 1:
        {
            int a, b;
            printf("Nhap 2 so a, b can tim BCNN: ");
            scanf("%d%d", &a, &b);
            BCNN(a, b);
            goto label;
        }
    case 2:
        {
            hePT();
            goto label;
        }
    case 3:
        {
            tangTruong();
            goto label;
        }
    case 4:
        {
            inNam();
            goto label;
        }
    case 5:
        {
            maTran();
            goto label;
        }
    case 0:
        {
            break;
        }
    }
}
int main()
{
    Menu();
    return 0;
}

