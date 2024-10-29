#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TRANSAKSI 100

typedef char string[255];

// Prototypes for menu-related functions
void daftarNasabah(string *nama, string *alamat, long *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, bool *nasabahStatus, int *saldo, int *totalSetor, int *totalTarik);
void setorUang(int pin, bool *blokirStatus, int *totalSetor, int *saldo, int setor[]);
void tarikUang(int pin, bool *blokirStatus, int *saldo, int tarik[], int *totalTarik);
void lihatDataNasabah(string nama, string alamat, long ktp, int saldo);
void lihatRiwayatSetorTarik(int setor[], int tarik[], int totalSetor, int totalTarik);

// Prototypes for supporting functions
void initSetorTarik(int arr[]);
void pesanNoNasabah();
void pesanTerblokir();
void pesanEnter();
int cekPin(int actualPin, bool *blokirStatus);

int main() {
    string nama, alamat;
    long ktp = 0;
    int pin;
    int saldo = 0;
    int setor[MAX_TRANSAKSI], tarik[MAX_TRANSAKSI];
    int totalSetor = 0, totalTarik = 0;
    bool nasabahStatus = false, blokirStatus = false;
    int pilihan;

    do {
        system("clear");
        printf("\n\nSelamat Datang di ATM Bank ABC!");
        printf("\n1. Daftar Nasabah");
        printf("\n2. Setor Uang");
        printf("\n3. Tarik Uang");
        printf("\n4. Lihat Data Nasabah dan Saldo");
        printf("\n5. Lihat Riwayat Setor dan Tarik");
        printf("\n0. Keluar");
        printf("\nPilih Menu: ");
        scanf("%d", &pilihan);
        getchar(); // Clear newline from input buffer

        switch (pilihan) {
            case 1:
                if (!nasabahStatus) {
                    daftarNasabah(&nama, &alamat, &ktp, &pin, setor, tarik, &blokirStatus, &nasabahStatus, &saldo, &totalSetor, &totalTarik);
                } else {
                    printf("Nasabah sudah terdaftar!");
                }
                pesanEnter();
                break;
            case 2:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    setorUang(pin, &blokirStatus, &totalSetor, &saldo, setor);
                }
                pesanEnter();
                break;
            case 3:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    tarikUang(pin, &blokirStatus, &saldo, tarik, &totalTarik);
                }
                pesanEnter();
                break;
            case 4:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    lihatDataNasabah(nama, alamat, ktp, saldo);
                }
                pesanEnter();
                break;
            case 5:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    lihatRiwayatSetorTarik(setor, tarik, totalSetor, totalTarik);
                }
                pesanEnter();
                break;
            case 0:
                printf("\nTerima kasih telah menggunakan ATM ABC!\n");
                return 0;
            default:
                printf("\nMenu tidak ditemukan");
                pesanEnter();
                break;
        }
    } while (pilihan != 0);
}

void daftarNasabah(string *nama, string *alamat, long *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, bool *nasabahStatus, int *saldo, int *totalSetor, int *totalTarik) {
    printf("\n1. Daftar Nasabah\n");
    printf("\nMasukkan data nasabah \n");
    //getchar();
    printf("Nama    : ");
    fgets(*nama, sizeof(*nama), stdin);
    (*nama)[strcspn(*nama, "\n")] = '\0';
    printf("Alamat  : ");
    fgets(*alamat, sizeof(*alamat), stdin);
    (*alamat)[strcspn(*alamat, "\n")] = '\0';
    printf("No. KTP : ");
    scanf("%ld", ktp);
    printf("PIN     : ");
    scanf("%d", pin);

    *saldo = 0;
    *totalSetor = 0;
    *totalTarik = 0;
    *blokirStatus = false;
    *nasabahStatus = true;

    initSetorTarik(setor);
    initSetorTarik(tarik);

    printf("Nasabah %s berhasil didaftarkan dengan saldo %d", *nama, *saldo);
}

