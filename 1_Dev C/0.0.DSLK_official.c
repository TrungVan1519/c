#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Khai bao cac struct
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
    NODE* pHead;
    NODE* pTail;
}Tlist;

// Khoi tao 1 NODE dau tien
NODE* Create_NODE()
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL)
    {
        printf("Out of memory!\n");
    }
    p ->pNext = NULL;
    return p;
}

// Khoi tao danh sach
void Create_Tlist(Tlist* x)
{
    x ->pHead = x ->pTail = NULL;
}

// Nhap thong tin cho NODE ban dau vua tao
void Input_NODE(NODE* p)
{
    char ho[10], ten[10];
    int tuoi;
    float diem;

    printf("Nhap ho sinh vien: ");
    fflush(stdin);
    gets(ho);


    printf("Nhap ten sinh vien: ");
    fflush(stdin);
    gets(ten);

    // Ghep 2 chuoi ho, ten roi gan cho chuoi name trong struct
    strcpy(p ->Data.name, strcat(ho, ten));

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &tuoi);
    p ->Data.age = tuoi;
    fflush(stdin);

    printf("Nhap diem cua sinh vien: ");
    scanf("%f", &diem);
    p ->Data.score = diem;
    fflush(stdin);

    printf("\n");
    p ->pNext = NULL;
}

// Them 1 NODE ms vao cuoi danh sach
void Add_Last(Tlist* x, NODE* q)
{
    // Danh sach chua co phan tu nao
    if(x ->pHead == NULL)
    {
        x ->pHead = x ->pTail = q;
    }
    // Danh sach da co phan tu
    else
    {
        x ->pTail ->pNext = q;
        x ->pTail = q;
    }
}

// Them 1 NODE ms vao dau danh sach
void Add_First(Tlist* x, NODE* q)
{
    // Danh sach chua co phan tu nao ca
    if(x ->pHead == NULL)
    {
        x ->pHead = x ->pTail = q;
    }
    // Danh sach da co phan tu
    else
    {
        q ->pNext = x ->pHead;
        x ->pHead = q;
    }
}

// Them 1 NODE ms vao 1 vi tri cho trc bat ky --> them sinh vien sau khi xong dsach
void Add_Pos(Tlist* x, NODE* q, int pos)
{

    NODE* temp = x ->pHead;
    int i = 1;

    // Vi tri khong phu hop dau danh sach
    if(pos < 1)
    {
        printf("Khong ton tai vi tri nay!\n");
    }

    // Chen vao vi tri dau
    else if(pos == 1)
    {
        Add_First(x, q);
    }

    else
    {
        while(i != pos - 1)
        {
            temp = temp ->pNext;
            if(temp == NULL)
            {
               break;
            }
            i++;
        }

        // Vi tri khong phu hop cuoi danh sach
        if(temp == NULL)
        {
             printf("Khong ton tai vi tri nay!\n");
        }

        // Chen vao vi tri cuoi
        else if(temp ->pNext == NULL)
        {
            Add_Last(x, q);
        }

        // Chen vao cac vi tri o giua
        else
        {
            q ->pNext = temp ->pNext;
            temp ->pNext = q;
        }
    }
}

// Xoa 1 NODE o 1 vi tri bat ky cho trc co san trong dsach
void Del_Pos(Tlist* x, int pos)
{
    NODE* temp = x ->pHead;
    NODE* del = x ->pHead;
    int i = 1;

    // Vi tri khong phu hop dau danh sach
    if(pos < 1)
    {
        printf("Khong ton tai vi tri nay!\n");
        return;
    }

    // Xoa o vi tri dau
    else if(pos == 1)
    {
        x ->pHead = temp ->pNext;
        temp = x ->pHead;
        free(del);
        del = x ->pHead;
    }

    else
    {
        while(i != pos - 1)
        {
            temp = temp ->pNext;
            if(temp ->pNext == NULL)
            {
                break;
            }
            i++;
        }

        // Vi tri khong phu hop o cuoi danh sach
        if(temp ->pNext == NULL)
        {
            printf("Khong ton tai vi tri nay!\n");
        }

        // Xoa o vi tri cuoi
        else if(temp ->pNext ->pNext == NULL)
        {
            x ->pTail = temp;
            del = temp ->pNext;
            free(del);
            temp ->pNext = NULL;
        }

        // Xoa vi tri o giua
        else
        {
            del = temp ->pNext;
            temp ->pNext = del ->pNext;
            free(del);
        }
    }
}

