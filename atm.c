#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//#include <conio.h>

//deklarasi maksimum transaksi setor/tarik yang diperbolehkan
#define MAX_Transaksi 100

//deklarasi tipe data string mempunyai panjang 255 karakter
typedef char string[255];

//deklarasi prosedur dan fungsi sesuai menu
void daftarNasabah(string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokir, int *saldo);
int setorUang(int pin, bool *blokir, int saldo, int setor[]);
int tarikUang(int pin, bool *blokir, int saldo, int tarik[]);
void displayNasabah(string nama, string alamat, int ktp, int saldo);
void displaySetorTarik(int setor[], int tarik[]);

//deklarasi prosedur pendukung
void initSetorTarik(int arr[]);
bool checkPIN(int *attempts, int correctPIN, bool *blokir);
void getch();

int main() 
{
    //deklrasi variabel
    string nama, alamat;
    int ktp = 0, pin, saldo = 0;
    int setor[MAX_Transaksi], tarik[MAX_Transaksi];
    int pilihan, attempts = 0;
    bool blokir = false;

    //mengosongkan nilai array setor dan tarik
    initSetorTarik(setor);
    initSetorTarik(tarik);

    do
    {
        printf("\n--- Menu ATM ---\n");
        printf("1. Daftar Nasabah\n");
        printf("2. Setor Uang\n");
        printf("3. Tarik Uang\n");
        printf("4. Lihat Data Nasabah dan Saldo\n");
        printf("5. Lihat Riwayat Setor dan Penarikan\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                daftarNasabah(&nama, &alamat, &ktp, &pin, setor, tarik, &blokir, &saldo);
                attempts = 0; 
                break;
            case 2:
                saldo = setorUang(pin, &blokir, saldo, setor);
                break;
            case 3:
                saldo = tarikUang(pin, &blokir, saldo, tarik);
                break;
            case 4:
                displayNasabah(nama, alamat, ktp, saldo);
                break;
            case 5:
                displaySetorTarik(setor, tarik);
                break;
            case 0:
                printf("Terima kasih telah menggunakan ATM.\n");
                return 0;
            default:
                printf("Pilihan menu tidak ditemukan.\n");
        }
    } while(pilihan !=0);
    getch();
}

void daftarNasabah(string *nama, string *alamat, int *ktp, int *pin, int setor[], int tarik[], bool *blokir, int *saldo) {
    printf("Data Nasabah Baru \n");
	printf("Nama  : ");
    //Menghilangkan buffer \n agar tidak terbaca sebagai input langsung
    getchar(); 
        //menggunakan fgets agar bisa membaca karakter spasi
        fgets(*nama, 255, stdin);
        //menghilangkan karakter \n dari input fgets
        (*nama)[strcspn(*nama, "\n")] = 0; 
    
    printf("Alamat: ");
        fgets(*alamat, 255, stdin);
        (*alamat)[strcspn(*alamat, "\n")] = 0; 
    printf("No KTP: ");
        scanf("%d", ktp);
    printf("PIN   : ");
        scanf("%d", pin);

    *blokir = false; 
    *saldo = 0; 

    initSetorTarik(setor);
    initSetorTarik(tarik);

    printf("Data nasabah baru berhasil disimpan!\n");
    getch();
}

void initSetorTarik(int arr[]) {
    for(int i = 0; i < MAX_Transaksi; i++) {
        arr[i] = 0;
    }
}

void displayNasabah(string nama, string alamat, int ktp, int saldo) {
    printf("\n--- Data Nasabah ---\n");
    printf("Nama  : %s\n", nama);
    printf("Alamat: %s\n", alamat);
    printf("No KTP: %d\n", ktp);
    printf("Saldo : %d\n", saldo);
    getch();
}

void displaySetorTarik(int setor[], int tarik[]) 
{
    
    for(int i = 0; i < MAX_Transaksi; i++) {
        if(setor[i] != 0) {
            printf("Setoran ke-%d: %d\n", i, setor[i]);
        }
    }
    for(int i = 0; i < MAX_Transaksi; i++) {
        if(tarik[i] != 0) {
            printf("Penarikan ke%d: %d\n", i, tarik[i]);
        }
    }
    getch();
}

bool checkPIN(int *attempts, int correctPIN, bool *blokir) 
{
    int pinInput;
    int maxAttempts = 3;

    if (*blokir) 
    {
        printf("Data nasabah diblokir!\n");
        return false;
    }
    while (*attempts < maxAttempts) 
    {
        printf("Masukkan PIN: ");
        scanf("%d", &pinInput);

        if (pinInput == correctPIN) 
        {
            *attempts = 0;
            return true;
        } 
        else 
        {
            (*attempts)++;
            int remainingAttempts = maxAttempts - *attempts;
            if (remainingAttempts > 0) 
            {
                printf("PIN yang dimasukkan salah! %d kesempatan lagi!\n", remainingAttempts);
            } 
            else 
            {
        	printf("PIN yang dimasukkan salah! 0 kesempatan lagi!\n");
            printf("Maaf data nasabah akan diblokir!\n");
            *blokir = true;
            break;
        	}
   		 }   		 
	}
	getch();
}

int setorUang(int correctPIN, bool *blokir, int saldo, int setor[]) {
    int jumlahSetor, i = 0;
    static int attempts = 0;

    if (!checkPIN(&attempts, correctPIN, blokir)) 
    {
        return saldo;
    }

    while(setor[i] != 0 && i < MAX_Transaksi) i++; 

    if(i < MAX_Transaksi) 
    {
        printf("Input setoran: ");
            scanf("%d", &jumlahSetor);
        saldo += jumlahSetor;
        setor[i] = jumlahSetor;
        printf("Setoran berhasil.\n");
    } 
    else 
    {
        printf("Riwayat setor penuh.\n");
    }
    return saldo;
}

int tarikUang(int correctPIN, bool *blokir, int saldo, int tarik[]) {
    int jumlahTarik, i = 0;
    static int attempts = 0;

    if (!checkPIN(&attempts, correctPIN, blokir)) 
    {
        return saldo;
    }

    while(tarik[i] != 0 && i < MAX_Transaksi) i++; 

    if(i < MAX_Transaksi) 
    {
        printf("Tarik sebesar: ");scanf("%d", &jumlahTarik);

        if (jumlahTarik > saldo) 
        {
            printf("Saldo tidak cukup.\n");
        } 
        else 
        {
            saldo -= jumlahTarik;
            tarik[i] = jumlahTarik;
            printf("Penarikan berhasil.\n");
        }
    } 
    else 
    {
        printf("Riwayat tarik penuh.\n");
    }
    return saldo;
}

void getch()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}