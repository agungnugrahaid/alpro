#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
int cekPin();
void cekBlokir();

//deklarasi variabel nasabah
string nama;
string alamat;
string ktp;
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
        printf("\n\nSelamat Datang di ATM Bank ABC!");
        printf("\n1. Daftar Nasabah");
        printf("\n2. Setor Uang");
        printf("\n3. Tarik Uang");
        printf("\n4. Lihat Data Nasabah dan Saldo");
        printf("\n5. Lihat Riwayat Setor dan Tarik");
        printf("\n0. Keluar");
        printf("\nPilih Menu: ");
            scanf("%d", &pilihan);
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
            break;
        case 0:
            printf("\nTerima kasih telah menggunakan ATM ABC!\n");
            return 0;
        default:
            printf("\nMenu tidak ditemukan");
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
    printf("Nama    : "); scanf("%s", nama);
    printf("Alamat  : "); scanf("%s", alamat);
    printf("No. KTP : "); scanf("%s", ktp);
    printf("PIN     : "); scanf("%d", &pin);

    saldo = 0;
    
    totalSetor = 0;
    totalTarik = 0;
    blokirStatus = 0;
    nasabahStatus = 1;

    printf("Nasabah %s berhasil didaftarkan dengan saldo %d\n", nama, saldo);
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
            printf("Maksimal setoran tercapai!\n");
            //return;
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
            printf("Maksimal setoran tercapai!\n");
            return;
        }
        else
        {
            printf("Masukkan Jumlah uang yang akan ditarik: ");
                scanf("%d", &uangditarik);
            if (uangditarik > saldo)
                {
                    printf("Saldo tidak mencukupi, masukkan nominal yang lebih kecil \n");
                    tarikUang();
                    return;
                }
            tarik[totalTarik++] = uangditarik;
            saldo = saldo - uangditarik;
            printf("Penarikan berhasil! Saldo saat ini : %d", saldo);
        }
    }
}

//menu 4. lihatDataNasabah()
void lihatDataNasabah()
{
    printf("\n4. Lihat Data Nasabah dan Saldo\n");
    printf("\nNama    : %s", nama);
    printf("\nAlamat  : %s", alamat);
    printf("\nNo. KTP : %s", ktp);
    printf("\nSaldo   : %d", saldo);
}

void lihatRiwayatSetorTarik()
{
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
    printf("Akun and diblokir karena 3 kali kesalahan input Pin\n");
    printf("Silahkan mendaftarkan ulang dengan keluar program terlebih dahulu\n");
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
        printf("PIN salah! Kesempatan tersisa %d kali\n", percobaan);
    }
    blokirStatus = 1;
    printf("Akun diblokir karena 3 kali kesalahan Pin!\n");
    return 0;
}