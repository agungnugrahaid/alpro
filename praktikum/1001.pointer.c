#include <stdio.h>

// Fungsi untuk menghitung total nilai dari sebuah array of integer
int hitungTotal(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += *(arr + i);    // Menggunakan pointer untuk mengakses elemen array
    }
    return total;
}

int main() {
    int array[] = {10, 20, 30, 40, 50}; // Contoh array
    int size = sizeof(array) / sizeof(array[0]); // Menghitung jumlah elemen array
    int total = hitungTotal(array, size); // Memanggil fungsi hitungTotal

    printf("Total array: %d\n", total);
    return 0;
}