// Them 1 NODE bat ky vao danh sach sau 1 ten nhap vao
void Add_Name(Tlist* x, NODE* q)
{
    char tmpname[25];
    NODE* temp = x ->pHead;
    printf("Ban muon them sinh vien nay vao sau sinh vien: ");
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
    while(strcmp(temp ->Data.name, tmpname) != 0)
    {
        if(temp == NULL)
            break;
        temp = temp ->pNext;
    }

    // Vi tri khong phu hop o cuoi
    if(temp == NULL)
    {
        printf("Sinh vien khong co trong danh sach");
        return;
    }

    // Chen vao sau moi vi tri trong danh sach
    else if(strcmp(temp ->Data.name, tmpname) == 0 && temp != NULL)
    {
        q ->pNext = temp ->pNext;
        temp ->pNext = q;
        return;
    }
}

// Xoa 1 NODE bat ky co trong danh sach bang ten nhap vao
//void Del_Name(Tlist* x)
//{
//    char tmpname[25];
//    NODE* temp = x ->pHead;
//    NODE* del = x ->pHead;
//
//    printf("Nhap ho va ten sinh vien can xoa: ");
//    fflush(stdin);
//    gets(tmpname);
//
//    if(strcmp(del ->Data.name, tmpname) == 0)
//    {
//        x ->pHead = del ->pNext;
//        free(del);
//        return;
//    }
//    while(strcmp(del ->pNext ->Data.name, tmpname) != 0)
//    {
//        if(del == NULL)
//            break;
//        del = del ->pNext;
//    }
//    if(del == NULL)
//    {
//        printf("Mat hang nay khong co trong danh sach");
//    }
//    else if(del ->pNext ->pNext == NULL)
//    {
//        temp = del;
//        del = del ->pNext;
//        x ->pTail = temp;
//        temp ->pNext = NULL;
//        free(del);
//        return;
//    }
//    else
//    {
//        temp = del;
//        del = del->pNext;
//        temp->pNext = del->pNext;
//        free(del);
//    }
//
//}

// Xoa 1 NODE bat ky co trong danh sach bang ten nhap vao giong ham Del_Name()
void Check_Del(Tlist* x)
{
    char tmpname[25];
    NODE* del = x ->pHead;
    NODE* temp = x ->pHead;
    printf("Nhap ho va ten muon xoa: ");
    fflush(stdin);
    gets(tmpname);
    while(1)
    {
        if(del == NULL)
        {
            printf("Khong co sinh vien trong danh sach");
            return;
        }

        // Xoa vi tri dau
        if(strcmp(del ->Data.name, tmpname) == 0 && del == x ->pHead)
        {
            x ->pHead = x ->pHead ->pNext;
            free(del);
            return;
        }

        // Xoa vi tri cuoi
        else if(strcmp(del ->pNext ->Data.name, tmpname) == 0 && del ->pNext == x ->pTail)
        {
           temp = del;
           del = del ->pNext;
           x ->pTail = temp;
           temp ->pNext = NULL;
           free(del);
           return;
        }

        // Xoa vi tri o giua
        else if(strcmp(del ->pNext ->Data.name, tmpname) == 0 && del ->pNext != x ->pTail)
        {
            temp = del;
            del = del ->pNext;
            temp ->pNext = del ->pNext;
            free(del);
            return;
        }
        del = del ->pNext;
    }
}

// Sua thong tin sinh vien
void Fix_Info(Tlist x)
{
    NODE* temp = x.pHead;
    char tmpname[25];
    printf("Nhap ho va ten sinh vien can sua: ");
    fflush(stdin);
    gets(tmpname);
    while(1)
    {
        if(temp == NULL)
        {
            printf("Khong co sinh vien trong danh sach!");
            return;
        }
        else if(strcmp(temp ->Data.name, tmpname) == 0 && temp != NULL)
        {
            printf("Nhap lai tuoi SV: ");
            scanf("%d", &temp ->Data.age);
            fflush(stdin);

            printf("Nhap lai diem SV: ");
            scanf("%f", &temp ->Data.score);
            fflush(stdin);

            return;
        }
        temp = temp ->pNext;
    }
}
// Nhap thong tin vao danh sach
void Input_Tlist(Tlist* x, int select)
{
    NODE* q = Create_NODE();    // NODE nay chi dung de tao danh sach ban dau con muon them phai tu tao lai NODE o ham main

    if(select == 1)
    {
        Input_NODE(q);
        Add_Last(x, q);
    }
    if(select == 2)
    {
        Input_NODE(q);
        Add_First(x, q);
    }
}

// Xuat thong tin cua 1 NODE
void Output_NODE(NODE* q, int dem)
{
    printf("|%5d|%25s|%5d|%5.2f|\n", dem, q ->Data.name, q ->Data.age, q ->Data.score);
}

