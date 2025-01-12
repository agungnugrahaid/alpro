#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char string[255];
typedef struct{
	int tgl;
	int bln;
	int thn;
}Date;
typedef struct{
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

typedef struct{
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
	if(L.First->Next==NULL)
		return true;
	else
		return false;
}

address alokasi(Barang x){
	address P=(Node*)malloc(sizeof(Node));
	if(P!=NULL){
		P->value=x;
		P->Next=NULL;
	}
	return P;
}

void dealokasi(address P){
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
	printf("Berhasil memasukkan data!");
}

void DelFirst(List *L)
{
	if(!isEmpty(*L)){
		address P=(*L).First;
		(*L).First=(*L).First->Next;
		free(P);
		printf("Del First Berhasil!");
	}else{
		printf("List Empty!");
	}
}

void InsertLast(List *L, Barang x)
{
	address P;
	address Ptr=alokasi(x);
	P=(*L).First;
	if(!isEmpty(*L)){
		while(P->Next!=NULL){
			P=P->Next;
		}
		P->Next=Ptr;
		printf("Berhasil memasukkan data!");
	}else{
		InsertFirst(L, Ptr);
		printf("Berhasil memasukkan data!");
	}
}

void DelLast(List *L)
{
	address P,Last;
	P=(*L).First;
	if(!isEmpty(*L)){
		if(P->Next==NULL){
			DelFirst(L);
		}else{
			while(P->Next->Next!=NULL){
			P=P->Next;
			}
			Last=P->Next;
			P->Next=NULL;
			free(Last);
			printf("Del Last berhasil!");
		}
	}else{
		printf("List Empty!");
	}
}

void DelAfter(List *L, int after)
{
	address P,Q;
	bool found=false;
	P=(*L).First;
	if(!isEmpty(*L)){
		if(P->value.kode==after){
			DelFirst(L);
		}else{
			while(P->Next!=NULL){
				if(P->Next->value.kode==after){
					found=true;
					break;
				}
				P=P->Next;
			}
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

void InsertAfter(List *L, Barang a, int after)
{
	address P;
	address Ptr=alokasi(a);
	bool found=false;
	P=(*L).First;
	if(!isEmpty(*L)){
		while(P!=NULL){
			if(P->value.kode==after){
				found=true;
				break;
			}
			P=P->Next;
		}
		if(found){
			Ptr->Next=P->Next;
			P->Next=Ptr;
			printf("Berhasil memasukkan data!");
		}else{
			printf("Data tidak ditemukan! %d",after);
		}
	}else{
		InsertFirst(L, Ptr);
		printf("Berhasil memasukkan data!");
	}

}

void ShowList(List L){
	address P;
	P=L.First;
	if(!isEmpty(L)){
		do{
			printf("\nKode: %d", P->value.kode);
			printf("\nNama: %s", P->value.nama);
			printf("\nJml: %d", P->value.jumlah);
			printf("\nHrg: %d", P->value.harga);
			printf("\nTgl Beli: %d/%d/%d", P->value.tgl_beli.tgl,P->value.tgl_beli.bln,P->value.tgl_beli.thn);
			P=P->Next;
		}while(P!=NULL);
	}else{
		printf("List Empty!");
	}
}

void cariByTglBeli(List L, Date d)
{
	address P;
	P=L.First;
	int temp=0;
	if(!isEmpty(L)){
		while(P!=NULL){
			if(P->value.tgl_beli.tgl==d.tgl && P->value.tgl_beli.bln==d.bln && P->value.tgl_beli.thn==d.thn){
				printf("\nKode: %d", P->value.kode);
				printf("\nNama: %s", P->value.nama);
				printf("\nJml: %d", P->value.jumlah);
				printf("\nHrg: %d", P->value.harga);
				printf("\nTgl Beli: %d/%d/%d", P->value.tgl_beli.tgl,P->value.tgl_beli.bln,P->value.tgl_beli.thn);
				temp=1;
			}
			P=P->Next;
		}
		if(temp==0)
			puts("Tidak ada barang dengan tanggal beli tersebut!");
	}else{
		printf("List Empty!");
	}
}

void orderByKode(List *L)
{
	address P,Q;
	Barang temp;
	P=(*L).First;
	while(P!=NULL){
		Q=P->Next;
		while(Q!=NULL){
			if(Q->value.kode>P->value.kode){
				temp=P->value;
				P->value=Q->value;
				Q->value=temp;
			}
			Q=Q->Next;	
		}
		P=P->Next;
	}
	puts("List telah diurutkan!");
}

int main()
{
	List L;
	int after, kode;
	Barang a;
	Date d;
	CreateEmpty(&L);
	do
	{
		puts("Menu Toko Sebelah");
		puts("1. Insert First Barang");
		puts("2. Delete First Barang");
		puts("3. Insert Last Barang");
		puts("4. Delete Last Barang");
		puts("5. Insert After Kode Tertentu");
		puts("6. Delete By Kode Tertentu");
		puts("7. Show List");
		puts("8. Cari By Tgl Beli");
		puts("9. Order By Kode Descending");
		puts("0. Exit");
		puts("Pilih : ");
		switch(getchar())
		{
		case '1' :	printf("Input Kode Barang: ");scanf("%d", &a.kode);
					fflush(stdin);
					printf("Input Nama Barang: ");scanf("%s", a.nama); 		//tidak perlu & karena tipe data otomatis ke pointer array alamat pertama (&a.nama[0])
					printf("Input Jml Barang: ");scanf("%d", &a.jumlah);
					printf("Input Hrg Barang: ");scanf("%d", &a.harga);
					printf("Input Tgl Beli: ");scanf("%d", &a.tgl_beli.tgl);
					printf("Input Bln Beli: ");scanf("%d", &a.tgl_beli.bln);
					printf("Input Thn Beli: ");scanf("%d", &a.tgl_beli.thn);
					InsertValueFirst(&L, a);
					break;
		case '2' :	DelFirst(&L);
					break;
		case '3' :	printf("Input Kode Barang: ");scanf("%d", &a.kode);
					fflush(stdin);
					printf("Input Nama Barang: ");scanf("%s", a.nama);
					printf("Input Jml Barang: ");scanf("%d", &a.jumlah);
					printf("Input Hrg Barang: ");scanf("%d", &a.harga);
					printf("Input Tgl Beli: ");scanf("%d", &a.tgl_beli.tgl);
					printf("Input Bln Beli: ");scanf("%d", &a.tgl_beli.bln);
					printf("Input Thn Beli: ");scanf("%d", &a.tgl_beli.thn);
					InsertLast(&L,a);
					break;
		case '4' :	DelLast(&L);
					break;
		case '5' :	if(!isEmpty(L)){
						printf("Input Kode Barang: ");scanf("%d", &a.kode);
						fflush(stdin);
						printf("Input Nama Barang: ");scanf("%s", a.nama);
						printf("Input Jml Barang: ");scanf("%d", &a.jumlah);
						printf("Input Hrg Barang: ");scanf("%d", &a.harga);
						printf("Input Tgl Beli: ");scanf("%d", &a.tgl_beli.tgl);
						printf("Input Bln Beli: ");scanf("%d", &a.tgl_beli.bln);
						printf("Input Thn Beli: ");scanf("%d", &a.tgl_beli.thn);
						printf("Insert setelah Kode Barang: ");scanf("%d", &after);
						InsertAfter(&L,a,after);
					}
					break;
		case '6' :	if(!isEmpty(L) && !isOneElement(L)){
						printf("Input Kode Barang yang mau dihapus: ");scanf("%d", &kode);
						DelAfter(&L, kode);
					}
		case '7' :	ShowList(L);
					break;
		case '8' :	printf("Input Tgl Beli: ");scanf("%d", &d.tgl);
					printf("Input Bln Beli: ");scanf("%d", &d.bln);
					printf("Input Thn Beli: ");scanf("%d", &d.thn);
					cariByTglBeli(L,d);
					break;
		case '9' :	orderByKode(&L);
					break;
		case '0' :	return 0;
		}
	}while(getchar()!=27);
	getchar();
	return 0;
}