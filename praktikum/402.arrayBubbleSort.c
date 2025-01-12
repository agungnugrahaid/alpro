#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

void isiArray(int arr[]);
void showArray(int arr[]);
void bubbleSortArray(int arr[]);
void getch();

int main()
{
    int array[MAX], pilihan;
    do
    {
        system("clear");
        puts("Menu Hitung Persegi");
        puts("1. Isi Array");
        puts("2. Tampilkan Isi Array");
        puts("3. Urutkan Ascending Array");
        puts("0. Exit");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Consume newline after scanf to avoid issues in getch()
        
        switch(pilihan)
        {
            case 1:
                isiArray(array);
                getch();
                break;
            case 2: 
                showArray(array);
                getch();
                break;
            case 3: 
                bubbleSortArray(array);
                printf("Array has been sorted in ascending order.\n");
                getch();
                break;
            case 0: 
                break;
            default: 
                printf("Maaf, menu tidak ditemukan!\n");
                getch();
                break;
        }
    } while(pilihan != 0);
}

/*
void bubbleSortArray(int arr[])
{
    int i, j, temp;
    for(i = 0; i < MAX - 1; i++) // Update loop boundaries for bubble sort
    {
        for(j = 0; j < MAX - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
*/

void bubbleSortArray(int arr[])
{
    int i, j, temp;
    for(i = 0; i < MAX; i++)
    {
        for(j = i; j < MAX; j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void showArray(int arr[])
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void isiArray(int arr[])
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        printf("Masukkan Nilai Indeks ke %d: ", i);
        scanf("%d", &arr[i]);
        getchar(); // Consume newline after each scanf
    }
}

void getch()
{
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
}
