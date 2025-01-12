#include <stdio.h>
#include <string.h>

typedef struct {
    char Nama[25];
    char NIM[10];
    int UTS;
    int UAS;
    int Tugas;
} Mahasiswa;

typedef Mahasiswa* addressMhs;

void inputMahasiswa(addressMhs pmhs, int *count) {
    if (*count < 10) {
        printf("Masukkan Nama: ");
        scanf(" %[^\n]", pmhs->Nama);
        printf("Masukkan NIM: ");
        scanf("%s", pmhs->NIM);
        printf("Masukkan Nilai UTS: ");
        scanf("%d", &pmhs->UTS);
        printf("Masukkan Nilai UAS: ");
        scanf("%d", &pmhs->UAS);
        printf("Masukkan Nilai Tugas: ");
        scanf("%d", &pmhs->Tugas);
        (*count)++;
    } else {
        printf("Data mahasiswa penuh!\n");
    }
}

void tampilkanMahasiswa(Mahasiswa *mhs, int count) {
    printf("Daftar Mahasiswa:\n");
    for (int i = 0; i < count; i++) {
        addressMhs pmhs = &mhs[i];
        printf("Mahasiswa %d:\n", i + 1);
        printf("Nama: %s\n", pmhs->Nama);
        printf("NIM: %s\n", pmhs->NIM);
        printf("UTS: %d\n", pmhs->UTS);
        printf("UAS: %d\n", pmhs->UAS);
        printf("Tugas: %d\n", pmhs->Tugas);
    }
}

void hapusMahasiswaByNIM(Mahasiswa *mhs, int *count, const char *nim) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(mhs[i].NIM, nim) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            (*count)--;
            printf("Data mahasiswa dengan NIM %s berhasil dihapus.\n", nim);
            break;
        }
    }
    if (!found) {
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
    }
}

int main() {
    Mahasiswa mhs[10];
    addressMhs pmhs;
    int count = 0, pilihan;
    char nim[10];

    do {
        printf("\nMenu:\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Hapus Data Mahasiswa by NIM\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                pmhs = &mhs[count];
                inputMahasiswa(pmhs, &count);
                break;
            case 2:
                tampilkanMahasiswa(mhs, count);
                break;
            case 3:
                printf("Masukkan NIM yang akan dihapus: ");
                scanf("%s", nim);
                hapusMahasiswaByNIM(mhs, &count, nim);
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
