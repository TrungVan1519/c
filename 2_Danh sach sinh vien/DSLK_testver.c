#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char name[25];
    int age;
    float score;
}Student;
typedef struct NODE
{
    Student Data;
    struct NODE* pNext;
}NODE;
typedef struct
{
    NODE* pFirst;
    NODE* pLast;
}Tlist;

NODE* Create_NODE()
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL)
    {
        printf("Het bo nho\n");
    }
    p ->pNext = NULL;
    return p;
}

void Create_Tlist(Tlist* x)
{
    x ->pFirst = x ->pLast = NULL;
}

void Input_NODE(NODE* p)
{
    char hoten[25];
    int tuoi;
    float diem;

    printf("Nhap ho va ten: ");
    fflush(stdin);
    gets(hoten);
    strcpy(p ->Data.name, hoten);

    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    p ->Data.age = tuoi;
    fflush(stdin);

    printf("Nhap diem: ");;
    scanf("%f", &diem);
    p ->Data.score = diem;
    fflush(stdin);

    p ->pNext = NULL;
}

void Add_Last(Tlist* x, NODE* p)
{
    if(x ->pFirst == NULL)
    {
        x ->pFirst = x ->pLast = p;
    }
    else
    {
        x ->pLast ->pNext = p;
        x ->pLast = p;
    }
}

void Add_First(Tlist* x, NODE* p)
{
    if(x ->pFirst == NULL)
    {
        x ->pFirst = x ->pLast = NULL;
    }
    else
    {
        p ->pNext = x ->pFirst;
        x ->pFirst = p;
    }
}

void Input_Tlist(Tlist* x)
{
    printf("\n");
    NODE* q = Create_NODE();
    Input_NODE(q);
    Add_Last(x, q);
}

void Output_NODE(NODE* p, int dem)
{
    printf("|%5d|%25s|%5d|%5.2f|\n", dem, p ->Data.name, p ->Data.age, p ->Data.score);
}

void Output_Tlist(Tlist x)
{
    int dem = 1;
    NODE* temp = x.pFirst;
    printf("\nLIST:\n");
    printf(" ___________________________________________\n");
    printf("|%5s|%25s|%5s|%5s|\n", "STT", "Ho va ten", "Tuoi", "Diem");
    printf("|%5s|%25s|%5s|%5s|\n", "-----", "-------------------------", "-----", "-----");

    while(temp != NULL)
    {
        Output_NODE(temp, dem);
        temp = temp ->pNext;
        dem++;
    }
    printf("|%5s|%25s|%5s|%5s|\n", "_____", "_________________________", "_____", "_____");
}

void Free_Mem(Tlist* x)
{
    NODE* del = x ->pFirst;
    while(x ->pFirst != NULL)
    {
        x ->pFirst = x ->pFirst ->pNext;
        free(del);
        del = x ->pFirst;
    }
}

