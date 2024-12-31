#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char string[255];
typedef struct Date
{
    int tgl;
    int bln;
    int thn;
}Date;

typedef struct Barang
{
    string nama;
    int kode;
    int jumlah;
    int harga;
    Date tgl_beli;
}Barang;

typedef struct tNode *address;

typedef struct tNode
{
    Barang value;
    address Next;
}Node;

typedef struct List
{
    address First;
}List;

void CreateEmpty(List *L)
{
    (*L).First=NULL;
}

bool isEmpty(List L)
{
    if(L.First==NULL)
        return true;
    else
        return false;
}

bool isOneElement(List L)
{
    if(L.First->Next=NULL)
        return true;
    else
        return false;
}

address alokasi(Barang x)
{
    address P=(Node*)malloc(sizeof(Node));
    if(P!=NULL)
    {
        P->value=x;
        P->Next=NULL;
    }
    return P;
}

void dealokasi(address P)
{
    free(P);
}

void InsertFirst(List *L, address P)
{
    P->Next=(*L).First;
    (*L).First=P;
}

void InsertValueFirst(List *L, Barang x)
{
    address P=alokasi(x);
    InsertFirst(L,P);
    printf("Data berhasil dimasukkan!");
}

//Main Action
int main()
{
    return 0;
}