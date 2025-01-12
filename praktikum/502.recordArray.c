#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3

typedef char string[255];

// Mendefinisikan struct Mobil dengan atribut tahun, merk, dan ukuran tangki
typedef struct {
    int tahun;          // Tahun produksi mobil
    string merk;        // Merk mobil
    float ukuranTangki; // Ukuran tangki dalam liter
} Mobil;

// Deklarasi fungsi/prosedur
void init(Mobil m[]);
void entryData(Mobil m[]);
void show(Mobil m[]);
void sortDescendingByYear(Mobil m[]);
void getch(); // Fungsi untuk menahan layar sebelum lanjut

int main() {
    int pilihan;
    Mobil m[MAX]; // Array untuk menyimpan data mobil

    do {
        system("clear"); // Membersihkan layar (gunakan 'cls' untuk Windows)
        puts("Menu Data Mobil (Penerapan Record/Struct, Array, dan Sorting)");
        puts("1. Inisialisasi Data");
        puts("2. Masukkan Data Mobil");
        puts("3. Tampilkan Data Mobil");
        puts("4. Urutkan Data Mobil Berdasarkan Tahun");
        puts("0. Exit");
        printf("Pilih menu: ");
        scanf("%d", &pilihan); // Input pilihan menu
        getchar();

        // Proses berdasarkan pilihan pengguna
        switch (pilihan) {
            case 1:
                init(m); // Inisialisasi data
                getch();
                break;
            case 2:
                entryData(m); // Input data mobil
                getch();
                break;
            case 3:
                show(m); // Menampilkan data mobil
                getch();
                break;
            case 4:
                sortDescendingByYear(m); // Mengurutkan data berdasarkan tahun
                printf("\nData telah diurutkan berdasarkan tahun secara menurun.");
                getch();
                break;
            case 0:
                break; // Keluar dari program
            default:
                printf("Maaf menu tidak ditemukan!");
                getch();
                break;
        }
    } while (pilihan != 0); // Program berjalan selama pilihan bukan 0
}

// Fungsi untuk inisialisasi data
void init(Mobil m[]) {
    for (int i = 0; i < MAX; i++) {
        m[i].tahun = 0;             // Mengosongkan data tahun
        strcpy(m[i].merk, "\0");    // Mengosongkan data merk
        m[i].ukuranTangki = 0.0;    // Mengosongkan data ukuran tangki
    }
}

// Fungsi untuk memasukkan data mobil
void entryData(Mobil m[]) {
    for (int i = 0; i < MAX; i++) {
        printf("\nData Mobil Ke-%d\n", i + 1);
        printf("Input Tahun\t\t: ");
        scanf("%d", &m[i].tahun); // Input tahun mobil
        getchar();

        printf("Input Merk\t\t: ");
        fgets(m[i].merk, 255, stdin); // Input merk mobil
        m[i].merk[strcspn(m[i].merk, "\n")] = '\0'; // Menghapus karakter newline

        printf("Input Ukuran Tangki (liter)\t: ");
        scanf("%f", &m[i].ukuranTangki); // Input ukuran tangki
        getchar();
    }
}

// Fungsi untuk menampilkan data mobil
void show(Mobil m[]) {
    for (int i = 0; i < MAX; i++) {
        printf("\nData Mobil Ke-%d", i + 1);
        printf("\nTahun\t\t: %d", m[i].tahun);
        printf("\nMerk\t\t: %s", m[i].merk);
        printf("\nUkuran Tangki\t: %.2f liter\n", m[i].ukuranTangki);
    }
}

// Fungsi untuk mengurutkan data berdasarkan tahun (dari besar ke kecil)
void sortDescendingByYear(Mobil m[]) {
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if (m[i].tahun < m[j].tahun) {
                // Menukar data antar elemen array
                Mobil temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }
}

// Fungsi untuk menahan layar sebelum lanjut
void getch() {
    printf("\n\nTekan Enter untuk melanjutkan...");
    getchar();
}