void setorUang(int pin, bool *blokirStatus, int *totalSetor, int *saldo, int setor[]) {
    printf("\n2. Setor Uang\n");
    int uangdisetor;

    if (*blokirStatus) {
        pesanTerblokir();
    } else if (cekPin(pin, blokirStatus)) {
        if (*totalSetor >= MAX_TRANSAKSI) {
            printf("Maksimal setoran tercapai!");
        } else {
            printf("Masukkan Jumlah uang yang akan disetor: ");
            scanf("%d", &uangdisetor);
            setor[*totalSetor] = uangdisetor;
            (*totalSetor)++;
            *saldo += uangdisetor;
            printf("Setoran berhasil! Saldo saat ini: %d", *saldo);
        }
    }
}

void tarikUang(int pin, bool *blokirStatus, int *saldo, int tarik[], int *totalTarik) {
    printf("\n3. Tarik Uang\n");
    int uangditarik;

    if (*blokirStatus) {
        pesanTerblokir();
    } else if (cekPin(pin, blokirStatus)) {
        if (*totalTarik >= MAX_TRANSAKSI) {
            printf("Maksimal tarikan tercapai!");
        } else {
            printf("Masukkan Jumlah uang yang akan ditarik: ");
            scanf("%d", &uangditarik);
            if (uangditarik > *saldo) {
                printf("Saldo Anda: %d tidak mencukupi, masukkan nominal yang lebih kecil\n", *saldo);
                tarikUang(pin, blokirStatus, saldo, tarik, totalTarik);
            } else {
                tarik[*totalTarik] = uangditarik;
                (*totalTarik)++;
                *saldo -= uangditarik;
                printf("\nPenarikan berhasil! Saldo saat ini: %d", *saldo);
            }
        }
    }
}

void lihatDataNasabah(string nama, string alamat, long ktp, int saldo) {
    printf("\n4. Lihat Data Nasabah dan Saldo\n");
    printf("\nNama    : %s", nama);
    printf("\nAlamat  : %s", alamat);
    printf("\nNo. KTP : %ld", ktp);
    printf("\nSaldo   : %d", saldo);
}

void lihatRiwayatSetorTarik(int setor[], int tarik[], int totalSetor, int totalTarik) {
    printf("\n5. Riwayat Setor dan Tarik\n");

    if (totalSetor == 0 && totalTarik == 0) {
        printf("\nBelum ada riwayat transaksi!\n");
        return;
    }

    printf("\nRiwayat Setoran:\n");
    for (int i = 0; i < totalSetor; i++) {
        printf("Setoran ke-%d: %d \n", i + 1, setor[i]);
    }

    printf("\nRiwayat Tarikan:\n");
    for (int i = 0; i < totalTarik; i++) {
        printf("Tarikan ke-%d: %d \n", i + 1, tarik[i]);
    }
}

void pesanNoNasabah() {
    printf("\nBelum ada nasabah terdaftar!\nSilahkan mendaftar dahulu.\n");
}

void pesanTerblokir() {
    printf("\nAkun Anda diblokir karena 3 kali kesalahan input PIN.\nSilahkan mendaftarkan ulang dengan keluar program terlebih dahulu.");
}

int cekPin(int actualPin, bool *blokirStatus) 
{
    int pinInput, percobaan = 3;

    while (percobaan > 0) {
        printf("\nMasukkan PIN: ");
        scanf("%d", &pinInput);
        if (pinInput == actualPin) {
            return 1;
        }
        percobaan--;
        printf("\nPIN salah! Kesempatan tersisa %d kali", percobaan);
    }
    *blokirStatus = true;  // Dereference blokirStatus to assign a bool value
    printf("\nAkun diblokir karena 3 kali kesalahan Pin!");
    return 0;
}

void initSetorTarik(int arr[])
{
    for(int i = 0; i < MAX_TRANSAKSI; i++) 
    {
        arr[i] = 0;
    }
}

void pesanEnter()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}