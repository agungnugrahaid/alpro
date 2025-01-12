#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void isiMatrix(int mat[MAX][MAX]);
void showMatriks(int mat[MAX][MAX]);
void sumMatriksABC(int mat_a[MAX][MAX], int mat_b[MAX][MAX], int mat_c[MAX][MAX], int total[MAX][MAX]);
void subMatriks(int mat_a[MAX][MAX], int mat_b[MAX][MAX], int mat_c[MAX][MAX], int result[MAX][MAX]);
void transposeMatriks(int mat[MAX][MAX], int transposed[MAX][MAX]);
void getch();

int main() 
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int mat_total[MAX][MAX], mat_result[MAX][MAX], transposed[MAX][MAX];
    int pilihan;

    do
    { 
        system("clear");
        puts("Menu Operasi Matriks 3 x 3"); 
        puts("1. Isi Matriks A"); 
        puts("2. Isi Matriks B"); 
        puts("3. Isi Matriks C");
        puts("4. Tampilkan Isi Matriks A"); 
        puts("5. Tampilkan Isi Matriks B"); 
        puts("6. Tampilkan Isi Matriks C");
        puts("7. Penjumlahan Matriks A, B, dan C"); 
        puts("8. Pengurangan Matriks A, B, dan C");
        puts("9. Transpose Matriks");
        puts("0. Exit");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) 
        {
            case 1:  
                isiMatrix(a); 
                getch(); 
                break; 
            case 2:  
                isiMatrix(b); 
                getch(); 
                break; 
            case 3:
                isiMatrix(c);
                getch();
                break;
            case 4: 
                showMatriks(a); 
                getch(); 
                break; 
            case 5: 
                showMatriks(b); 
                getch(); 
                break; 
            case 6:
                showMatriks(c);
                getch();
                break;
            case 7: 
                sumMatriksABC(a, b, c, mat_total); 
                showMatriks(mat_total); 
                getch(); 
                break; 
            case 8:
                subMatriks(a, b, c, mat_result);
                showMatriks(mat_result);
                getch();
                break;
            case 9:
                printf("Pilih matriks yang akan ditranspose:\n");
                printf("1. Matriks A\n");
                printf("2. Matriks B\n");
                printf("3. Matriks C\n");
                printf("Pilihan: ");
                int transpose_choice;
                scanf("%d", &transpose_choice);
                if (transpose_choice == 1) {
                    transposeMatriks(a, transposed);
                    printf("Transpose Matriks A:\n");
                    showMatriks(transposed);
                } else if (transpose_choice == 2) {
                    transposeMatriks(b, transposed);
                    printf("Transpose Matriks B:\n");
                    showMatriks(transposed);
                } else if (transpose_choice == 3) {
                    transposeMatriks(c, transposed);
                    printf("Transpose Matriks C:\n");
                    showMatriks(transposed);
                } else {
                    printf("Pilihan tidak valid.\n");
                }
                getch();
                break;
            case 0: 
                break; 
            default: 
                printf("Maaf menu tidak ditemukan!");
                getch();
                break;
        } 
    } while (pilihan != 0); 

    return 0;
}

void isiMatrix(int mat[MAX][MAX]) 
{ 
    int i, j; 
    for (i = 0; i < MAX; i++) 
    { 
        for (j = 0; j < MAX; j++) 
        { 
            printf("Input Elemen Baris %d Kolom %d: ", i, j);
            scanf("%d", &mat[i][j]); 
        } 
    } 
}

void showMatriks(int mat[MAX][MAX]) 
{ 
    int i, j; 
    for (i = 0; i < MAX; i++) 
    { 
        for (j = 0; j < MAX; j++) 
        { 
            printf("%d\t", mat[i][j]); 
        } 
        printf("\n"); 
    } 
}

void sumMatriksABC(int mat_a[MAX][MAX], int mat_b[MAX][MAX], int mat_c[MAX][MAX], int total[MAX][MAX]) 
{ 
    int i, j; 
    for (i = 0; i < MAX; i++) 
    { 
        for (j = 0; j < MAX; j++) 
        {
            total[i][j] = mat_a[i][j] + mat_b[i][j] + mat_c[i][j]; 
        }
    } 
}

void subMatriks(int mat_a[MAX][MAX], int mat_b[MAX][MAX], int mat_c[MAX][MAX], int result[MAX][MAX]) 
{
    int i, j;
    for (i = 0; i < MAX; i++) 
    {
        for (j = 0; j < MAX; j++) 
        {
            result[i][j] = mat_a[i][j] - mat_b[i][j] - mat_c[i][j];
        }
    }
}

void transposeMatriks(int mat[MAX][MAX], int transposed[MAX][MAX])
{
    int i, j;
    for (i = 0; i < MAX; i++) 
    {
        for (j = 0; j < MAX; j++) 
        {
            transposed[j][i] = mat[i][j];
        }
    }
}

void getch()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}