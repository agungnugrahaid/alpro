#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//deklarasi maksimum transaksi setor/tarik yang diperbolehkan
#define MAX_TRANSAKSI 100

//deklrasai tipe data string mempunyai panjang 255 karakter
typedef char string[255];

//deklarasi tipe data "Nasabah" menggunakan struct/record
typedef struct {
    string nama;
    string alamat;
    long ktp;
    int pin;
    int saldo;
    int totalSetor;
    int totalTarik;
    bool blokirStatus;
    bool nasabahStatus;
    int setor[MAX_TRANSAKSI];
    int tarik[MAX_TRANSAKSI];
} Nasabah;

//deklarasi fungsi dan prosedur dalam program sesuai menu
void daftarNasabah(Nasabah *nasabah);
void setorUang(Nasabah *nasabah);
void tarikUang(Nasabah *nasabah);
void lihatDataNasabah(Nasabah nasabah);
void lihatRiwayatSetorTarik(Nasabah nasabah);

//deklarasi fungsi dan prosedur pendukung
void initSetorTarik(int arr[]);
void pesanNoNasabah();
void pesanTerblokir();
void pesanEnter();
int cekPin(int actualPin, bool *blokirStatus);

int main() 
{
    //inisialisasi/mengosongkan data Nasabah 
    Nasabah nasabah = {0}; 
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
        //menghilangkan \n dari buffer input
        getchar();

        switch (pilihan) {
            case 1:
                if (!nasabah.nasabahStatus) 
                {
                    daftarNasabah(&nasabah);
                } 
                else 
                {
                    printf("Nasabah sudah terdaftar!");
                }
                pesanEnter();
                break;
            case 2:
                if (!nasabah.nasabahStatus) 
                {
                    pesanNoNasabah();
                } 
                else 
                {
                    setorUang(&nasabah);
                }
                pesanEnter();
                break;
            case 3:
                if (!nasabah.nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    tarikUang(&nasabah);
                }
                pesanEnter();
                break;
            case 4:
                if (!nasabah.nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    lihatDataNasabah(nasabah);
                }
                pesanEnter();
                break;
            case 5:
                if (!nasabah.nasabahStatus) {
                    pesanNoNasabah();
                } else {
                    lihatRiwayatSetorTarik(nasabah);
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

void daftarNasabah(Nasabah *nasabah) {
    printf("\n1. Daftar Nasabah\n");
    printf("\nMasukkan data nasabah \n");

    printf("Nama    : ");
    fgets(nasabah.nama, sizeof(nasabah.nama), stdin);
    nasabah.nama[strcspn(nasabah.nama, "\n")] = '\0';
    printf("Alamat  : ");
    fgets(nasabah->alamat, sizeof(nasabah->alamat), stdin);
    nasabah->alamat[strcspn(nasabah->alamat, "\n")] = '\0';
    printf("No. KTP : ");
    scanf("%ld", &nasabah->ktp);
    printf("PIN     : ");
    scanf("%d", &nasabah->pin);

    nasabah->saldo = 0;
    nasabah->totalSetor = 0;
    nasabah->totalTarik = 0;
    nasabah->blokirStatus = false;
    nasabah->nasabahStatus = true;

    initSetorTarik(nasabah->setor);
    initSetorTarik(nasabah->tarik);

    printf("Nasabah %s berhasil didaftarkan dengan saldo %d", nasabah->nama, nasabah->saldo);
}

void setorUang(Nasabah *nasabah) {
    printf("\n2. Setor Uang\n");
    int uangdisetor;

    if (nasabah->blokirStatus) {
        pesanTerblokir();
    } else if (cekPin(nasabah->pin, &nasabah->blokirStatus)) {
        if (nasabah->totalSetor >= MAX_TRANSAKSI) {
            printf("Maksimal setoran tercapai!");
        } else {
            printf("Masukkan Jumlah uang yang akan disetor: ");
            scanf("%d", &uangdisetor);
            nasabah->setor[nasabah->totalSetor] = uangdisetor;
            nasabah->totalSetor++;
            nasabah->saldo += uangdisetor;
            printf("Setoran berhasil! Saldo saat ini: %d", nasabah->saldo);
        }
    }
}

void tarikUang(Nasabah *nasabah) {
    printf("\n3. Tarik Uang\n");
    int uangditarik;

    if (nasabah->blokirStatus) {
        pesanTerblokir();
    } else if (cekPin(nasabah->pin, &nasabah->blokirStatus)) {
        if (nasabah->totalTarik >= MAX_TRANSAKSI) {
            printf("Maksimal tarikan tercapai!");
        } else {
            printf("Masukkan Jumlah uang yang akan ditarik: ");
            scanf("%d", &uangditarik);
            if (uangditarik > nasabah->saldo) {
                printf("Saldo Anda: %d tidak mencukupi, masukkan nominal yang lebih kecil\n", nasabah->saldo);
                tarikUang(nasabah);
            } else {
                nasabah->tarik[nasabah->totalTarik] = uangditarik;
                nasabah->totalTarik++;
                nasabah->saldo -= uangditarik;
                printf("\nPenarikan berhasil! Saldo saat ini: %d", nasabah->saldo);
            }
        }
    }
}

void lihatDataNasabah(Nasabah nasabah) {
    printf("\n4. Lihat Data Nasabah dan Saldo\n");
    printf("\nNama    : %s", nasabah.nama);
    printf("\nAlamat  : %s", nasabah.alamat);
    printf("\nNo. KTP : %ld", nasabah.ktp);
    printf("\nSaldo   : %d", nasabah.saldo);
}

void lihatRiwayatSetorTarik(Nasabah nasabah) {
    printf("\n5. Riwayat Setor dan Tarik\n");

    if (nasabah.totalSetor == 0 && nasabah.totalTarik == 0) {
        printf("\nBelum ada riwayat transaksi!\n");
        return;
    }

    printf("\nRiwayat Setoran:\n");
    for (int i = 0; i < nasabah.totalSetor; i++) {
        printf("Setoran ke-%d: %d \n", i + 1, nasabah.setor[i]);
    }

    printf("\nRiwayat Tarikan:\n");
    for (int i = 0; i < nasabah.totalTarik; i++) {
        printf("Tarikan ke-%d: %d \n", i + 1, nasabah.tarik[i]);
    }
}

void pesanNoNasabah() {
    printf("\nBelum ada nasabah terdaftar!\nSilahkan mendaftar dahulu.\n");
}

void pesanTerblokir() {
    printf("\nAkun Anda diblokir karena 3 kali kesalahan input PIN.\nSilahkan mendaftarkan ulang dengan keluar program terlebih dahulu.");
}

int cekPin(int actualPin, bool *blokirStatus) {
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

void initSetorTarik(int arr[]) {
    for (int i = 0; i < MAX_TRANSAKSI; i++) {
        arr[i] = 0;
    }
}

void pesanEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
}
