#include <stdio.h>
#include <string.h>
#define MAX_QUEUE 10

// ADT Definitions
typedef struct {
    char licensePlate[15];
    int hourIn;
} Vehicle;

typedef struct {
    Vehicle vehicles[MAX_QUEUE];
    int front;
    int rear;
    int count;
} Queue;

// Queue Operations
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(Queue *q) {
    return q->count == MAX_QUEUE;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, Vehicle v) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX_QUEUE;
        q->vehicles[q->rear] = v;
        q->count++;
    } else {
        printf("Queue is full!\n");
    }
}

Vehicle dequeue(Queue *q) {
    Vehicle v = {"", -1};
    if (!isEmpty(q)) {
        v = q->vehicles[q->front];
        q->front = (q->front + 1) % MAX_QUEUE;
        q->count--;
    } else {
        printf("Queue is empty!\n");
    }
    return v;
}

int queueSize(Queue *q) {
    return q->count;
}

// Revenue Calculation
typedef struct {
    int carRevenue;
    int motorRevenue;
} Revenue;

// Main program
int main() {
    Queue carQueue, motorQueue;
    Revenue revenue = {0, 0};
    initQueue(&carQueue);
    initQueue(&motorQueue);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Kendaraan datang\n");
        printf("2. Kendaraan keluar\n");
        printf("3. Tampilkan Total Kendaraan\n");
        printf("4. Tampilkan Total Revenue\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char type;
            Vehicle v;

            printf("Jenis kendaraan (m untuk mobil, o untuk motor): ");
            scanf(" %c", &type);
            printf("Masukkan nomor polisi: ");
            scanf("%s", v.licensePlate);
            printf("Masukkan jam masuk: ");
            scanf("%d", &v.hourIn);

            if (type == 'm') {
                enqueue(&carQueue, v);
            } else if (type == 'o') {
                enqueue(&motorQueue, v);
            } else {
                printf("Jenis kendaraan tidak valid!\n");
            }
        } else if (choice == 2) {
            char type;
            int hourOut;

            printf("Jenis kendaraan yang keluar (m untuk mobil, o untuk motor): ");
            scanf(" %c", &type);
            printf("Masukkan jam keluar: ");
            scanf("%d", &hourOut);

            if (type == 'm') {
                if (!isEmpty(&carQueue)) {
                    Vehicle v = dequeue(&carQueue);
                    int duration = hourOut - v.hourIn;
                    int cost = duration * 3000;
                    revenue.carRevenue += cost;
                    printf("Mobil dengan nomor polisi %s dikenakan biaya %d\n", v.licensePlate, cost);
                }
            } else if (type == 'o') {
                if (!isEmpty(&motorQueue)) {
                    Vehicle v = dequeue(&motorQueue);
                    int duration = hourOut - v.hourIn;
                    int cost = duration * 2000;
                    revenue.motorRevenue += cost;
                    printf("Motor dengan nomor polisi %s dikenakan biaya %d\n", v.licensePlate, cost);
                }
            } else {
                printf("Jenis kendaraan tidak valid!\n");
            }
        } else if (choice == 3) {
            printf("Total kendaraan saat ini:\n");
            printf("Mobil: %d\n", queueSize(&carQueue));
            printf("Motor: %d\n", queueSize(&motorQueue));
        } else if (choice == 4) {
            printf("Total revenue saat ini:\n");
            printf("Mobil: %d\n", revenue.carRevenue);
            printf("Motor: %d\n", revenue.motorRevenue);
        } else if (choice == 5) {
            break;
        } else {
            printf("Opsi tidak valid!\n");
        }
    }

    return 0;
}
