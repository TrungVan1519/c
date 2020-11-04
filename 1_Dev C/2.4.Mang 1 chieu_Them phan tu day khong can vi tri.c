#include<stdio.h>
#define MAX 5

void Input(int* a, int* n)
{
    int i;
    for(i = 0; i < *n; i++)
    {
        printf("Nhap: ");
        scanf("%d", &a[i]);
    }
}

void Output(int* a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

void Sort(int* a, int *n)
{
    int i, j;
    int tmp;
    for(i = 0; i < *n - 1; i++)
    {
        for(j = i + 1; j < *n; j++)
        {
            if(a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void Add(int* a, int* n, int* value, int pos)
{
    int i, j;
    for(i = 0; i < *n; i++)
    {
        if(*value <= a[i] && *value > a[i-1])
        {
            *n += 1;
            pos = i;
            for(j = *n - 2; j >= pos; j--)
            {
                a[j+1] = a[j];
            }
            a[pos] = *value;
        }
        /*
        else if(*value > a[*n - 1])
        {
            printf("\nDay la:\n%d\n\n", *n);
            return;
        }
        */

        else if(*value > a[*n - 1])
        {
            *n += 1;
            pos = *n - 1;
            printf("\nSo phan tu cua day la: %d\n", *n);
            a[pos] = *value;
            return;
        }

        else if(*value < a[0])
        {
            *n += 1;
            pos = 0;
            for(i = *n - 2; i >= 0; i--)
            {
                a[i+1] = a[i];
            }
            a[pos] = *value;
        }
    }
}
void main()
{
    int arr[MAX];
    int n;
    int value, pos;
    printf("Nhap n: ");
    scanf("%d", &n);
    Input(arr, &n);
    Sort(arr, &n);
    Output(arr, n);
    label:
    printf("\nNhap gia tri muon them: ");
    scanf("%d", &value);
    Add(arr, &n, &value, pos);
    Output(arr, n);
    goto label;
}
/*  Chú ý:
    - Kiểu thêm này chỉ sử dụng được khi mảng đã được sắp xếp rồi - tức là phải có hàm Sort

    - Thắc mắc 1 chút về đoạn thêm value vào vị trí cuối cùng của mảng - tức là đoạn else if thứ 2 trong hàm Add,
    không hiểu tại sao khi chạy nó lại chạy thừa số phần tử mà còn chạy giá trị đúng mới kinh chứ
    - Cách giải quyết: đã thêm return để chỉ viết 1 lần xong là thoát nhưng thực chất vẫn muốn hiểu tại sao

    - Thêm 1 thắc mắc nữa là ở if và else-if thứ 3 trong vòng lawoj for theo suy nghĩ thì phải là i < *n - 2 mới đúng
    nhưng nếu ta viết là i < *n - 1 thì vẫn chạy đúng thế mới lạ
    - Cách giải quyết: Méo hiểu sao cả 2 vẫn đúng, vẫn chạy ngon nghẻ
*/
