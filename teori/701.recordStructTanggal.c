#include <stdio.h>
#include <string.h>

typedef struct
{
    int jam;
    int menit;
    int detik;
}Waktu;

int main()
{
    //Memanggil tipe data bentukan
    Waktu w;
    printf("Masukkan Jam\t:");
        scanf("%d", &w.jam);
    printf("Masukkan Menit\t:");
        scanf("%d", &w.menit);
    printf("Masukkan Detik\t:");
        scanf("%d", &w.detik);
    printf("Waktu \t %d : %d : %d\n", w.jam, w.menit, w.detik);
    return 0;
}