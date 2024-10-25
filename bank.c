#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//deklarasi maksimum transaksi setor/tarik yang diperbolehkan
#define MAX_TRANSAKSI 100

//deklarasi tipe data string mempunyai panjang 255 karakter
typedef char string[255];

//deklarasi prosedur dan fungsi sesuai menu
void daftarNasabah();
void setorUang();
void tarikUang();
void lihatDataNasabah();
void lihatRiwayatSetorTarik();

//deklarasi prosedur dan fungsi pendukung
void pesanNoNasabah();
void pesanTerblokir();
void pesanEnter();
int cekPin();

//deklarasi variabel nasabah
string nama;
string alamat;
long ktp;
int pin;

//deklarasi variabel jumlah saldo dan banyaknya transaksi
int saldo = 0;
int setor[MAX_TRANSAKSI];
int tarik[MAX_TRANSAKSI];
int totalSetor = 0;
int totalTarik = 0;

//deklarasi variabel status nasabah dan status blokir
bool nasabahStatus = 0;
bool blokirStatus = 0;

//program utama
int main()
{
    int pilihan;
    do{
        system("clear");
        printf("\n\nSelamat Datang di ATM Bank ABC!");
        printf("\n1. Daftar Nasabah");
        printf("\n2. Setor Uang");
        printf("\n3. Tarik Uang");
        printf("\n4. Lihat Data Nasabah dan Saldo");
        printf("\n5. Lihat Riwayat Setor dan Tarik");
        printf("\n0. Keluar");
        printf("\nPilih Menu: ");
            scanf("%d", &pilihan);
        //menghilangkan karakter \n dari input scanf
        //while (getchar() != '\n');
        switch (pilihan)
        {
        case 1: //daftarNasabah
            if (nasabahStatus==0)
            {
                daftarNasabah();
                nasabahStatus = 1;
            }
            else 
            {
                printf("Nasabah sudah terdaftar!");
            }
            pesanEnter();
            break;
        case 2: //setorUang
            if (nasabahStatus==0)
            {
                pesanNoNasabah();
            }
            else
            {
                setorUang();
            }
            pesanEnter();
            break;
        case 3: //tarikUang
            if (nasabahStatus==0)
            {
                pesanNoNasabah();
            }
            else
            {
                tarikUang();
            }
            pesanEnter();
            break;
        case 4:
            if (nasabahStatus==0)
            {
                pesanNoNasabah();
            }
            else 
            {
                lihatDataNasabah();
            }
            pesanEnter();
            break;
        case 5:
            if (nasabahStatus==0)
            {
                pesanNoNasabah();
            }
            else
            {
                lihatRiwayatSetorTarik();
            }
            pesanEnter();
            break;
        case 0:
            printf("\nTerima kasih telah menggunakan ATM ABC!\n");
            return 0;
        default:
            printf("\nMenu tidak ditemukan");
            pesanEnter();
            break;
        }
    } 
    while (pilihan!=0);
}

//menu 1. Daftar Nasabah
void daftarNasabah()
{
    printf("\n1. Daftar Nasabah\n");
    printf("\nMasukkan data nasabah \n");
    //menghilangkan buffer \n agar tidak terbaca sebagai input
    while (getchar() != '\n');
    printf("Nama    : "); 
        //scanf("%s", nama);
        //replace scanf dengan fgets agar bisa membaca spasi
        fgets(nama, sizeof(nama),stdin);
        //menghilangkan karakter \n dari input fgets
        nama[strcspn(nama,"\n")] = '\0';
    printf("Alamat  : "); 
        //scanf("%s", alamat);
        //replace scanf dengan fgets agar bisa membaca spasi
        fgets(alamat, sizeof(alamat),stdin);
        //menghilangkan karakter \n dari input fgets
        alamat[strcspn(alamat,"\n")] = '\0';
    printf("No. KTP : "); scanf("%ld", &ktp);
    printf("PIN     : "); scanf("%d", &pin);

    saldo = 0;
    
    totalSetor = 0;
    totalTarik = 0;
    blokirStatus = 0;
    nasabahStatus = 1;

    printf("Nasabah %s berhasil didaftarkan dengan saldo %d", nama, saldo);
}

