#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void insertFirst(List *L, address P)
{
    if(isEmpty(*L))
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

void insertValueFirst(List *L, Mahasiswa x)
{
    address P=alokasi(x);
    insertFirst(L,P);
    printf("Data berhasil dimasukkan!");
}

void delFirst(List *L)
{
	if(!isEmpty(*L)){
		address P=(*L).First;
		address Last=findLast(*L);
		if((*L).First==Last){	
			(*L).First=NULL;
		}else{
			(*L).First=(*L).First->Next;
			Last->Next=(*L).First;
		}
		dealokasi(P);
	}else{
		printf("List Empty!");
	}
}

void insertLast(List *L, Mahasiswa x)
{
	address P;
	address Ptr=alokasi(x);
	P=(*L).First;
	if(!isEmpty(*L)){
		address Last=findLast(*L);
		Ptr->Next=Last->Next;
		Last->Next=Ptr;
		printf("Berhasil memasukkan data!");
	}else{
		insertFirst(L, Ptr);
		printf("Berhasil memasukkan data!");
	}
}

void delLast(List *L)
{
	address P, DelNode;
	address Last=findLast(*L);
	P=(*L).First;
	if(!isEmpty(*L)){
		if((*L).First==Last){
			delFirst(L);
		}else{
			while(P->Next!=Last){
				P=P->Next;
			}
			P->Next=Last->Next;
			dealokasi(Last);
		}
	}else{
		printf("List Empty!");
	}
}

void delAfter(List *L, int after)
{
	address P,Q;
	bool found=false;
	P=(*L).First;
	if(isEmpty(*L)){
		if(P->value.nim==after){
			delFirst(L);
		}else{
			do{
				if(P->Next->value.nim==after){
					found=true;
					break;
				}
				P=P->Next;
			}while(P->Next!=(*L).First);
			if(found){
				Q=P->Next;
				P->Next=Q->Next;
				free(Q);
				printf("Del After Berhasil!");
			}else{
				printf("Data %d tidak ditemukan!",after);
			}
		}
	}else{
		printf("List Empty!");
	}
}

void insertAfter(List *L, Mahasiswa a, string after)
{
	address P;
	address Ptr=alokasi(a);
	bool found=false;
	P=(*L).First;
	if(!isEmpty(*L)){
		do{
			if(strcmp(P->value.nama, after)==0){
				found=true;
				break;
			}
			P=P->Next;
		}while(P!=(*L).First);
		if(found){
			Ptr->Next=P->Next;
			P->Next=Ptr;
			printf("Berhasil memasukkan data!");
		}else{
			printf("Data %c tidak ditemukan!",after);
		}
	}else{
		insertFirst(L, Ptr);
		printf("Berhasil memasukkan data!");
	}
}

void showList(List L){
	address P;
	P=L.First;
	if(isEmpty(L)){
		do{
			printf("\nNama: %s ", P->value.nama);
			printf("\nJenis Kelamin: %c", P->value.jk);
			printf("\nNIM: %d ", P->value.nim);
			printf("\nIPK: %f ", P->value.ipk);
			P=P->Next;
		}while(P!=L.First);
	}else{
		printf("List Empty!");
	}
}

void cariByNIM(List L, int nim)
{
	address P;
	P=L.First;
	int temp=0;
	if(isEmpty(L))
    {
		do
        {
			if(P->value.nim==nim)
            {
				printf("\nNama: %s ", P->value.nama);
				printf("\nJenis Kelamin: %c ", P->value.jk);
				printf("\nNIM: %d ", P->value.nim);
				printf("\nIPK: %f ", P->value.ipk);
				temp=1;
			}
			P=P->Next;
		}
        while(P!=L.First);
		if(temp==0)
			puts("Tidak ada data mahasiswa dengan NIM tersebut!");
	}
    else
    {
		printf("List Empty!");
	}
}

void orderByNIM(List *L)
{
	address P,Q;
	Mahasiswa temp;
	P=(*L).First;
	do{
		Q=P->Next;
		while(Q!=(*L).First){
			if(Q->value.nim<P->value.nim){
				temp=P->value;
				P->value=Q->value;
				Q->value=temp;
			}
			Q=Q->Next;	
		}
		P=P->Next;
	}while(P!=(*L).First);
	puts("List telah diurutkan!");
}

void showIPKTertinggi(List L)
{
	address P,Q;
	float temp;
	P=L.First;
	temp=P->value.ipk;
	Q=P;
	if(!isEmpty(L)){
		{
			if(P->value.ipk>temp){
				temp=P->value.ipk;
				Q=P;
			}
			P=P->Next;
		}while(P!=L.First);
		printf("\nNama: %s ", Q->value.nama);
		printf("\nJenis Kelamin: %c ", Q->value.jk);
		printf("\nNIM: %d ", Q->value.nim);
		printf("\nIPK: %f ", Q->value.ipk);
	}{
		printf("List Empty!");
	}
}
					
void showAvgIPK(List L)
{
	address P;
	int counter=0;
	float avg=0;
	P=L.First;
	if(isEmpty(L)){
		do{
			avg+=P->value.ipk;
			counter++;
			P=P->Next;
		}while(P!=L.First);
		printf("\nRata-rata IPK: %.2f", (float)avg/counter);
	}else{
		printf("List Empty!");
	}
}

int main()
{
    List L;
    Mahasiswa a;
    string after;
    int nim;
    createEmpty(&L);
    do
    {
        puts("Program Mahasiswa Gadungan");
        puts("[1] Insert First Mahasiswa");
        puts("[2] Delete First Mahasiswa");
        puts("[3] Insert Last Mahasiswa");
        puts("[4] Delete Last Mahasiswa");
        puts("[5] Insert After Nama Tertentu");
        puts("[6] Delete by NIM");
        puts("[7] Show List");
        puts("[8] Search Mahasiswa by NIM");
        puts("[9] Show Mahasiswa IPK Tertinggi");
        puts("[a] Show Average IPK");
        puts("[b] Order by NIM Ascending");
        puts("[0] Keluar Program");
        printf("Pilih Menu : ");
        getchar();
        switch (getchar())
        {
            case '1':	
                printf("Input Nama: ");scanf("%s", &a.nama);
				fflush(stdin);
				printf("Input Jenis Kelamin: ");scanf("%c", &a.jk);
				printf("Input NIM: ");scanf("%d", &a.nim);
				printf("Input IPK: ");scanf("%f", &a.ipk);
				insertValueFirst(&L, a);					break;
		    case '2':	
                delFirst(&L);
				break;
		    case '3':	
                printf("Input Nama: ");scanf("%s", &a.nama);
				fflush(stdin);
				printf("Input Jenis Kelamin: ");scanf("%c", &a.jk);
				printf("Input NIM: ");scanf("%d", &a.nim);
				printf("Input IPK: ");scanf("%f", &a.ipk);
				insertLast(&L,a);
				break;
		    case '4':	
                delLast(&L);
				break;
		    case '5':	
                if(!isEmpty(L)){
				printf("Input Nama: ");scanf("%s", &a.nama);
				fflush(stdin);
				printf("Input Jenis Kelamin: ");scanf("%c", &a.jk);
				printf("Input NIM: ");scanf("%d", &a.nim);
				printf("Input IPK: ");scanf("%f", &a.ipk);
				printf("Insert setelah nama: ");scanf("%s", &after);
				insertAfter(&L,a,after);
				}
				break;
		    case '6':
                if(!isEmpty(L) && !isOneElement(L)){
				printf("Delete By NIM: ");scanf("%d", &nim);
				delAfter(&L, nim);
				}
				break;
            default:
                printf("Menu Not Found!");
                break;
            case '0':
                return 0;
                break;
		 }
	}
    while (getchar()!=0);
    return 0;
}