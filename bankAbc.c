#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_TRANSAKSI 100

//konfigurasi tipe data string mempunyai panjang 255 karakter
typedef char string[255];



//deklarasi prosedur dan fungsi pada program
//prosedur menampilkan w

void prosedurDaftarNasabah();
void prosedurSetorTarik();
void prosedurDisplayNasabah();
void prosedurDisplaySetorTarik();
bool fungsiCheckPIN(bool *blokirStatus, int pin);
int fungsiSetorUang(bool *blokirStatus, int pin, int saldo, int setor[]);
int fungsiTarikUang(bool *blokirStatus, int pin, int saldo, int tarik[]);

//prosedur tambahan
void noDataNasabah();

//deklarasi variabel
string *nama, *alamat;
int *ktp, *pin, setor[MAX_TRANSAKSI], tarik[MAX_TRANSAKSI], saldo;
bool *blokirStatus = 0, *nasabahStatus = 0;


//program utama
int main()
{
    int pilihan;
    do
    {
        system("clear");
        puts("\nSelamat Datang di ATM Bank ABC!");
        puts("[1] Daftar Nasabah");
        puts("[2] Setor Uang");
        puts("[3] Tarik Uang");
        puts("[4] Lihat Data Nasabah dan Saldo");
        puts("[5] Lihat Riwayat Setor dan Tarik");
        puts("[0] Keluar");
        printf("Pilih Menu: ");
            scanf("%d",&pilihan);
        switch (pilihan)
        {
        case 1:
            if(!nasabahStatus)
            {
                prosedurDaftarNasabah();
                nasabahStatus;
            }
            else noDataNasabah();
            break;
        
        default:
            printf("Maaf menu tidak ditemukan!");
            getchar();
            break;
        case 0:
            printf("Terima kasih telah menggunakan ATM Bank ABC!\n");
            return 0;
        }
    } while (pilihan!=0);
    return 0;
}

void noDataNasabah()
{
    printf("Belum ada Nasabah Terdaftar!\n");
}
void prosedurDaftarNasabah()
{
    //string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokirStatus, int *saldo
    printf("Masukkan nama nasabah: ");
        scanf("%s", &nama);
    printf("Masukkan PIN: ")
        scanf("d", &nasabah.pin)

    nasabah.saldo = 0;
    nasabah.blokir = 0;
    nasabah.totalSetoran = 0;
    nasabah.totalPenarikan =0;

    printf("Nasabah %s berhasil didaftarkan dengan saldo %.2f \n", nasabah.nama, nasabah.saldo);
}

void prosedurSetorTarik(int arr[])
{
    
}

void prosedurDisplayNasabah()
{
    //string nama, string alamat, int ktp, int saldo
}

void prosedurDisplaySetorTarik()
{
    //int setor[], int tarik[]
}

bool fungsiCheckPIN()
{
    //bool *blokirStatus, int pin;
    return 0;
}

int fungsiSetorUang()
{
    //bool *blokirStatus, int pin, int saldo, int setor[]
    return 0;
}

int fungsiTarikUang()
{
    //bool *blokirStatus, int pin, int saldo, int tarik[]
    return 0;
}

int github(int dummy)
{
    /*
    git add .
    git commit -m "Initial commit with hello world in C"
    git push origin main
    */
   return 0;
}