void Check_Add(Tlist* x, char ten[])
{
    NODE* q = Create_NODE();
    Input_NODE(q);
    NODE* temp = x ->pFirst;

    printf("Ban muon them sinh vien nay vao sau sinh vien nao?\n");
    fflush(stdin);
    gets(ten);
    while(1)
    {
        if(temp == NULL)
        {
            printf("Khong co sinh vien trong danh sach");
        }
        if(strcmp(temp ->Data.name, ten) == 0)
        {
            q ->pNext = temp ->pNext;
            temp ->pNext = q;
            return;
        }

        temp = temp ->pNext;
    }

}
//void Check_Del(Tlist* x, char ten[])
//{
//    NODE* del = x ->pFirst;
//    NODE* temp1 = x ->pFirst;
//    NODE* temp2 = x ->pFirst;
//    printf("Nhap ho va ten muon xoa: ");
//    fflush(stdin);
//    gets(ten);
//    while(1)
//    {
//        if(del == NULL)
//        {
//            printf("Khong co sinh vien trong danh sach");
//            return;
//        }
//        if(strcmp(del ->Data.name, ten) == 0 && del == x ->pFirst)
//        {
//            x ->pFirst = x ->pFirst ->pNext;
//            free(del);
//            //del = x ->pFirst;
//            return;
//        }
//        else if(strcmp(del ->Data.name, ten) == 0 && del ->pNext == NULL)
//        {
//           for(temp1 = x ->pFirst; temp1 != NULL; temp1 = temp1 ->pNext)
//           {
//                if(temp1 ->pNext ->pNext == NULL)
//                {
//                    temp2 = temp1;
//                    free(temp1 ->pNext);
//                    x ->pLast = temp2;
//                    temp2 ->pNext = NULL;
//                    return;
//                }
//           }
//        }
//        else if(strcmp(del ->Data.name, ten) == 0 && del != x ->pFirst && del ->pNext != NULL)
//        {
//            for(temp1 = x ->pFirst; temp1 != NULL; temp1 = temp1 ->pNext)
//            {
//                if(temp1 ->pNext  == del)
//                {
//                    temp2 = temp1;
//                    temp1 = temp1 ->pNext;
//                    temp2 ->pNext = temp1 ->pNext;
//                    free(temp1);
//                    return;
//                }
//            }
//        }
//        del = del ->pNext;
//    }
//}

void Check_Del(Tlist* x, char ten[])
{
    NODE* temp = x ->pFirst;
    NODE* del = x ->pFirst;
    printf("Nhap ho ten sinh vien can xoa: ");
    fflush(stdin);
    gets(ten);
    if(strcmp(del ->Data.name, ten) == 0)
    {
        x ->pFirst = del ->pNext;
        free(del);
        return;
    }
    while(strcmp(del ->pNext ->Data.name, ten) != 0)
    {
        if(del == NULL)
            break;
        del = del ->pNext;
    }
    if(del == NULL)
    {
        printf("Sinh vien khong co trong danh sach");
    }
    else if(del ->pNext ->pNext == NULL)
    {
        temp = del;
        del = del ->pNext;
        x ->pLast = temp;
        temp ->pNext = NULL;
        free(del);
        return;
    }
    else
    {
        temp = del;
        del = del->pNext;
        temp->pNext = del->pNext;
        free(del);
    }
}
void Find_NODE(Tlist* x, char ten[])
{
    NODE* temp = x ->pFirst;

    printf("Nhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(ten);

    while(1)
    {
        if(temp == NULL)
        {
            printf("Sinh vien khong co trong danh sach\n");
            return;
        }
        else if(strcmp(temp ->Data.name, ten) == 0)
        {
            printf("Sinh vien co trong danh sach\n");
            return;
        }
        temp = temp ->pNext;
    }
}
void Menu()
{
    Tlist x;
    int chon, n, i;
    char ten[25];
    Create_Tlist(&x);

    label:
        printf("\n");
    printf("1. Nhap danh sach\n");
    printf("2. Xuat danh sach\n");
    printf("3. Them sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Tim kiem sinh vien\n");
    printf("0. Thoat\n");
    printf("\n====  End  ====\n");

    printf("Vui long chon: ");
    scanf("%d", &chon);
    switch(chon)
    {
        case 1:
        {
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            for(i = 0; i < n; i++)
            {
                Input_Tlist(&x);

            }
            goto label;
        }
        case 2:
        {
            Output_Tlist(x);
            goto label;
        }
        case 3:
        {
            Check_Add(&x, ten);
            Output_Tlist(x);
            goto label;
        }
        case 4:
        {
            Check_Del(&x, ten);
            Output_Tlist(x);
            goto label;
        }
        case 5:
        {
            Find_NODE(&x, ten);
            goto label;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            printf("Vui long nhap lai: ");
            goto label;
        }
    }
    Free_Mem(&x);
}

int main()
{
    Menu();
    return 0;
}
