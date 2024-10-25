#include <stdio.h> 
#include <stdlib.h>
//#include <conio.h>

#define MAX 10 //MAX adalah nama variabel (bisa bebas) yang diberi nilai 10 

//deklarasi fungsi dan prosedur
void isiArray(int arr[]); 
void showArray(int arr[]); 
int jumlahAllElemen(int arr[]); 
int cariNilaiTerbesar(int arr[]); 

//deklarasi fungsi tambahan
void pesanEnter();

int main() 
{ 
    int array[MAX], sum, terbesar, pilihan; 
    do
    { 
        //system("clear"); 
        puts("Menu Hitung Persegi"); 
        puts("1. Isi Array"); 
        puts("2. Tampilkan Isi Array"); 
        puts("3. Tampilkan Hasil Penjumlahan Semua Elemen"); 
        puts("4. Tampilkan Nilai Terbesar"); 
        puts("0. Exit"); 
        printf("Pilih menu: ");
            scanf("%d",&pilihan); 
        switch(pilihan) 
        { 
            case 1:  
                isiArray(array); 
                pesanEnter(); 
                break; 
            case 2:  
                showArray(array); 
                pesanEnter(); 
                break; 
            case 3:
                sum=jumlahAllElemen(array); 
                printf("Total Semua Elemen: %d",sum); 
                pesanEnter(); 
                break; 
            case 4: 
                terbesar=cariNilaiTerbesar(array); 
                printf("Bilangan Terbesar: %d",terbesar); 
                pesanEnter(); 
                break; 
            case 0: 
                break; 
            default: 
                printf("Maaf menu tidak ditemukan!"); 
                pesanEnter(); 
                break; 
        }
    }
    while(pilihan!=0); 
}

void showArray(int arr[]) 
{ 
    int i; 
    for(i=0;i<MAX;i++)
    { 
        printf("%d\n",arr[i]); 
    } 
} 

void isiArray(int arr[]) 
{ 
    int i; 
    for(i=0;i<MAX;i++)
    { 
        printf("Masukkan Nilai Indeks ke %d: ",i);
        scanf("%d",&arr[i]); 
    } 
} 

int jumlahAllElemen(int arr[])  
{ 
    int i, total=0; 
    for(i=0;i<MAX;i++)
    { 
        total=total+arr[i]; 
    } 
    return total; 
} 

int cariNilaiTerbesar(int arr[]) 
{ 
    int i, bil_besar=arr[0]; 
    for(i=0;i<MAX;i++)
    { 
        if(arr[i]>bil_besar)
        { 
            bil_besar=arr[i]; 
        }
    }
    return bil_besar; 
}

void pesanEnter()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}