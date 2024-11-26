#include <stdio.h>
#include <string.h>
#define MAX 5

//deklarasi tipe data string
typedef char string[255];

//deklrasai ADT
typedef struct{
    string judul[255];
    string prodi;
    float ipk;
}Data_Buku;

//deklarasi Array of ADT, enkapsulasi "Data_Buku" pada array "Buku"
typedef struct{
    Data_Buku Data[5]; 
}Buku;

int main()
{
    //memanggil 
    Buku b;


    return 0;
}

//Constructor/Initialize
void init(Buku *b)
{
    int i;
    for (i=0; i<MAX; i++)
    {
        strcpy((*b).data[i].judul,"\0");
        strcpy((*b).data[i].judul,"\0");
    }
}

//Mutator
void deleteBuku()
{

}
//Display
void displayBuku()
{
    //menggunakan perulangan untuk menampilkan data buku
}

//Mutator, prosedur melakukan pengurutan index dari array
void sortingByYearAsc(Buku *b)
{
    int i,j;
    Data_Buku temp;
    for (i)
}