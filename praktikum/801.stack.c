#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Inisialisasi stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Mengecek apakah stack kosong
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Mengecek apakah stack penuh
bool isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Push elemen ke stack
bool push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh!\n");
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

// Pop elemen dari stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Mengecek apakah semua bilangan genap
bool allEven(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        if (stack->data[i] % 2 != 0)
            return false;
    }
    return true;
}

// Mengecek apakah semua bilangan ganjil
bool allOdd(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        if (stack->data[i] % 2 == 0)
            return false;
    }
    return true;
}

// Operasi menghitung bilangan
void calculate(Stack *stack) {
    if (isEmpty(stack) || stack->top == 0) {
        printf("Operasi tidak dapat dilakukan karena stack kosong atau hanya ada satu elemen.\n");
        return;
    }

    int result;
    if (stack->top == 1) {
        // Operasi pembagian
        int b = pop(stack);
        int a = pop(stack);
        result = a / b;
        push(stack, result);
        printf("Hasil pembagian: %d\n", result);
    } else if (isFull(stack)) {
        if (allEven(stack)) {
            // Operasi perkalian
            result = 1;
            while (!isEmpty(stack)) {
                result *= pop(stack);
            }
            push(stack, result);
            printf("Hasil perkalian: %d\n", result);
        } else if (allOdd(stack)) {
            // Operasi penjumlahan
            result = 0;
            while (!isEmpty(stack)) {
                result += pop(stack);
            }
            push(stack, result);
            printf("Hasil penjumlahan: %d\n", result);
        } else {
            printf("Tidak ada operasi yang dilakukan.\n");
        }
    } else {
        // Operasi pengurangan
        result = pop(stack);
        while (!isEmpty(stack)) {
            result -= pop(stack);
        }
        push(stack, result);
        printf("Hasil pengurangan: %d\n", result);
    }
}

// Menampilkan stack
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
        return;
    }
    printf("Isi stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d \n", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Push Bilangan\n");
        printf("2. Pop Bilangan\n");
        printf("3. Hitung Bilangan\n");
        printf("4. Tampilkan Stack\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan bilangan: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Bilangan yang di-pop: %d\n", value);
                }
                break;
            case 3:
                calculate(&stack);
                break;
            case 4:
                displayStack(&stack);
                break;
            case 0:
                printf("Keluar program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}
