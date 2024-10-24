#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//konfigurasi tipe data string mempunyai panjang 255 karakter
typedef char string[255];

//deklarasi prosedur dan fungsi pada program
void prosedurDaftarNasabah(string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, int *saldo);
void prosedurSetorTarik(int arr[]);
void prosedurDisplayNasabah(string nama, string alamat, int ktp, int saldo);
void prosedurDisplaySetorTarik(int setor[], int tarik[]);
bool fungsiCheckPIN(bool *blokirStatus, int pin);
int fungsiSetorUang(bool *blokirStatus, int pin, int saldo, int setor[]);
int fungsiTarikUang(bool *blokirStatus, int pin, int saldo, int tarik[]);


//program utama
int main()
{
    printf("something\n");   
}

void prosedurDaftarNasabah(string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, int *saldo)
{
    
}

void prosedurSetorTarik(int arr[])
{
    
}

void prosedurDisplayNasabah(string nama, string alamat, int ktp, int saldo)
{

}

void prosedurDisplaySetorTarik(int setor[], int tarik[])
{

}

bool fungsiCheckPIN(bool *blokirStatus, int pin)
{
    return 0;
}

int fungsiSetorUang(bool *blokirStatus, int pin, int saldo, int setor[])
{
    return 0;
}

int fungsiTarikUang(bool *blokirStatus, int pin, int saldo, int tarik[])
{
    return 0;
}