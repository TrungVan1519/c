#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct
{
    char name[25];
    int age;
    float score;
}Student;

typedef struct NODE
{
    Student Data;
    struct NODE* Next;  // dung de quang day tu con tro dau sang con tro tiep theo
}NODE;

typedef struct LIST
{
    NODE* pHead;
    NODE* pTail;
}Tlist;

//Create a NODE
NODE* Creat_NODE()
{
    NODE* p = NULL;     // goi 1 con tro ms va khoi tao no
    p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL)
    {
        printf("Out of memmory!!!");
    }
    p->Next = NULL;
    return p;
}
//Creat a list
void Creat_Tlist(Tlist* x)
{
    x->pHead = x->pTail = NULL;        //ban dau Tlist chua co phan tu nao nen 2 con tro cua no = NULL
}
//Enter information for the NODE
void Input_NODE(NODE* p)
{
    char tname[25];                     //goi bien ms nhap va gan bang cac thanh phan cua NODE
    int tage;
    float tscore;

    printf("Enter the full name: ");
    fflush(stdin);
    gets(tname);
    strcpy(p->Data.name, tname);

    printf("Enter the age: ");
    scanf("%d", &tage);
    fflush(stdin);
    p->Data.age = tage;

    printf("Enter the score: ");
    scanf("%f", &tscore);
    fflush(stdin);
    p->Data.score = tscore;

    p->Next = NULL;
}
//Add a new NODE to the top of the list
void Add_First(Tlist* x, NODE* p)
{
    if(x->pHead == NULL)
    {
        x->pHead = x->pTail = p;
    }
    else
    {
        p->Next = x->pHead;
        x->pHead = p;
    }
}
//Add a new NODE to the end of the list
void Add_Last(Tlist* x, NODE* p)
{
    if(x->pHead == NULL)
    {
        x->pHead = x->pTail = p;
    }
    else
    {
        x->pTail->Next = p;
        x->pTail = p;
    }
}
void Add_Pos(Tlist* x, int pos)
{
    int i = 1;
    NODE* temp = NULL;
    NODE* q = NULL;
    temp = x->pHead;
    q = Creat_NODE();
    Input_NODE(q);
    if(pos < 1)
    {
        printf("There are no students in this position!!!");
    }
    else if(pos == 1 || temp == NULL)
    {
        Add_First(x, q);
    }
    else
    {
        while(i != pos - 1)
        {
            temp = temp->Next;
            if(temp == NULL)
                break;
            i++;
        }
        //printf("Gia tri cua i la %d\n", i);
        if(temp == NULL)
        {
            printf("There are no students in this position");
        }
        else if(temp -> Next == NULL)
        {
            Add_Last(x, q);
        }
        else
        {
            q->Next = temp->Next;
            temp->Next = q;
        }
    }
}
//Delete the first NODE
void Del_First(Tlist* x)
{
    NODE* q = NULL;
    //q = Creat_NODE();
    q = x -> pHead;
    if(x -> pHead == NULL)
    {
        return;
    }
    else
    {
        x -> pHead = q -> Next;
        free(q);
        return;
    }
}
//Delete the last NODE
void Del_Last(Tlist* x)
{
    NODE* temp;
    NODE* del;

    if(x -> pHead == NULL)
    {
        return;
    }
    else
    {
        if(del ->Next)
    }
}
void Del_Pos(Tlist* x, int pos)
{
    int i = 1;
    NODE* temp = x -> pHead;
    //NODE* q;// = Creat_NODE();
    if(pos < 1)
    {
        printf("There are no students in this position!!!");
    }
    if(pos == 1)
    {
        Del_First(x);
    }
    else
    {
        while(i != pos)
        {
            temp = temp -> Next;
            if(temp = NULL)
                break;
            i++;
        }
        if(temp == NULL)
        {
            printf("There are no students in this position!!!");
        }
        else if(temp -> Next== NULL)
        {
            Del_Last(x);
        }
        else
        {
            NODE* del = temp->Next;
            temp->Next = del->Next;
            free(del);

        }
    }
}

