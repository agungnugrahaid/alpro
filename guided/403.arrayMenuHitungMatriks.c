#include <stdio.h> 
#include <stdlib.h>
//#include <conio.h>

#define MAX 3 

void isiMatrix(int mat[MAX][MAX]); 
void showMatriks(int mat[MAX][MAX]); 
void sumMatriks(int mat_a[MAX][MAX], int mat_b[MAX][MAX], int total[MAX][MAX]); 
void getch();

int main() 
{
    int a[MAX][MAX], b[MAX][MAX], mat_total[MAX][MAX],pilihan;
    do
    { 
        system("clear"); 
        puts("Menu Hitung Matriks 3 x 3"); 
        puts("1. Isi Matriks A"); 
        puts("2. Isi Matriks B"); 
        puts("3. Tampilkan Isi Matriks A"); 
        puts("4. Tampilkan Isi Matriks B"); 
        puts("5. Jumlahkan Matriks"); 
        puts("0. Exit"); 
        printf("Pilih menu: ");
            scanf("%d",&pilihan); 
        switch(pilihan) 
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
                showMatriks(a); 
                getch(); 
                break; 
            case 4: 
                showMatriks(b); 
                getch(); 
                break; 
            case 5: 
                sumMatriks(a,b,mat_total); 
                showMatriks(mat_total); 
                getch(); 
                break; 
            case 0: 
                break; 
            default: 
                printf("Maaf menu tidak ditemukan!"); 
                getch(); 
            break; 
        } 
    }
    while(pilihan!=0); 
} 

void isiMatrix(int mat[MAX][MAX]) 
{ 
    int i, j; 
    for(i=0;i<MAX;i++)
    { 
        for(j=0;j<MAX;j++)
        { 
            printf("Input Elemen Baris %d Kolom %d:",i,j);
            scanf("%d",&mat[i][j]); 
        } 
    } 
}

void showMatriks(int mat[MAX][MAX]) 
{ 
    int i, j; 
    for(i=0;i<MAX;i++)
    { 
        for(j=0;j<MAX;j++)
        { 
            printf("%d\t",mat[i][j]); 
        } 
        printf("\n"); 
    } 
}

void sumMatriks(int mat_a[MAX][MAX], int mat_b[MAX][MAX], int total[MAX][MAX]) 
{ 
    int i, j; 
    for(i=0;i<MAX;i++)
    { 
        for(j=0;j<MAX;j++)
        {
            total[i][j]=mat_a[i][j]+mat_b[i][j]; 
        }
    } 
} 

void getch()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}