#include <stdio.h> 
#include <stdlib.h>

#define MAX 10 //MAX adalah nama variabel (bisa bebas) yang diberi nilai 10 

//deklarasi fungsi dan prosedur
void isiArray(int arr[]); 
void showArray(int arr[]); 
int jumlahAllElemen(int arr[]); 
int cariNilaiTerbesar(int arr[]); 
int cariNilaiTerkecil(int arr[]); 
int cariNilaiDalamArray(int arr[], int nilai); 

//deklarasi fungsi tambahan
void pesanEnter();

int main() 
{ 
    int array[MAX], sum, terbesar, terkecil, pilihan, nilai, posisi; 
    do
    { 
        system("clear");
        puts("Menu Hitung Array"); 
        puts("1. Isi Array"); 
        puts("2. Tampilkan Isi Array"); 
        puts("3. Tampilkan Hasil Penjumlahan Semua Elemen"); 
        puts("4. Tampilkan Nilai Terbesar"); 
        puts("5. Tampilkan Nilai Terkecil"); 
        puts("6. Cari Nilai dalam Array"); 
        puts("0. Exit"); 
        printf("Pilih menu: ");
        scanf("%d", &pilihan); 
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
                sum = jumlahAllElemen(array); 
                printf("Total Semua Elemen: %d\n", sum); 
                pesanEnter(); 
                break; 
            case 4: 
                terbesar = cariNilaiTerbesar(array); 
                printf("Bilangan Terbesar: %d\n", terbesar); 
                pesanEnter(); 
                break; 
            case 5: 
                terkecil = cariNilaiTerkecil(array); 
                printf("Bilangan Terkecil: %d\n", terkecil); 
                pesanEnter(); 
                break; 
            case 6: 
                printf("Masukkan nilai yang ingin dicari: ");
                scanf("%d", &nilai);
                posisi = cariNilaiDalamArray(array, nilai);
                if (posisi != -1) {
                    printf("Nilai %d ditemukan pada indeks ke-%d.\n", nilai, posisi);
                } else {
                    printf("Nilai %d tidak ditemukan di dalam array.\n", nilai);
                }
                pesanEnter(); 
                break; 
            case 0: 
                break; 
            default: 
                printf("Maaf, menu tidak ditemukan!\n"); 
                pesanEnter(); 
                break; 
        }
    }
    while(pilihan != 0); 
}

void isiArray(int arr[]) 
{ 
    int i; 
    for (i = 0; i < MAX; i++) 
    { 
        printf("Masukkan Nilai Indeks ke-%d: ", i);
        scanf("%d", &arr[i]); 
    } 
}

void showArray(int arr[]) 
{ 
    int i; 
    for (i = 0; i < MAX; i++) 
    { 
        printf("%d\n", arr[i]); 
    } 
    printf("\n");
}

int jumlahAllElemen(int arr[])  
{ 
    int i, total = 0; 
    for (i = 0; i < MAX; i++) 
    { 
        total += arr[i]; 
    } 
    return total; 
}

int cariNilaiTerbesar(int arr[]) 
{ 
    int i, bil_besar = arr[0]; 
    for (i = 1; i < MAX; i++) 
    { 
        if (arr[i] > bil_besar) 
        { 
            bil_besar = arr[i]; 
        }
    }
    return bil_besar; 
}

int cariNilaiTerkecil(int arr[]) 
{ 
    int i, bil_kecil = arr[0]; 
    for (i = 1; i < MAX; i++) 
    { 
        if (arr[i] < bil_kecil) 
        { 
            bil_kecil = arr[i]; 
        }
    }
    return bil_kecil; 
}

int cariNilaiDalamArray(int arr[], int nilai) 
{
    int i; 
    for (i = 0; i < MAX; i++) 
    { 
        if (arr[i] == nilai) 
        { 
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

void pesanEnter() 
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}
