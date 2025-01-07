#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;    // Array untuk elemen antrean
    int front;   // Indeks elemen terdepan
    int rear;    // Indeks elemen belakang
    int maxSize; // Ukuran maksimum antrean
} Queue;

// Inisialisasi antrean
void initQueue(Queue* Q, int size) {
    Q->arr = (int*)malloc(sizeof(int) * size);
    Q->front = 0;
    Q->rear = 0;
    Q->maxSize = size;
}

// Memeriksa apakah antrean kosong
int isQueueEmpty(Queue* Q) {
    return Q->front == Q->rear;
}

// Menambah elemen ke antrean
void enqueue(Queue* Q, int value) {
    if (Q->rear < Q->maxSize) {
        Q->arr[Q->rear++] = value;
    } else {
        printf("Antrean penuh\n");
    }
}

// Mengeluarkan elemen dari antrean
int dequeue(Queue* Q) {
    if (!isQueueEmpty(Q)) {
        return Q->arr[Q->front++];
    } else {
        printf("Antrean kosong\n");
        return 0; // Atau bisa menggunakan nilai lain sebagai indikasi error
    }
}

// Fungsi untuk menambahkan dan mengurangkan elemen dari dua antrean
int addSub(Queue* Q, Queue* R) {
    int counter = 5, t1, t2, temp, t = 0;

    while (counter > 0 && !isQueueEmpty(Q) && !isQueueEmpty(R)) {
        t1 = dequeue(Q);
        t2 = dequeue(R);
        printf("\ncounter ke %d before : t1 / t2 / temp/ t : %d / %d / %d / %d\n", counter, t1, t2, temp, t);
        if ((t1 + t2) % 2 == 0) {
            temp = t1 + t2;
            t += temp;
            printf("\ntemp = t1+t2 = %d + %d", t1, t2);
            printf("\nt = %d\n",t);
        } else {
            temp = t1 - t2;
            t -= temp;
            printf("\ntemp = t1-t2 = %d + %d", t1, t2);
            printf("\nt = %d\n",t);
        }
        //printf("\ncounter ke %d after  : t1 / t2 / temp/ t : %d / %d / %d / %d\n", counter, t1, t2, temp, t);
        counter--;
    }

    return t; // Kembalikan hasil akhir
}

// Contoh penggunaan
int main() {
    Queue Q, R;
    initQueue(&Q, 10);
    initQueue(&R, 10);

    // Mengisi antrean Q dengan elemen yang telah ditentukan
    enqueue(&Q, 16);
    enqueue(&Q, 18);
    enqueue(&Q, 10);

    // Mengisi antrean R dengan elemen yang telah ditentukan
    enqueue(&R, 12);
    enqueue(&R, 67);
    enqueue(&R, 32);

    // Menghitung hasil dengan fungsi addSub
    int result = addSub(&Q, &R);
    printf("Hasil akhir: %d\n", result);

    // Bebaskan memori
    free(Q.arr);
    free(R.arr);
    return 0;
}