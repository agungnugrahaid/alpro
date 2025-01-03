#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char string[255];

typedef struct Mahasiswa
{
    string nama;
    int nim;
    float ipk;
    char jk;
}Mahasiswa;

typedef struct tNode *address;

typedef struct tNode
{
    Mahasiswa value;
    address Next;
}Node;

typedef struct List
{
    address First;
}List;

void createEmpty(List *L)
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
    if(L.First->Next==L.First)
        return true;
    else
        return false;
}

address alokasi(Mahasiswa x)
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

address FindLast(List L)
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

int main()
{
    do
    {
        puts("Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        puts("[1] Program Mahasiswa Gadungan");
        printf("Input Menu : ");
        getchar();
        switch (getchar())
        {
            case '1':
                return 0;
                break;
    
            default:
                printf("Menu Not Found!");
                getchar();
                break;
            case 0:
                return 0;
                break;
        }
    } while (getchar()!='0');
    return 0;
}