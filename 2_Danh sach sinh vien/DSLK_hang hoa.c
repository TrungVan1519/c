//Viet chuong trinh quan ly hang hoa dung danh sach moc noi
// 1 hang hoa: ten, don gia, so luong, tien
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char ten[25];
    int soluong;
    float gia;
    float tien;
}Hanghoa;

typedef struct NODE
{
    Hanghoa Data;
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
        printf("Het bo nho!");
    }
    p ->pNext = NULL;
    return p;
}

NODE* Create_Tlist(Tlist* x)
{
    x ->pHead = x ->pTail = NULL;
}

void Input_NODE(NODE* p)
{
    char tmpten[25];
    int tmpsoluong;
    float tmpgia;
    float tmptien;

    printf("Nhap ten hang hoa: ");
    fflush(stdin);
    gets(tmpten);
    strcpy(p ->Data.ten, tmpten);

    printf("Nhap so luong hang hoa: ");
    scanf("%d", &tmpsoluong);
    p ->Data.soluong = tmpsoluong;
    fflush(stdin);

    printf("Nhap don gia cho hang hoa: ");
    scanf("%f", &tmpgia);
    p ->Data.gia = tmpgia;
    fflush(stdin);

    tmptien = tmpgia * tmpsoluong;
    p ->Data.tien = tmptien;
    p ->pNext = NULL;
}

void Add_Last(Tlist* x, NODE* p)
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

void Add_First(Tlist* x, NODE* p)
{
    if(x ->pHead == NULL)
    {
        x ->pHead = x ->pTail = p;
    }
    else
    {
        p ->pNext = x ->pHead;
        x ->pHead = p;
    }
}

void Input_Tlist(Tlist* x)
{
    printf("\n");
    NODE* p = Create_NODE();
    Input_NODE(p);
    Add_Last(x, p);
}

void Check_Add(Tlist* x, char tenmh[])
{
    NODE* q = Create_NODE();
    Input_NODE(q);
    NODE* temp = x ->pHead;

    printf("Ban muon them mat hang nay vao sau mat hang: ");
    fflush(stdin);
    gets(tenmh);
    while(1)
    {
        if(temp == NULL)
        {
            printf("Khong co mat hang nay trong danh sach");
        }
        if(strcmp(temp ->Data.ten, tenmh) == 0)
        {
            q ->pNext = temp ->pNext;
            temp ->pNext = q;
            return;
        }
        temp = temp ->pNext;
    }
}
void Check_Del(Tlist* x, char tenmh[])
{
    NODE* temp = x ->pHead;
    NODE* del = x ->pHead;
    printf("Nhap ten mat hang can xoa: ");
    fflush(stdin);
    gets(tenmh);
    if(strcmp(del ->Data.ten, tenmh) == 0)
    {
        x ->pHead = del ->pNext;
        free(del);
        return;
    }
    while(strcmp(del ->pNext ->Data.ten, tenmh) != 0)
    {
        if(del == NULL)
            break;
        del = del ->pNext;
    }
    if(del == NULL)
    {
        printf("Mat hang nay khong co trong danh sach");
    }
    else if(del ->pNext ->pNext == NULL)
    {
        temp = del;
        del = del ->pNext;
        x ->pTail = temp;
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
void Output_NODE(NODE* p, int dem)
{
    printf("\t|%5d|%25s|%10d|%10.2f|%10.2f|\n", dem, p ->Data.ten, p ->Data.soluong, p ->Data.gia, p ->Data.tien);
}

void Find_NODE(Tlist* x, char tenmh[])
{
    NODE* temp = x ->pHead;

    printf("Nhap ten mat hang can tim: ");
    fflush(stdin);
    gets(tenmh);

    while(1)
    {
        if(temp == NULL)
        {
            printf("Mat hang nay khong co trong danh sach\n");
            return;
        }
        else if(strcmp(temp ->Data.ten, tenmh) == 0)
        {
            printf("Mat hang nay co trong danh sach\n");
            return;
        }
        temp = temp ->pNext;
    }
}

void Output_Tlist(Tlist x)
{
    NODE* temp = x.pHead;
    int dem  = 1;
    printf("\t ________________________________________________________________\n");
    printf("\t|%5s|%25s|%10s|%10s|%10s|\n", "STT", "Ten", "So luong", "Gia ca", "Thanh tien");
    printf("\t|%5s|%25s|%10s|%10s|%10s|\n", "-----", "-------------------------", "----------", "----------", "----------");
    while(temp != NULL)
    {
        Output_NODE(temp, dem);
        dem++;
        temp = temp ->pNext;
    }
    printf("\t|%5s|%25s|%5s|%10s|%10s|\n", "_____", "_________________________", "__________", "__________", "__________");
}

void Free_Mem(Tlist* x)
{
    NODE* del = x ->pHead;
    while(x ->pHead != NULL)
    {
        x ->pHead = x ->pHead ->pNext;
        free(del);
        del = x ->pHead;
    }
}
void Menu()
{
    Tlist x;
    int n, i, chon;
    char tenmh[25];
    Create_Tlist(&x);

    label:
    printf("\t _______________________________________________\n");
    printf("\t|                  === Menu ===                 |\n");
    printf("\t|-----------------------------------------------|\n");
    printf("\t|       1. Nhap danh sach                       |\n");
    printf("\t|       2. Xuat danh sach                       |\n");
    printf("\t|       3. Them hang hoa                        |\n");
    printf("\t|       4. Xoa hang hoa                         |\n");
    printf("\t|       5. Tim kiem hang hoa                    |\n");
    printf("\t|       0. Thoat chuong trinh                   |\n");
    printf("\t|_______________________________________________|\n");
    printf("\nVui long chon: ");
    scanf("%d", &chon);
    switch(chon)
    {
        case 1:
        {
            printf("Nhap so mat hang: ");
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
            Check_Add(&x, tenmh);
            Output_Tlist(x);
            goto label;
        }
        case 4:
        {
            Check_Del(&x, tenmh);
            Output_Tlist(x);
            goto label;
        }
        case 5:
        {
            Find_NODE(&x, tenmh);
            goto label;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            printf("Ban nhap sai. Vui long nhap lai: ");
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
