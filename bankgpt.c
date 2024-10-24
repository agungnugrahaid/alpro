#include <stdio.h>
#include <string.h>

#define MAX_TRANSAKSI 100

// Variabel global untuk menyimpan data nasabah
char nama[50];
int pin;
float saldo = 0;
int blokir = 0;
float setoran[MAX_TRANSAKSI];
float penarikan[MAX_TRANSAKSI];
int totalSetoran = 0;
int totalPenarikan = 0;

void daftarNasabah() {
    printf("Masukkan nama nasabah: ");
    scanf("%s", nama);
    printf("Masukkan PIN (4 digit): ");
    scanf("%d", &pin);
    saldo = 0;
    blokir = 0;
    totalSetoran = 0;
    totalPenarikan = 0;
    printf("Nasabah %s berhasil didaftarkan dengan saldo %.2f\n", nama, saldo);
}

int verifikasiPIN() {
    int pinInput, percobaan = 3;
    while (percobaan > 0) {
        printf("Masukkan PIN: ");
        scanf("%d", &pinInput);
        if (pinInput == pin) {
            return 1;
        }
        percobaan--;
        printf("PIN salah! Kesempatan tersisa: %d\n", percobaan);
    }
    blokir = 1;
    printf("Akun diblokir karena 3 kali kesalahan PIN.\n");
    return 0;
}

void setorUang() {
    if (blokir) {
        printf("Akun diblokir. Silakan daftar ulang untuk membuka blokir.\n");
        return;
    }
    if (verifikasiPIN()) {
        if (totalSetoran >= MAX_TRANSAKSI) {
            printf("Maksimal setoran tercapai.\n");
            return;
        }
        float jumlah;
        printf("Masukkan jumlah uang yang akan disetor: ");
        scanf("%f", &jumlah);
        saldo += jumlah;
        setoran[totalSetoran++] = jumlah;
        printf("Setoran berhasil! Saldo saat ini: %.2f\n", saldo);
    }
}

void tarikUang() {
    if (blokir) {
        printf("Akun diblokir. Silakan daftar ulang untuk membuka blokir.\n");
        return;
    }
    if (verifikasiPIN()) {
        if (totalPenarikan >= MAX_TRANSAKSI) {
            printf("Maksimal penarikan tercapai.\n");
            return;
        }
        float jumlah;
        printf("Masukkan jumlah uang yang akan ditarik: ");
        scanf("%f", &jumlah);
        if (jumlah > saldo) {
            printf("Saldo tidak mencukupi.\n");
            return;
        }
        saldo -= jumlah;
        penarikan[totalPenarikan++] = jumlah;
        printf("Penarikan berhasil! Saldo saat ini: %.2f\n", saldo);
    }
}

void lihatDataNasabah() {
    printf("Nama Nasabah: %s\n", nama);
    printf("Saldo Saat Ini: %.2f\n", saldo);
    if (blokir) {
        printf("Status Akun: Diblokir\n");
    } else {
        printf("Status Akun: Aktif\n");
    }
}

void lihatRiwayat() {
    printf("Riwayat Setoran:\n");
    for (int i = 0; i < totalSetoran; i++) {
        printf("%d. %.2f\n", i + 1, setoran[i]);
    }

    printf("Riwayat Penarikan:\n");
    for (int i = 0; i < totalPenarikan; i++) {
        printf("%d. %.2f\n", i + 1, penarikan[i]);
    }
}

int main() {
    int pilihan;
    int nasabahTerdaftar = 0;

    while (1) {
        printf("\nATM Menu:\n");
        printf("1. Daftar Nasabah\n");
        printf("2. Setor Uang\n");
        printf("3. Tarik Uang\n");
        printf("4. Lihat Data Nasabah dan Saldo\n");
        printf("5. Lihat Riwayat Setor dan Tarik\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (!nasabahTerdaftar) {
                    daftarNasabah();
                    nasabahTerdaftar = 1;
                } else {
                    printf("Nasabah sudah terdaftar.\n");
                }
                break;
            case 2:
                if (nasabahTerdaftar) {
                    setorUang();
                } else {
                    printf("Belum ada nasabah terdaftar.\n");
                }
                break;
            case 3:
                if (nasabahTerdaftar) {
                    tarikUang();
                } else {
                    printf("Belum ada nasabah terdaftar.\n");
                }
                break;
            case 4:
                if (nasabahTerdaftar) {
                    lihatDataNasabah();
                } else {
                    printf("Belum ada nasabah terdaftar.\n");
                }
                break;
            case 5:
                if (nasabahTerdaftar) {
                    lihatRiwayat();
                } else {
                    printf("Belum ada nasabah terdaftar.\n");
                }
                break;
            case 6:
                printf("Terima kasih telah menggunakan ATM.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
