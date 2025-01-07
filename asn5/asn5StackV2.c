#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;    // Array untuk elemen stack
    int top;     // Indeks elemen teratas
    int maxSize; // Ukuran maksimum stack
} Stack;

// Inisialisasi stack
void initStack(Stack* S, int size) {
    S->arr = (int*)malloc(sizeof(int) * size);
    S->top = -1;
    S->maxSize = size;
}

// Memeriksa apakah stack kosong
int isEmpty(Stack* S) {
    return S->top == -1;
}

// Menambahkan elemen ke stack
void push(Stack* S, int value) {
    if (S->top < S->maxSize - 1) {
        S->arr[++(S->top)] = value;
    } else {
        printf("Stack penuh\n");
    }
}

// Menghapus dan mengembalikan elemen teratas dari stack
int pop(Stack* S) {
    if (!isEmpty(S)) {
        return S->arr[(S->top)--];
    } else {
        printf("Stack kosong\n");
        return 0; // Atau bisa menggunakan nilai lain sebagai indikasi error
    }
}

// Fungsi untuk menghitung elemen genap dan ganjil dalam stack
int countEl(Stack* S) {
    int temp, t = 0;
    while (!isEmpty(S)) {  // Periksa apakah stack tidak kosong
        temp = pop(S);     // Ambil elemen teratas
        if (temp % 2 == 0) {
            t += temp;       // Tambahkan jika genap
        } else {
            t -= temp;       // Kurangi jika ganjil
        }
    }
    return t; // Kembalikan hasil akhir
}

// Contoh penggunaan
int main() {
    Stack myStack;
    initStack(&myStack, 5); // Inisialisasi stack dengan ukuran 5

    // Mengisi stack dengan elemen yang telah ditentukan
    push(&myStack, 4); // Top
    push(&myStack, 5);
    push(&myStack, 2);
    push(&myStack, 11);
    push(&myStack, 3); // Bottom

    int result = countEl(&myStack);
    printf("Hasil akhir: %d\n", result);

    free(myStack.arr); // Bebaskan memori
    return 0;
}