//menu 2. Setor Uang()
void setorUang()
{
    printf("\n2. Setor Uang\n");
    int uangdisetor;
    if (blokirStatus==1)
    {
        pesanTerblokir();
    }
    else
    if (cekPin()==1)
    {
        if (totalSetor >= MAX_TRANSAKSI)
        {
            printf("Maksimal setoran tercapai!");
        }
        else
        {
            printf("Masukkan Jumlah uang yang akan disetor: ");
                scanf("%d", &uangdisetor);
            setor[totalSetor++] = uangdisetor;
            saldo = saldo + uangdisetor;
            printf("Setoran berhasil! Saldo saat ini : %d", saldo);
        }
    }
}

//menu 3. Tarik Uang()
void tarikUang()
{
    printf("\n3. Tarik Uang\n");
    int uangditarik;
    if (blokirStatus==1)
    {
        pesanTerblokir();
    }
    else
    if (cekPin()==1)
    {
        if (totalTarik >= MAX_TRANSAKSI)
        {
            printf("Maksimal tarikan tercapai!");
            //return;
        }
        else
        {
            printf("Masukkan Jumlah uang yang akan ditarik: ");
                scanf("%d", &uangditarik);
            if (uangditarik > saldo)
            {
                printf("Saldo Anda : %d tidak mencukupi, masukkan nominal yang lebih kecil \n",saldo);
                tarikUang();
                //return;
                }
            else
            {
                tarik[totalTarik++] = uangditarik;
                saldo = saldo - uangditarik;
            printf("\nPenarikan berhasil! Saldo saat ini : %d", saldo);
            }
        }
    }
}

//menu 4. lihatDataNasabah()
void lihatDataNasabah()
{
    printf("\n4. Lihat Data Nasabah dan Saldo\n");
    printf("\nNama    : %s", nama);
    printf("\nAlamat  : %s", alamat);
    printf("\nNo. KTP : %ld", ktp);
    printf("\nSaldo   : %d\n", saldo);
}

void lihatRiwayatSetorTarik()
{
    printf("\n5. Riwayat Setor dan Tarik\n");
    if (totalSetor==0 && totalTarik==0)
    {
        printf("\nBelum ada riwayat transaksi!\n");
        return;
    }
    
    printf("\nRiwayat Setoran:");
    printf("\n================\n");
    for (int i = 0; i < totalSetor ; i++)
    {
        printf("Setoran ke-%d. %d \n", i+1, setor[i]);
    }

    printf("\nRiwayat Tarikan:");
    printf("\n================\n");
    for (int i = 0; i < totalTarik ; i++)
    {
        printf("Tarikan ke-%d. %d \n", i+1, tarik[i]);
    }
}

//fungsi dan prosedur pendukung
void pesanNoNasabah()
{
    printf("\nBelum ada nasabah terdaftar!\n");
    printf("\nSilahkan mendaftar dahulu: ");
    daftarNasabah();
}

void pesanTerblokir()
{
    printf("\nAkun and diblokir karena 3 kali kesalahan input Pin");
    printf("\nSilahkan mendaftarkan ulang dengan keluar program terlebih dahulu");
}

int cekPin()
{
    int pinInput, percobaan = 3;
    while (percobaan > 0)
    {
        printf("\nMasukkan PIN : ");
            scanf("%d", &pinInput);
        if (pinInput == pin)
        {
            return 1;
        }
        percobaan--;
        printf("\nPIN salah! Kesempatan tersisa %d kali", percobaan);
    }
    blokirStatus = 1;
    printf("\nAkun diblokir karena 3 kali kesalahan Pin!");
    return 0;
}

void pesanEnter()
{
    printf("\nTekan Enter untuk melanjutkan...");
    while (getchar() != '\n');
    getchar();
}