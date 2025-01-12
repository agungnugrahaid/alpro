#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char tanggalPeriksa[15];
    char idRiwayat[10];
    float tinggiBadan;
    float beratBadan;
    int umur;
    char tekananDarah[10];
    char keluhan[100];
    char catatanDokter[100];
    char resep[100];
} Riwayat;

typedef struct {
    char idPasien[15];
    char nama[50];
    char jenisKelamin[10];
    char tanggalLahir[15];
    char golonganDarah[5];
    char alamat[100];
    char nomorKTP[20];
    char nomorBPJS[20];
    char nomorTelepon[15];
    char tanggalDaftar[15];
    char dokterPribadi[50];
    Riwayat riwayat;
} Pasien;

void insertDataPasien(Pasien *p) {
    printf("Masukkan ID Pasien: ");
    scanf("%s", p->idPasien);
    printf("Masukkan Nama: ");
    getchar(); // clear buffer
    fgets(p->nama, sizeof(p->nama), stdin);
    strtok(p->nama, "\n"); // remove newline
    printf("Masukkan Jenis Kelamin: ");
    scanf("%s", p->jenisKelamin);
    printf("Masukkan Tanggal Lahir (dd-mm-yyyy): ");
    scanf("%s", p->tanggalLahir);
    printf("Masukkan Golongan Darah: ");
    scanf("%s", p->golonganDarah);
    printf("Masukkan Alamat: ");
    getchar();
    fgets(p->alamat, sizeof(p->alamat), stdin);
    strtok(p->alamat, "\n");
    printf("Masukkan Nomor KTP: ");
    scanf("%s", p->nomorKTP);
    printf("Masukkan Nomor BPJS/Askes: ");
    scanf("%s", p->nomorBPJS);
    printf("Masukkan Nomor Telepon: ");
    scanf("%s", p->nomorTelepon);
    printf("Masukkan Tanggal Daftar (dd-mm-yyyy): ");
    scanf("%s", p->tanggalDaftar);
    printf("Masukkan Nama Dokter Pribadi: ");
    getchar();
    fgets(p->dokterPribadi, sizeof(p->dokterPribadi), stdin);
    strtok(p->dokterPribadi, "\n");
}

void updateDataPasien(Pasien *p) {
    printf("\nUpdate Data Pasien\n");
    printf("ID Pasien: %s\n", p->idPasien);
    printf("Masukkan Nama Baru: ");
    getchar();
    fgets(p->nama, sizeof(p->nama), stdin);
    strtok(p->nama, "\n");
    printf("Masukkan Jenis Kelamin Baru: ");
    scanf("%s", p->jenisKelamin);
    printf("Masukkan Tanggal Lahir Baru: ");
    scanf("%s", p->tanggalLahir);
    printf("Masukkan Alamat Baru: ");
    getchar();
    fgets(p->alamat, sizeof(p->alamat), stdin);
    strtok(p->alamat, "\n");
}

void deleteDataPasien(Pasien *p) {
    memset(p, 0, sizeof(Pasien));
    printf("Data pasien telah dihapus.\n");
}

void insertRiwayatPasien(Pasien *p) {
    printf("Masukkan Tanggal Periksa: ");
    scanf("%s", p->riwayat.tanggalPeriksa);
    printf("Masukkan ID Riwayat: ");
    scanf("%s", p->riwayat.idRiwayat);
    printf("Masukkan Tinggi Badan: ");
    scanf("%f", &p->riwayat.tinggiBadan);
    printf("Masukkan Berat Badan: ");
    scanf("%f", &p->riwayat.beratBadan);
    printf("Masukkan Umur: ");
    scanf("%d", &p->riwayat.umur);
    printf("Masukkan Tekanan Darah: ");
    scanf("%s", p->riwayat.tekananDarah);
    printf("Masukkan Keluhan: ");
    getchar();
    fgets(p->riwayat.keluhan, sizeof(p->riwayat.keluhan), stdin);
    strtok(p->riwayat.keluhan, "\n");
    printf("Masukkan Catatan Dokter: ");
    fgets(p->riwayat.catatanDokter, sizeof(p->riwayat.catatanDokter), stdin);
    strtok(p->riwayat.catatanDokter, "\n");
    printf("Masukkan Resep: ");
    fgets(p->riwayat.resep, sizeof(p->riwayat.resep), stdin);
    strtok(p->riwayat.resep, "\n");
}

void tampilkanDataPasien(Pasien p) {
    printf("\nKartu Kesehatan Pasien\n");
    printf("Nomor ID Pasien: %s\n", p.idPasien);
    printf("Nama: %s\n", p.nama);
    printf("Jenis Kelamin: %s\n", p.jenisKelamin);
    printf("Tanggal Lahir: %s\n", p.tanggalLahir);
    printf("Golongan Darah: %s\n", p.golonganDarah);
    printf("Alamat: %s\n", p.alamat);
    printf("Nomor KTP: %s\n", p.nomorKTP);
    printf("Nomor BPJS: %s\n", p.nomorBPJS);
    printf("Nomor Telepon: %s\n", p.nomorTelepon);
    printf("Tanggal Daftar: %s\n", p.tanggalDaftar);
    printf("Dokter Pribadi: %s\n", p.dokterPribadi);
    printf("\nRiwayat Pasien\n");
    printf("Tanggal Periksa: %s\n", p.riwayat.tanggalPeriksa);
    printf("ID Riwayat: %s\n", p.riwayat.idRiwayat);
    printf("Tinggi Badan: %.1f cm\n", p.riwayat.tinggiBadan);
    printf("Berat Badan: %.1f kg\n", p.riwayat.beratBadan);
    printf("Umur: %d\n", p.riwayat.umur);
    printf("Tekanan Darah: %s\n", p.riwayat.tekananDarah);
    printf("Keluhan: %s\n", p.riwayat.keluhan);
    printf("Catatan Dokter: %s\n", p.riwayat.catatanDokter);
    printf("Resep: %s\n", p.riwayat.resep);
}

int main() {
    Pasien pasien;
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Data Pasien\n");
        printf("2. Update Data Pasien\n");
        printf("3. Delete Data Pasien\n");
        printf("4. Insert Riwayat Pasien\n");
        printf("5. Tampilkan Data dan Riwayat Pasien\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                insertDataPasien(&pasien);
                break;
            case 2:
                updateDataPasien(&pasien);
                break;
            case 3:
                deleteDataPasien(&pasien);
                break;
            case 4:
                insertRiwayatPasien(&pasien);
                break;
            case 5:
                tampilkanDataPasien(pasien);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}