//void del_Node_at_pos(Tlist* x, int pos)
//{
//    //Tim vi tri truoc pos
//    int i = 1;
//    NODE* tmp = x->pHead;
//
//    if (pos < 1)
//    {
//        printf("\t\tKhong co vi tri thu %d\n",pos);
//        return;
//    }
//
//    //Neu vi tri nhap vao la vi tri dau tien
//    if (pos == 1)
//    {
//        x->pHead = x->pHead->Next;
//        free(tmp);
//        return;
//    }
//    else //Vi tri khac 1
//    {
//        while (i!=pos-1)
//        {
//            tmp = tmp->Next;
//            if (tmp->Next == NULL)
//                break;
//            i++;
//        }
//
//        //Neu so thu tu nhap vao la phan tu cuoi cung
//        if (tmp->Next == NULL)
//            {
//                printf("\t\tKhong co phan tu thu %d\n",pos);
//            }
//        else if (tmp->Next->Next==NULL)
//            {
//                x->pTail = tmp;
//                tmp = tmp->Next;
//                x->pTail->Next = NULL;
//                free(tmp);
//            }
//        else
//        {
//            NODE* del = tmp->Next;
//            tmp->Next = del->Next;
//            free(del);
//        }
//    }
//}
//Enter the information for the list
void Input_Tlist(Tlist* x, int l)
{
    NODE* p = NULL;        //!!! Cho con tro p = p o ham NODE* tao p o ham nay:
                                //! Giu o ham va cho di cung vs 2 ham Input nhap p, Add them p la dung vi nhu the se tao, nhap, them n NODE
    p = Creat_NODE();           //! Cho con tro p = p o ham NODE* tao p o ham main va nhan p day o ham nay la sai vi nhu the tao 1 NODE
    if(l == 1)                  //!     ma lai nhap, them n NODE
    {
        Input_NODE(p);
        Add_First(x, p);

    }
    if(l == 2)
    {
        Input_NODE(p);
        Add_Last(x, p);
    }
    else
    {
        printf("You enter wrong. Please re-enter!!!");
    }
}
//Display the information for the NODE
void Output_NODE(NODE* p)
{
    printf("\t|%25s|%8d|%8.2f|\n", p->Data.name, p->Data.age, p->Data.score);
}
//Display the information for the List
void Output_Tlist(Tlist x)
{
    printf("\n\n\tLIST:\n");
    printf("\t%25s_%8s_%8s\n", " _________________________", "________", "________");
    printf("\t|%25s|%8s|%8s|\n", "Name", "Age", "Score");
    printf("\t|%25s|%8s|%8s|\n", "-------------------------", "--------", "--------");
    NODE* temp = NULL;         // goi 1 con tro ms y cung dc hoac dung con tro p minh tao cung dc
    temp = x.pHead;            // con tro nay k quan trong vi no chi co tac dung nhu bien dem for(i = 0; i < n; i++)
    while(temp != NULL)        // co the dung vong lap khac for(NODE* y = x.pHead; y != NULL; y->Next)
    {
        Output_NODE(temp);
        temp = temp->Next;
    }
    printf("\t|%25s|%5s|%5s|", "_________________________", "________", "________");
    printf("\n\n");
}
//Free memmory
void Free_Memmory(Tlist* x)
{
    NODE* temp = NULL;         //goi con tro ms a, b va chung cung khong quan trong vi chung chi co tac dung nhu bien dem for(i = 0; i < n; i++)
    NODE* del = NULL;         // { b = a; free(b); }
    temp = del = x->pHead;
    while(temp != NULL)
    {
        temp = temp->Next;
        free(del);
        del = temp;
    }
}
//Creat a Menu
void Creat_Menu()
{
    Tlist x;
    int i, n, m, l;     //!!! Cho con tro p = p o ham NODE* tao p o ham main nay:
    int pos;                //! Giu nguyen o ham nay, bo ham Input_Tlist va cho 3 ham tao, nhap, them p trong cung 1 vong lap la dung vi nhu the se tao, nhap, them n NODE
    Creat_Tlist(&x);        //! Khong giu nguyen o ham nay ma truyen len ham Input_Tlist va nhan p o do la sai vi nhu the se tao 1 NODE ma lai nhap, them n NODE
    label:
    printf("\t ___________________________________________________\n");
    printf("\t|                    === MENU ===                   |\n");
    printf("\t|---------------------------------------------------|\n");
    printf("\t|  1. Enter information for the list.               |\n");
    printf("\t|     1. Add students to the top of the list.       |\n");
    printf("\t|     2. Add students to the end of the list.       |\n");
    printf("\t|  2. Display list information.                     |\n");
    printf("\t|  3. Add a new student to the list.                |\n");
    printf("\t|  4. Delete one student in the list.               |\n");
    printf("\t|  0. Exit the list.                                |\n");
    printf("\t|___________________________________________________|\n");

    printf("\nPlease choose: ");
    scanf("%d", &m);
    switch(m)
    {
        case 1:
        {
            //printf("Enter information for the List\n");
            printf("Would you like to add students after or before the list: ");
            scanf("%d", &l);
            printf("Enter the number of students: ");
            scanf("%d", &n);
            for(i = 0; i < n; i++)
            {
                Input_Tlist(&x, l);         //! Dung ham nay khi cho p = NODE* tao p o ham Input_Tlist
//                NODE* p = Creat_NODE();   //! Dung 3 ham nay khi cho p = NODE* tao p o ham main
//                Input_NODE(p);
//                Add_Last(&x, p);
            }
            goto label;
        }
        case 2:
        {
            //printf("Display the List\n\n");
            Output_Tlist(x);
            goto label;
        }
        case 3:
        {
            printf("Enter the position to add: ");
            scanf("%d", &pos);
//            printf("Would you like to add a new student after or before this position: ");
//            scanf("%d", &l);
            Add_Pos(&x, pos);
            Output_Tlist(x);
            goto label;
        }
        case 4:
        {
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            //del_Node_at_pos(&x, pos);
            Del_Pos(&x, pos);
            Output_Tlist(x);
            goto label;
        }
        case 5:
            {
//                printf("Nhap vi tri muon xoa dau: ");
//                scanf("%d", &pos);
                Del_First(&x);
                Output_Tlist(x);
                goto label;
            }
        case 6:
            {
//                printf("Nhap vi tri muon xoa cuoi: ");
//                scanf("%d", &pos);
                //del_Node_at_pos(&x, pos);
                Del_Last(&x);
                Output_Tlist(x);
                goto label;
            }
        case 0:
        {
            printf("Thank you very much.");
            printf("\n");
            exit(0);
        }
        default:
        {
            printf("You chose wrong. Please select again!!!");
            goto label;
        }
    }
    Free_Mem(&x);
}
int main()
{
    Creat_Menu();
    return 0;
    //!!!!! Chú ý quan trọng nhất là khi thêm hay xóa đều thực hiện vs tk NODE phía trc
}