// Xuat thong tin cua danh sach
void Output_Tlist(Tlist x)
{
    int dem = 1;
    printf("DANH SACH SINH VIEN:\n");
    printf(" ____________________________________________\n");
    printf("|%5s|%25s|%5s|%5s|\n", "STT", "Ho va ten", "Tuoi", "Diem");
    printf("|%5s|%25s|%5s|%5s|\n", "-----", "-------------------------", "-----", "-----");
    NODE* temp = x.pHead;
    while(temp != NULL)
    {
        Output_NODE(temp, dem);
        temp = temp ->pNext;
        dem++;
    }
    printf("|%5s|%25s|%5s|%5s|\n", "_____", "_________________________", "_____", "_____");
}

// Xoa bo nho
void Free_Memmory(Tlist* x)
{
    NODE* temp = x ->pHead;
    NODE* del = x ->pHead;
    while(temp != NULL)
    {
        temp = temp ->pNext;
        free(del);
        del = temp;
    }
}
// Tao MENU
void Create_MENU()
{
    Tlist x;
    int pos;
    int n, i;
    int select, choose;

    Create_Tlist(&x);
    label:

    printf("\t ________________________________________________________\n");
    printf("\t|                       === MENU ===                     |\n");
    printf("\t|--------------------------------------------------------|\n");
    printf("\t|     1. Nhap danh sach sinh vien                        |\n");
    printf("\t|        1. Them sinh vien vao sau                       |\n");
    printf("\t|        2. Them sinh vien vao dau                       |\n");
    printf("\t|     2. In ra danh sach                                 |\n");
    printf("\t|     3. Them 1 sinh vien theo vi tri nhap               |\n");
    printf("\t|     4. Xoa 1 sinh vien theo vi tri nhap                |\n");
    printf("\t|     5. Them 1 sinh vien theo ten nhap                  |\n");
    printf("\t|     6. Xoa 1 sinh vien theo ten nhap                   |\n");
    printf("\t|     7. Sua thong tin sinh vien theo ten nhap           |\n");
    printf("\t|     0. Thoat chuong trinh                              |\n");
    printf("\t|________________________________________________________|\n");

    printf("Vui long nhap: ");
    scanf("%d", &choose);
    switch(choose)
    {
        case 1:
            {
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                printf("Ban muon nhap theo kieu: ");
                scanf("%d", &select);
                for(i = 0; i < n; i++)
                {
                    Input_Tlist(&x, select);
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
                printf("Ban muon them sinh vien vao vi tri: ");
                scanf("%d", &pos);
                NODE* q = Create_NODE();    // neu khong dung 2 dong nay o day thi
                Input_NODE(q);              // phai dua 2 dong nay len ham Add_Pos
                Add_Pos(&x, q, pos);
                Output_Tlist(x);
                goto label;
            }
        case 4:
            {
                printf("Ban muon xoa sinh vien o vi tri: ");
                scanf("%d", &pos);
                Del_Pos(&x, pos);
                Output_Tlist(x);
                goto label;
            }
        case 5:
            {
                printf("Nhap thong tin cua sinh ban muon them:\n");
                NODE* q = Create_NODE();
                Input_NODE(q);
                Add_Name(&x, q);
                Output_Tlist(x);
                goto label;
            }
        case 6:
            {
                //Del_Name(&x);
                Check_Del(&x);
                Output_Tlist(x);
                goto label;
            }
        case 7:
            {
                Fix_Info(x);
                Output_Tlist(x);
                goto label;
            }
        case 0:
            {
                exit(0);
            }
        default:
            {
                printf("Ban nhap sai. Vui long nhap lai!\n");
                goto label;
            }
    }
    Free_Memmory(&x);
}

int main()
{
    Create_MENU();
    return 0;
}

 ///* 3 loi thuong gap trong danh sach lien ket do la:

    /// #1: Hay quen ham Create_Tlist() ----> K chay dc chuong trinh

    /// #2: Viec truyen tham tri, tham chieu cua bien Tlist x

    ///     + Ham Create_Tlist bat buoc phai truyen tham chieu Tlist* x               ---->  Neu khong truyen tham chieu khi nhap thong tin van ok nhung
    ///                                                                                          den khi xuat du lieu thi se sai het thong tin minh nhap

    ///     + Cac ham Input_Tlist, Add, Del, Free_Mem phai truyen tham chieu Tlist* x ---->  Neu khong truyen tham chieu khi nhap thong tin van ok nhung
    ///                                                                                          den khi xuat du lieu thi se mat het thong tin xuat chi ra moi bang trang

    ///     + Cac ham xuat thong tin, xua thong tin thi co the truyen tham chieu hay tham tri deu dc

    /// #3: O ham Add_Name va Check_Del hay quen temp = temp -> pNext va del = del ->pNext ----> chuong trinh k bao loi nhung k them vs xoa dc
