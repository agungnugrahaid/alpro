#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
UTS Algoritma dan Struktur Data 
- Agung Nugraha Eka Saputra (241220055)
- Wagiyo Hadi Kristanto     (241210011)
*/

//deklarasi maksium transaksi setor-tarik yang diperbolehkan
#define MAX_TRANSAKSI 2

//deklarasi tipe data string dengan panjang karakter 255
typedef char string[255];

//deklarasi fungsi dan prosedur sesuai menu
void daftarNasabah(string *nama, string *alamat, long *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, bool *nasabahStatus, int *saldo, int *totalSetor, int *totalTarik);
void setorUang(int pin, bool *blokirStatus, int *totalSetor, int *saldo, int setor[]);
void tarikUang(int pin, bool *blokirStatus, int *saldo, int tarik[], int *totalTarik);
void lihatDataNasabah(string nama, string alamat, long ktp, int saldo);
void lihatRiwayatSetorTarik(int setor[], int tarik[], int totalSetor, int totalTarik, int saldo);

//deklarasi fungsi dan prosedur pendukung
void initSetorTarik(int arr[]);
void initDataNasabah();
void pesanNoNasabah();
void pesanTerblokir();
void getch();
int cekPin(int actualPin, bool *blokirStatus);

int main() {
    string nama, alamat;
    long ktp = 0;
    int pin;
    int saldo = 0;
    int setor[MAX_TRANSAKSI], tarik[MAX_TRANSAKSI];
    int totalSetor = 0, totalTarik = 0;
    bool nasabahStatus = false, blokirStatus = false;
    char confirmDel;
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
        getchar(); 

        switch (pilihan) {
            case 1:
                if (!nasabahStatus) {
                    daftarNasabah(&nama, &alamat, &ktp, &pin, setor, tarik, &blokirStatus, &nasabahStatus, &saldo, &totalSetor, &totalTarik);
                } else {
                    printf("\nNasabah sudah terdaftar!");
                    printf("\nApakah anda akan menghapusnya? [Y/y]");
                        scanf("%c",&confirmDel);
                    getchar();
                    if (confirmDel == 'y' || confirmDel == 'Y')
                    {
                        nasabahStatus=false;
                        blokirStatus=false;
                        daftarNasabah(&nama, &alamat, &ktp, &pin, setor, tarik, &blokirStatus, &nasabahStatus, &saldo, &totalSetor, &totalTarik);
                    }
                }
                getch();
                break;
            case 2:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    setorUang(pin, &blokirStatus, &totalSetor, &saldo, setor);
                }
                getch();
                break;
            case 3:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    tarikUang(pin, &blokirStatus, &saldo, tarik, &totalTarik);
                }
                getch();
                break;
            case 4:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    lihatDataNasabah(nama, alamat, ktp, saldo);
                }
                getch();
                break;
            case 5:
                if (!nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    lihatRiwayatSetorTarik(setor, tarik, totalSetor, totalTarik, saldo);
                }
                getch();
                break;
            case 0:
                printf("\nTerima kasih telah menggunakan ATM ABC!\n");
                return 0;
            default:
                printf("\nMenu tidak ditemukan");
                getch();
                break;
        }
    } while (pilihan != 0);
}

void daftarNasabah(string *nama, string *alamat, long *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, bool *nasabahStatus, int *saldo, int *totalSetor, int *totalTarik) {
    printf("\n1. Daftar Nasabah\n");
    printf("\nMasukkan data nasabah \n");
    printf("Nama    : ");
        //menggunakan fgets agar menerima input spasi
        fgets(*nama, sizeof(*nama), stdin);
        //menghilangkan \n (enter) dari value 
        (*nama)[strcspn(*nama, "\n")] = '\0';
    printf("Alamat  : ");
        fgets(*alamat, sizeof(*alamat), stdin);
        (*alamat)[strcspn(*alamat, "\n")] = '\0';
    printf("No. KTP : ");
        scanf("%ld", ktp);
    printf("PIN     : ");
        scanf("%d", pin);
    getchar();

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
            getchar();
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
            getchar();
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

void lihatRiwayatSetorTarik(int setor[], int tarik[], int totalSetor, int totalTarik, int saldo) {
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
    printf("\nSaldo Akhir : %d",saldo);
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
        getchar();
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

void getch()
{
    printf("\n...");
    getchar();
}