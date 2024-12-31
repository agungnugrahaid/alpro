#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Define TypeDefs
typedef float typeint;
typedef struct tNode *address;
typedef struct tNode
{
    typeint value;
    address Next;
}Node;
typedef struct 
{
    address First;
}List;

/* The Default Linked List Circular Functions */

// Inisialisasi, buat List dengan 1 elemen berisi NULL
void createEmpty(List *L)
{
    (*L).First=NULL;
}

// Cek apakah list kosong atau tidak
bool isEmpty(List L)
{
    if (L.First==NULL)
        return true;
    else
        return false;
}

//Cek apakah list hanya mempunyai 1 elemen
bool isOneElement(List L)
{
    if(L.First->Next==L.First)
        return true;
    else
        return false;
}

//Pengalokasian memory pada sistem sesuai dengan tipe data yang akan disimpan
address alokasi(typeint x)
{
    address P=(Node*)malloc(sizeof(Node));
    if (P!=NULL)
    {
        P->value=x;
        P->Next=NULL;
    }
    return P;
}

//De-Alokasi memori pada address yang dituju
void deAlokasi(address P)
{
    free(P);
}

//Mencari address elemen terakhir. Karena Linked List Circular, maka address elemen terakhir adalah yang setelahnya adalah address elemen pertama
address findLast(List L)
{
    address P=L.First;
    if(!isEmpty(L))
    {
        while (P->Next!=(L).First)
        {
            P=P->Next;
        }
    }
    return P;
}

//Insert First
void insertFirst(List *L, address P)
{
    if (isEmpty(*L))
    {
        (*L).First=P;
        P->Next=(*L).First;
    }
    else
    {
        address Last=findLast(*L);
        P->Next=(*L).First;
        (*L).First=P;
        Last->Next=(*L).First;
    }
}

//Insert Value First
void insertValueFirst(List *L, typeint x)
{
    address P=alokasi(x);
    insertFirst(L,P);
    printf("\nFirst Value Added Successfully!\n");
}

//Delete First
void delFirst(List *L)
{
    if (!isEmpty(*L))
    {
        address P=(*L).First;
        address Last=findLast(*L);
        //Modifikasi Address First menjadi NULL apabila hanya ada 1 elemen di dalam list
        if ((*L).First==Last)
        {
            (*L).First=NULL;        
        }
        //Modifikasi Address First menjadi Next of First, dan Address Next of Last menjadi First (Ingat, ini circular!)
        else
        {
            (*L).First=(*L).First->Next;
            Last->Next=(*L).First;
        }
        //Free Memori setelah adjustment terhadap address
        deAlokasi(P);
    }
    else
    {
        printf("\nCan't Delete, List is Empty!\n");
    }
}

//Print value di dalam List
void showList(List L)
{
    address P;
    P=L.First;
    //Tampilkan data dari L.First sampai data sebelum L.First (Ingat ini Circular!)
    if(!isEmpty(L))
    {
        do
        {
            printf("%.2f ", P->value);
            P=P->Next;
            if(P!=L.First)
            {
                printf("-> ");
            }
        }
        while (P!=L.First);
        //getchar();
    }
    else
    {
        printf("NULL");
    }
}

//Insert Value pada posisi address terakhir, jika kosong ya jadi value of First and the Last
void insertLast(List *L, typeint x)
{
    address P;
    address Ptr=alokasi(x);
    P=(*L).First;
    if (!isEmpty(*L))
    {
        address Last=findLast(*L);
        Ptr->Next=Last->Next;
        Last->Next=Ptr;
        printf("\nLast Value Added Successfully!\n");
    }
    else
    {
        insertFirst(L, Ptr);
        printf("\nFirst AND Last Value Added Successfully!\n");
    }
}

//Delete 
void delLast(List *L)
{
    address P, DelNode;
    address Last=findLast(*L);
    P=(*L).First;
    if (!isEmpty(*L))
    {
        if((*L).First==Last)
        {
            delFirst(L);
        }
        else
        {
            while (P->Next!=Last)
            {
                P=P->Next;
            }
            P->Next=Last->Next;
            deAlokasi(Last);
        }
    }
    else
    {
        printf("\nCan't Delete, List is Empty!");
    }
}

void subMenu()
{

}

void mergeLists(List *L1, List *L2)
{
    if (isEmpty(*L2))
    {
        printf("\nList Merged Successfully!");
        return;
    }
    if (isEmpty(*L1))
    {
        (*L1).First = (*L2).First;
    }
    else
    {
        address lastL1 = findLast(*L1);
        address lastL2 = findLast(*L2);

        lastL1->Next = (*L2).First;
        lastL2->Next = (*L1).First;     // Ingat ini circular!
    }
    (*L2).First = NULL;
    printf("\nList Merged Successfully!");
}

int main()
{
    //Aesthetic on my Terminal
    system("clear");
    
    //Deklarasi Variable
    List L1, L2 ;
    typeint a, after;
    
    //Inisialisasi List
    createEmpty(&L1);
    createEmpty(&L2);

    //Menampilkan Menu
    do
    {
        system("clear");
        puts("\nMenu Program Pengelolaan List");
        puts("[1] Insert Data List A");              //use insertLast()
        puts("[2] Insert Data List B");              //use insertLast()
        puts("[3] Delete Data List A");              //use delLast()
        puts("[4] Delete Data List B");              //use delLast()
        puts("[5] Show List A & List B");            //
        puts("[6] Sub-Menu Operasi dan Eksekusi");
        puts("[7] Merge List");
        puts("[0] Exit");
        printf("Pilih : ");
        switch (getchar())
        {
        case '1':
            printf("[1] Insert Data List A\nInput Your Data: "); scanf("%f", &a);
            insertLast(&L1, a);
            printf("List A : ");
            showList(L1);
            getchar();
            break;
        case '2':
            printf("[2] Insert Data List B\nInput Your Data: "); scanf("%f", &a);
            insertLast(&L2, a);
            printf("List B : ");
            showList(L2);
            getchar();
            break;
        case '3':
            printf("[3] Delete Data List A");
            delLast(&L1);
            printf("\nList A : ");
            showList(L1);
            getchar();
            break;
        case '4':
            printf("[4] Delete Data List B");
            delLast(&L2);
            printf("\nList B : ");
            showList(L2);
            getchar();
            break;
        case '5':
            getchar();
            printf("[5] Show Lists Value\nList A: ");
            showList(L1);
            printf("\nList B: ");
            showList(L2);
            break;
        case '7':
            getchar();
            printf("[7] Merge List");
            mergeLists(&L1, &L2);
            printf("\nList A: ");
            showList(L1);
            printf("\nList B: ");
            showList(L2);
            break;
        default:
            getchar();
            printf("Menu Not Found!");
            break;
        case '0':
            return 0;
        }
    } 
    while (getchar()!=0);
    return 0;
}