#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MOBIL_RATE 3000
#define MOTOR_RATE 2000

// Definisi Struct
typedef struct {
    char nomor_polisi[15];
    int jam_masuk;
    int menit_masuk;
    int detik_masuk;
} Kendaraan;

typedef struct {
    Kendaraan data[MAX];
    int head;
    int tail;
} Queue;

// Fungsi Queue
void initQueue(Queue *q) {
    q->head = -1;
    q->tail = -1;
}

int isFull(Queue *q) {
    return (q->tail + 1) % MAX == q->head;
}

int isEmpty(Queue *q) {
    return q->head == -1;
}

void enqueue(Queue *q, Kendaraan kendaraan) {
    if (isFull(q)) {
        printf("Queue penuh! Tidak dapat menambahkan kendaraan.\n");
        return;
    }

    if (isEmpty(q)) {
        q->head = 0;
    }
    q->tail = (q->tail + 1) % MAX;
    q->data[q->tail] = kendaraan;
}

Kendaraan dequeue(Queue *q) {
    Kendaraan keluar = {"", 0, 0, 0};
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada kendaraan untuk dikeluarkan.\n");
        return keluar;
    }

    keluar = q->data[q->head];
    if (q->head == q->tail) {
        q->head = q->tail = -1;
    } else {
        q->head = (q->head + 1) % MAX;
    }

    return keluar;
}

int size(Queue *q) {
    if (isEmpty(q)) return 0;
    if (q->tail >= q->head) return q->tail - q->head + 1;
    return MAX - q->head + q->tail + 1;
}

int convertToSeconds(int jam, int menit, int detik) {
    return jam * 3600 + menit * 60 + detik;
}

void kendaraanDatang(Queue *queueMobil, Queue *queueMotor) {
    int tipe;
    Kendaraan kendaraan;

    printf("Masukkan tipe kendaraan (1 untuk Mobil, 2 untuk Motor): ");
    scanf("%d", &tipe);

    printf("Masukkan nomor polisi: ");
    scanf("%s", kendaraan.nomor_polisi);

    printf("Masukkan jam masuk: ");
    scanf("%d", &kendaraan.jam_masuk);
    printf("Masukkan menit masuk: ");
    scanf("%d", &kendaraan.menit_masuk);
    printf("Masukkan detik masuk: ");
    scanf("%d", &kendaraan.detik_masuk);

    if (tipe == 1) {
        enqueue(queueMobil, kendaraan);
    } else if (tipe == 2) {
        enqueue(queueMotor, kendaraan);
    } else {
        printf("Tipe kendaraan tidak valid!\n");
    }
}

void kendaraanKeluar(Queue *queueMobil, Queue *queueMotor) {
    int tipe;
    int jam_keluar, menit_keluar, detik_keluar;
    Kendaraan kendaraan;

    printf("Masukkan tipe kendaraan yang keluar (1 untuk Mobil, 2 untuk Motor): ");
    scanf("%d", &tipe);

    printf("Masukkan jam keluar: ");
    scanf("%d", &jam_keluar);
    printf("Masukkan menit keluar: ");
    scanf("%d", &menit_keluar);
    printf("Masukkan detik keluar: ");
    scanf("%d", &detik_keluar);

    int keluarInSeconds = convertToSeconds(jam_keluar, menit_keluar, detik_keluar);

    if (tipe == 1) {
        kendaraan = dequeue(queueMobil);
        if (strcmp(kendaraan.nomor_polisi, "") != 0) {
            int masukInSeconds = convertToSeconds(kendaraan.jam_masuk, kendaraan.menit_masuk, kendaraan.detik_masuk);
            int durasi = keluarInSeconds - masukInSeconds;
            if (durasi < 0) durasi += 24 * 3600; // Mengatasi perhitungan jika melewati tengah malam
            printf("Nomor Polisi: %s\n", kendaraan.nomor_polisi);
            printf("Biaya parkir: %d\n", (durasi / 3600) * MOBIL_RATE);
        }
    } else if (tipe == 2) {
        kendaraan = dequeue(queueMotor);
        if (strcmp(kendaraan.nomor_polisi, "") != 0) {
            int masukInSeconds = convertToSeconds(kendaraan.jam_masuk, kendaraan.menit_masuk, kendaraan.detik_masuk);
            int durasi = keluarInSeconds - masukInSeconds;
            if (durasi < 0) durasi += 24 * 3600; // Mengatasi perhitungan jika melewati tengah malam
            printf("Nomor Polisi: %s\n", kendaraan.nomor_polisi);
            printf("Biaya parkir: %d\n", (durasi / 3600) * MOTOR_RATE);
        }
    } else {
        printf("Tipe kendaraan tidak valid!\n");
    }
}

void tampilkanPendapatanParkir(Queue *queueMobil, Queue *queueMotor) {
    int totalPendapatanMobil = 0, totalPendapatanMotor = 0;
    int jam_sekarang, menit_sekarang, detik_sekarang;

    printf("Masukkan jam sekarang: ");
    scanf("%d", &jam_sekarang);
    printf("Masukkan menit sekarang: ");
    scanf("%d", &menit_sekarang);
    printf("Masukkan detik sekarang: ");
    scanf("%d", &detik_sekarang);

    int waktuSekarang = convertToSeconds(jam_sekarang, menit_sekarang, detik_sekarang);

    for (int i = queueMobil->head; i != (queueMobil->tail + 1) % MAX; i = (i + 1) % MAX) {
        int waktuMasuk = convertToSeconds(queueMobil->data[i].jam_masuk, queueMobil->data[i].menit_masuk, queueMobil->data[i].detik_masuk);
        int durasi = waktuSekarang - waktuMasuk;
        if (durasi < 0) durasi += 24 * 3600; // Mengatasi perhitungan jika melewati tengah malam
        totalPendapatanMobil += (durasi / 3600) * MOBIL_RATE;
    }

    for (int i = queueMotor->head; i != (queueMotor->tail + 1) % MAX; i = (i + 1) % MAX) {
        int waktuMasuk = convertToSeconds(queueMotor->data[i].jam_masuk, queueMotor->data[i].menit_masuk, queueMotor->data[i].detik_masuk);
        int durasi = waktuSekarang - waktuMasuk;
        if (durasi < 0) durasi += 24 * 3600; // Mengatasi perhitungan jika melewati tengah malam
        totalPendapatanMotor += (durasi / 3600) * MOTOR_RATE;
    }

    printf("Pendapatan total dari mobil: %d\n", totalPendapatanMobil);
    printf("Pendapatan total dari motor: %d\n", totalPendapatanMotor);
}

void tampilkanTotalKendaraan(Queue *queueMobil, Queue *queueMotor) {
    printf("Total kendaraan mobil: %d\n", size(queueMobil));
    printf("Total kendaraan motor: %d\n", size(queueMotor));
}

int main() {
    Queue queueMobil, queueMotor;
    initQueue(&queueMobil);
    initQueue(&queueMotor);

    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Kendaraan Datang\n");
        printf("2. Kendaraan Keluar\n");
        printf("3. Tampilkan Total Kendaraan\n");
        printf("4. Tampilkan Pendapatan Parkir\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                kendaraanDatang(&queueMobil, &queueMotor);
                break;
            case 2:
                kendaraanKeluar(&queueMobil, &queueMotor);
                break;
            case 3:
                tampilkanTotalKendaraan(&queueMobil, &queueMotor);
                break;
            case 4:
                tampilkanPendapatanParkir(&queueMobil, &queueMotor);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
