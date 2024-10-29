#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3

typedef char string[255];
typedef struct
    {
    int tahun;
    string merk;
    }
    Mobil;

void init(Mobil m[]);
void entryData(Mobil m[]);
void show(Mobil m[]);
void bubbleSortArray(Mobil m[]);

//deklarasi prosedur getch sebagai "pause" sebelum menu terhapus oleh command "clear"
void getch();

int main()
{
    int pilihan;
    Mobil m[3];
    do
    {
        //menggunakan command "clear" istead of "cls" karena menggunakan environment linux
        system("clear");
        puts("Menu Data Mobil (Penerapan Record/Struct, Array dan Bubble Sort)");
        puts("1. Inisialisasi Data");
        puts("2. Masukkan Data Mobil");
        puts("3. Tampilkan Data Mobil");
        puts("4. Urutkan Data Mobil");
        puts("0. Exit");
        printf("Pilih menu: ");
            scanf("%d",&pilihan);
        getchar();
        switch(pilihan)
        {
            case 1: 
                init(m);
                getch();
                break;
            case 2: 
                entryData(m);
                getch();
                break;
            case 3: 
                show(m);
                getch();
                break;
            case 4:
                bubbleSortArray(m);
                getch();
                break;
            case 0: 
                break;
            default: 
                printf("Maaf menu tidak ditemukan!");
                getch();
                break;
        }
    }
    while(pilihan!=0);
}

void init(Mobil m[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        //Mengosongkan data Tahun
        m[i].tahun=0;
        //Mengosongkan data Merk
        strcpy(m[i].merk,"\0");
    }
}

void entryData(Mobil m[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("Data Mobil Ke-%d\n",i+1);
        printf("Input Tahun\t: ");
            scanf("%d",&m[i].tahun);
        getchar();
        //fflush(stdin);
        printf("Input Merk\t: ");
        fgets(m[i].merk, 255, stdin);
        //fgets(alamat, sizeof(alamat),stdin);
        //menghilangkan karakter \n dari input fgets
        m[i].merk[strcspn(m[i].merk,"\n")] = '\0';
    }
}

void show(Mobil m[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("\nData Mobil Ke-%d",i+1);
        printf("\nTahun\t: %d",m[i].tahun);
        printf("\nMerk\t: %s",m[i].merk);
    }
}

void bubbleSortArray(Mobil m[])
{
    int i, j, tempTahun;
    string tempMerk;
    for(i = 0; i < MAX; i++)
    {
        for(j = i; j < MAX; j++)
        {
            //sorting Tahun dari kecil ke besar
            if(m[j].tahun < m[i].tahun)
            {
                //"swap" value Tahun sesuai urutan
                tempTahun=m[i].tahun;
                m[i].tahun=m[j].tahun;
                m[j].tahun=tempTahun;

                //"swap" value Merk sesuai urutan
                strcpy(tempMerk, m[i].merk);
                strcpy(m[i].merk, m[j].merk);
                strcpy(m[j].merk, tempMerk);
            }
        }
    }
    printf("Data telah diurutkan berdasarkan tahun");
}

void getch()
{
    printf("\n\nTekan Enter untuk melanjutkan...");
    getchar();
}