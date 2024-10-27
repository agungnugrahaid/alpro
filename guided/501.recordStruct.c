#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char string[255];

typedef struct
{
    int tahun;
    string merk;
} mobil;

void init(mobil *m);
void entryData(mobil *m);
void show(mobil m);
void pause();

int main()
{
    int pilihan;
    mobil m;
    do
    {
        system("clear");
        puts("Menu Record Mobil dan Tahun");
        puts("1. Inisialisasi Data");
        puts("2. Masukkan Data Mobil");
        puts("3. Tampilkan Data Mobil");
        puts("0. Exit");
        printf("Pilih menu: ");
            scanf("%d",&pilihan);
        switch(pilihan)
        {
            case 1: 
                init(&m);
                //pause();
                break;
            case 2: 
                entryData(&m);
                //pause();
                break;
            case 3: 
                show(m);
                pause();
                break;
            case 0: 
                break;
            default: 
                printf("\nMaaf menu tidak ditemukan!");
                pause();
                break;
        }
    }
    while(pilihan!=0);
}

void init(mobil *m)
{
    (*m).tahun=0;
    strcpy((*m).merk,"-");
}

void entryData(mobil *m)
{
    printf("Input Tahun: ");
        scanf("%d",&(*m).tahun);
        getchar();
    printf("Input Merk: ");
        fgets(((*m).merk), sizeof((*m).merk),stdin);
    ((*m).merk)[strcspn(((*m).merk),"\n")] = '\0';
}

void show(mobil m)
{
    puts("Data Mobil");
    printf("Tahun: %d\n",m.tahun);
    printf("Merk: %s\n",m.merk);
}

void pause()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}