#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <conio.h>
#define MAX_Transaksi 100

typedef char string[255];

void daftarNasabah(string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokir, int *saldo, bool *terdaftar);
void initSetorTarik(int arr[]);
void displayNasabah(string nama, string alamat, int ktp, int saldo);
void displaySetorTarik(int setor[], int tarik[]);
bool checkPIN(int *attempts, int correctPIN, bool *blokir);
int setorUang(int pin, bool *blokir, int saldo, int setor[], bool terdaftar);
int tarikUang(int pin, bool *blokir, int saldo, int tarik[], bool terdaftar);
void getch();

int main() {
    string nama, alamat;
    int ktp, pin, saldo = 0;
    int setor[MAX_Transaksi], tarik[MAX_Transaksi];
    int pilihan, attempts = 0;
    bool blokir = false;
    bool terdaftar = false;
    initSetorTarik(setor);
    initSetorTarik(tarik);

    while(1) {
        printf("\n--- Menu ATM ---\n");
        printf("1. Daftar Nasabah\n");
        printf("2. Setor Uang\n");
        printf("3. Tarik Uang\n");
        printf("4. Lihat Data Nasabah dan Saldo\n");
        printf("5. Lihat Riwayat Setor dan Penarikan\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                daftarNasabah(&nama, &alamat, &ktp, &pin, setor, tarik, &blokir, &saldo, &terdaftar);
                attempts = 0; 
                break;
            case 2:
                if (terdaftar) {
                    saldo = setorUang(pin, &blokir, saldo, setor, terdaftar);
                } else {
                    printf("Anda belum mendaftar sebagai nasabah.\n");
                }
                getch();
                break;
            case 3:
                if (terdaftar) {
                    saldo = tarikUang(pin, &blokir, saldo, tarik, terdaftar);
                } else {
                    printf("Anda belum mendaftar sebagai nasabah.\n");
                }
                getch();
                break;
            case 4:
                if (terdaftar) {
                    displayNasabah(nama, alamat, ktp, saldo);
                } else {
                    printf("Data nasabah tidak ditemukan. Silakan daftar terlebih dahulu.\n");
                }
                getch();
                break;
            case 5:
                if (terdaftar) {
                    displaySetorTarik(setor, tarik);
                } else {
                    printf("Belum ada riwayat karena Anda belum mendaftar sebagai nasabah.\n");
                }
                getch();
                break;
            case 0:
                printf("Terima kasih telah menggunakan ATM.\n");
                return 0;
            default:
                printf("Pilihan menu tidak ditemukan.\n");
                getch();
        }
    }
    return 0;
}

void daftarNasabah(string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokir, int *saldo, bool *terdaftar) {
    printf("Data Nasabah Baru \n");
    printf("Nama: ");
    getchar();
    fgets(*nama, 255, stdin);
    (*nama)[strcspn(*nama, "\n")] = 0; 
    printf("Alamat: ");
    fgets(*alamat, 255, stdin);
    (*alamat)[strcspn(*alamat, "\n")] = 0; 
    printf("No KTP: ");
    scanf("%d", ktp);
    printf("PIN: ");
    scanf("%d", pin);
    *blokir = false; 
    *saldo = 0; 
    *terdaftar = true;  
    initSetorTarik(tarik);
    printf("Data nasabah baru berhasil disimpan!\n");
}

void initSetorTarik(int arr[]) {
    for(int i = 0; i < MAX_Transaksi; i++) {
        arr[i] = 0;
    }
}

void displayNasabah(string nama, string alamat, int ktp, int saldo) {
    printf("\n--- Data Nasabah ---\n");
    printf("Nama: %s\n", nama);
    printf("Alamat: %s\n", alamat);
    printf("No KTP: %d\n", ktp);
    printf("Saldo: %d\n", saldo);
}

void displaySetorTarik(int setor[], int tarik[]) 
{
    printf("\n--- Riwayat Transaksi ---\n");
    for(int i = 0; i < MAX_Transaksi; i++) {
        if(setor[i] != 0) {
            printf("Setoran: %d\n", setor[i]);
        }
    }
    for(int i = 0; i < MAX_Transaksi; i++) {
        if(tarik[i] != 0) {
            printf("Penarikan: %d\n", tarik[i]);
        }
    }
}

bool checkPIN(int *attempts, int correctPIN, bool *blokir) {
    int pinInput;
    int maxAttempts = 3;

    if (*blokir) {
        printf("Data nasabah diblokir!\n");
        return false;
    }

    while (*attempts < maxAttempts) {
        printf("Masukkan PIN: ");
        scanf("%d", &pinInput);
        if (pinInput == correctPIN) {
            *attempts = 0;
            return true;
        } else {
            (*attempts)++;
            int remainingAttempts = maxAttempts - *attempts;
            if (remainingAttempts > 0) {
                printf("PIN yang dimasukkan salah! %d kesempatan lagi!\n", remainingAttempts);
            } else {
                printf("PIN yang dimasukkan salah! 0 kesempatan lagi!\n");
                printf("Maaf, data nasabah akan diblokir!\n");
                *blokir = true;
                break;
            }
        }
    }
    return false;
}

int setorUang(int correctPIN, bool *blokir, int saldo, int setor[], bool terdaftar) {
    int jumlahSetor, i = 0;
    static int attempts = 0;
    
    if (!terdaftar) {
        printf("Data belum ditemukan. Anda belum mendaftar.\n");
        return saldo;
    }

    if (!checkPIN(&attempts, correctPIN, blokir)) {
        return saldo;
    }
    while(setor[i] != 0 && i < MAX_Transaksi) i++; 
    if(i < MAX_Transaksi) {
        printf("Input setoran: ");
        scanf("%d", &jumlahSetor);
        saldo += jumlahSetor;
        setor[i] = jumlahSetor;
        printf("Setoran berhasil.\n");
    } else {
        printf("Riwayat setor penuh.\n");
    }
    return saldo;
}

int tarikUang(int correctPIN, bool *blokir, int saldo, int tarik[], bool terdaftar) {
    int jumlahTarik, i = 0;
    static int attempts = 0;

    if (!terdaftar) {
        printf("Data belum ditemukan. Anda belum mendaftar.\n");
        return saldo;
    }

    if (!checkPIN(&attempts, correctPIN, blokir)) {
        return saldo;
    }
    while(tarik[i] != 0 && i < MAX_Transaksi) i++; 
    if(i < MAX_Transaksi) {
        printf("Tarik sebesar: ");
        scanf("%d", &jumlahTarik);
        if (jumlahTarik > saldo) {
            printf("Saldo tidak cukup.\n");
        } else {
            saldo -= jumlahTarik;
            tarik[i] = jumlahTarik;
            printf("Penarikan berhasil.\n");
        }
    } else {
        printf("Riwayat tarik penuh.\n");
    }
    return saldo;
}

void getch()
{
    printf("\n...");
    getchar();
}