#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[25];
    int age;
    float mark;
}Student;

typedef struct NODE
{
    Student Data;
    struct NODE* pNext;
}NODE;

typedef struct
{
    NODE* pHead;
    NODE* pTail;
}Tlist;

NODE* Create_NODE()
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL)
    {
        printf("Khong du bo nho");
    }
    p ->pNext = NULL;
    return p;
}

void Create_Tlist(Tlist *x)
{
    x ->pHead = x->pTail = NULL;
}

void Input_NODE(NODE *p)
{
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(p ->Data.name);

    printf("Nhap tuoi: ");
    scanf("%d", &p ->Data.age);
    fflush(stdin);

    printf("Nhap diem: ");
    scanf("%f", &p->Data.mark);
    fflush(stdin);

    p->pNext = NULL;
}

void Add_Last(Tlist *x, NODE *p)
{
    if(x ->pHead == NULL)
    {
        x ->pHead = x ->pTail = p;
    }
    else
    {
        x ->pTail ->pNext = p;
        x ->pTail = p;
    }
}

void Add_Name(Tlist *x, NODE* p)
{
    NODE* tmp =x ->pHead;
    char tmpname[25];
    printf("Ban muon them vao sau sinh vien: ");
    fflush(stdin);
    gets(tmpname);

//    while(1)
//    {
//        if(temp == NULL)
//        {
//            printf("Khong co mat hang nay trong danh sach");
//        }
//        if(strcmp(temp ->Data.name, tmpname) == 0)
//        {
//            q ->pNext = temp ->pNext;
//            temp ->pNext = q;
//            return;
//        }
//        temp = temp ->pNext;
//    }
    while(1)
    {
        if(tmp == NULL)
        {
            printf("Sinh vien khong co trong danh sach!");
        }
        else if(strcmp(tmp ->Data.name, tmpname) == 0 && tmp != NULL)
        {
            p ->pNext = tmp ->pNext;
            tmp ->pNext = p;
            return;
        }
       tmp = tmp ->pNext;
    }
}

void Del_Name(Tlist *x)
{
    NODE* tmp = x ->pHead;
    NODE* del = x ->pHead;
    char tmpname[25];
    printf("Nhap ho ten sinh vien muon xoa: ");
    fflush(stdin);
    gets(tmpname);

    while(1)
    {
        if(del == NULL)
        {
            printf("Khong co sinh vien trong danh sach");
            return;
        }
        if(strcmp(del ->Data.name, tmpname) == 0 && del == x ->pHead)
        {
            x ->pHead = del ->pNext;
            free(del);
            return;
        }
        else if(strcmp(del ->pNext ->Data.name, tmpname) == 0 && del ->pNext == x ->pTail)
        {
            x ->pTail = del;
            del = del ->pNext;

            x ->pTail ->pNext = NULL;
            free(del);
            return;
        }
        else if(strcmp(del ->pNext ->Data.name, tmpname) == 0 && del ->pNext != x ->pTail)
        {
            tmp = del;
            del = del ->pNext;
            tmp ->pNext = del ->pNext;
            free(del);
            return;
        }
        del = del ->pNext;
    }
}

void Fix_Info(Tlist x)
{
    NODE* tmp = x.pHead;
    char tmpname[25];
    printf("Nhap ho ten sinh vien muon sua: ");
    fflush(stdin);
    gets(tmpname);
    while(1)
    {
        if(tmp == NULL)
        {
            printf("Khong co sinh vien trong danh sach!");
            return;
        }
        else if(strcmp(tmp ->Data.name, tmpname) == 0 && tmp != NULL)
        {
            printf("Nhap lai tuoi SV: ");
            scanf("%d", &tmp ->Data.age);
            fflush(stdin);

            printf("Nhap lai diem SV: ");
            scanf("%f", &tmp ->Data.mark);
            fflush(stdin);

            return;
        }
        tmp = tmp ->pNext;
    }
}

void Input_Tlist(Tlist *x)
{
    NODE* p = Create_NODE();
    Input_NODE(p);
    Add_Last(x, p);
}

void Output_NODE(NODE* p, int dem)
{
    printf("\t|%5d|%25s|%5d|%5.2f|\n", dem, p ->Data.name, p ->Data.age, p->Data.mark);
}

void Output_Tlist(Tlist x)
{
    int dem = 1;
    NODE* y =x.pHead;
    printf("\t ___________________________________________\n");
    printf("\t|%5s|%25s|%5s|%5s|\n", "STT", "Ho va ten", "Tuoi", "Diem");
    printf("\t|%5s|%25s|%5s|%5s|\n", "-----", "-------------------------", "-----", "-----");
    while(y != NULL)
    {
        Output_NODE(y, dem);
        dem++;
        y = y ->pNext;
    }
    printf("\t|%5s|%25s|%5s|%5s|\n", "_____", "_________________________", "_____", "_____");
}

void Free_Mem(Tlist* x)
{
    NODE* tmp = x ->pHead;
    NODE* del = x ->pHead;
    while(del != NULL)
    {
        tmp = tmp ->pNext;
        free(del);
        del = tmp;
    }
}
void Menu()
{
    Tlist x;
    int n, i;
    int chon;
    Create_Tlist(&x);

    label:
        printf("\n");
        printf("1. Nhap danh sach\n");
        printf("2. Xuat danh sach\n");
        printf("3. Them SV\n");
        printf("4. Xoa SV\n");
        printf("5. Sua thong tin SV\n");
        printf("0. Thoat\n");

    printf("\n Vui long chon: ");
    scanf("%d", &chon);
    switch(chon)
    {
        case 1:
            {
                printf("Nhap so SV: ");
                scanf("%d", &n);
                for( i = 0; i < n; i++)
                {
                    printf("\n");
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
                NODE* p = Create_NODE();
                Input_NODE(p);
                Add_Name(&x, p);
                Output_Tlist(x);
                goto label;
            }
        case 4:
            {
                Del_Name(&x);
                Output_Tlist(x);
                goto label;
            }
        case 5:
            {
                Fix_Info(x);
                Output_Tlist(x);
                goto label;
            }
        case 0:
            {
                break;
            }
    }
    Free_Mem(&x);
}

void main()
{
    Menu();
}
