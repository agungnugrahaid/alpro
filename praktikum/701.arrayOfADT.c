#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_P 5
#define MAX_R 3

typedef char string[255];
typedef struct{
	int tgl;
	int bln;
	int thn;
}Date;

typedef struct{
	float tinggi;
	float berat;
	int umur;
	int systole;
	int diastole;	
}Medcheckup;

typedef struct{
	Medcheckup checkup;
	int id;
	Date tgl_periksa;
	string keluhan;
	string catatan;
	string resep;
}Riwayat;

typedef struct{
	string goldar;
	int id;
	int no_ktp;
	string nama;
	string alamat;
	string dokter;
	char jk;
	Date tgl_lahir;
	int no_telp;
	int no_bpjs;
	Date tgl_daftar;
	Riwayat data_riwayat[MAX_R]; 
}Data_Pasien;

typedef struct
{
	Data_Pasien data[MAX_P];
}Pasien;

void getch()
{
    printf("\n...");
    getchar();
}

void updateDataPasienByID(Pasien *p, int id)
{
	int i;
	for(i=0;i<MAX_P;i++){
		if((*p).data[i].id==id){
			puts("Update Data Pasien");
			printf("Input Nama: ");scanf("%s",(*p).data[i].nama);
			printf("Input No KTP: ");scanf("%d",&(*p).data[i].no_ktp);
			printf("Input No BPJS/Askes: ");scanf("%d",&(*p).data[i].no_bpjs);
			printf("Input No Telp: ");scanf("%d",&(*p).data[i].no_telp);
			printf("Input Golongan Darah (A/B/AB/O)): ");scanf("%s",(*p).data[i].goldar);
			fflush(stdin);
			printf("Input JK (L/P)): ");scanf("%c",&(*p).data[i].jk);
			printf("Input Tgl Lahir: ");scanf("%d",&(*p).data[i].tgl_lahir.tgl);
			printf("Input Bln Lahir: ");scanf("%d",&(*p).data[i].tgl_lahir.bln);
			printf("Input Thn Lahir: ");scanf("%d",&(*p).data[i].tgl_lahir.thn);
			printf("Input Tgl Daftar: ");scanf("%d",&(*p).data[i].tgl_daftar.tgl);
			printf("Input Bln Daftar: ");scanf("%d",&(*p).data[i].tgl_daftar.bln);
			printf("Input Thn Daftar: ");scanf("%d",&(*p).data[i].tgl_daftar.thn);
			puts("Data Pasien Telah diupdate!");
			break;
		}else{
			puts("Tidak ditemukan pasien dengan ID tersebut!");
		}
	}
}

void createDataPasien(Pasien *p)
{
	int i;
	for(i=0;i<MAX_P;i++){
		if((*p).data[i].id==0){
			printf("Input ID: ");scanf("%d",&(*p).data[i].id);
			printf("Input Nama: ");scanf("%s",&(*p).data[i].nama);
			printf("Input Alamat: ");scanf("%s",&(*p).data[i].alamat);
			printf("Input Dokter: ");scanf("%s",&(*p).data[i].dokter);
			printf("Input No KTP: ");scanf("%d",&(*p).data[i].no_ktp);
			printf("Input No BPJS/Askes: ");scanf("%d",&(*p).data[i].no_bpjs);
			printf("Input No Telp: ");scanf("%d",&(*p).data[i].no_telp);
			printf("Input Golongan Darah (A/B/AB/O)): ");scanf("%s",&(*p).data[i].goldar);
			printf("Input JK (L/P)): ");scanf("%c",&(*p).data[i].jk);
			printf("Input Tgl Lahir: ");scanf("%d",&(*p).data[i].tgl_lahir.tgl);
			printf("Input Bln Lahir: ");scanf("%d",&(*p).data[i].tgl_lahir.bln);
			printf("Input Thn Lahir: ");scanf("%d",&(*p).data[i].tgl_lahir.thn);
			printf("Input Tgl Daftar: ");scanf("%d",&(*p).data[i].tgl_daftar.tgl);
			printf("Input Bln Daftar: ");scanf("%d",&(*p).data[i].tgl_daftar.bln);
			printf("Input Thn Daftar: ");scanf("%d",&(*p).data[i].tgl_daftar.thn);
			puts("Data Pasien Disimpan!");
			break;
		}
	}
}

void init(Pasien *p)
{
	int i, j;
	for(i=0;i<MAX_P;i++){
		(*p).data[i].id=0;
		strcpy((*p).data[i].nama,"-");
		strcpy((*p).data[i].alamat,"-");
		strcpy((*p).data[i].dokter,"-");
		strcpy((*p).data[i].goldar,"-");
		(*p).data[i].no_ktp=0;
		(*p).data[i].no_bpjs=0;
		(*p).data[i].no_telp=0;
		(*p).data[i].jk='-';
		(*p).data[i].tgl_lahir.tgl=0;
		(*p).data[i].tgl_lahir.bln=0;
		(*p).data[i].tgl_lahir.thn=0;
		(*p).data[i].tgl_daftar.tgl=0;
		(*p).data[i].tgl_daftar.bln=0;
		(*p).data[i].tgl_daftar.thn=0;
		//RIWAYAT
		for(j=0;j<MAX_R;j++){
			(*p).data[i].data_riwayat[j].id=0;
			strcpy((*p).data[i].data_riwayat[j].keluhan,"-");
			strcpy((*p).data[i].data_riwayat[j].catatan,"-");
			strcpy((*p).data[i].data_riwayat[j].resep,"-");
			(*p).data[i].data_riwayat[j].tgl_periksa.tgl=0;
			(*p).data[i].data_riwayat[j].tgl_periksa.bln=0;
			(*p).data[i].data_riwayat[j].tgl_periksa.thn=0;
			//Med Checkup
			(*p).data[i].data_riwayat[j].checkup.tinggi=0;
			(*p).data[i].data_riwayat[j].checkup.berat=0;
			(*p).data[i].data_riwayat[j].checkup.umur=0;
			(*p).data[i].data_riwayat[j].checkup.systole=0;
			(*p).data[i].data_riwayat[j].checkup.diastole=0;
		}	
	}
}

void initOneDataPasien(Data_Pasien *p)
{
	int j;
	(*p).id=0;
	strcpy((*p).nama,"-");
	strcpy((*p).alamat,"-");
	strcpy((*p).dokter,"-");
	strcpy((*p).goldar,"-");
	(*p).no_ktp=0;
	(*p).no_bpjs=0;
	(*p).no_telp=0;
	(*p).jk='-';
	(*p).tgl_lahir.tgl=0;
	(*p).tgl_lahir.bln=0;
	(*p).tgl_lahir.thn=0;
	(*p).tgl_daftar.tgl=0;
	(*p).tgl_daftar.bln=0;
	(*p).tgl_daftar.thn=0;
	//RIWAYAT
	for(j=0;j<MAX_R;j++){
		(*p).data_riwayat[j].id=0;
		strcpy((*p).data_riwayat[j].keluhan,"-");
		strcpy((*p).data_riwayat[j].catatan,"-");
		strcpy((*p).data_riwayat[j].resep,"-");
		(*p).data_riwayat[j].tgl_periksa.tgl=0;
		(*p).data_riwayat[j].tgl_periksa.bln=0;
		(*p).data_riwayat[j].tgl_periksa.thn=0;
		//Med Checkup
		(*p).data_riwayat[j].checkup.tinggi=0;
		(*p).data_riwayat[j].checkup.berat=0;
		(*p).data_riwayat[j].checkup.umur=0;
		(*p).data_riwayat[j].checkup.systole=0;
		(*p).data_riwayat[j].checkup.diastole=0;
	}
}

void displayMember(Pasien p)
{
	int i;
	puts("Data Member");
	for(i=0;i<MAX_P;i++){
		printf("\nID Pasien: %d",p.data[i].id);
		printf("\nNama Pasien: %s",p.data[i].nama);
	}
}

void displayDataWithRiwayat(Pasien p)
{
	int i, j;
	for(i=0;i<MAX_P;i++){
		puts("Kartu Kesehatan Pasien");
		printf("Nomor ID Pasien: %d",p.data[i].id);
		printf("\nNama Pasien: %s",p.data[i].nama);
		printf("\nJenis Kelamin: %c",p.data[i].jk);
		printf("\nTgl Lahir: %d/%d/%d",p.data[i].tgl_lahir.tgl,p.data[i].tgl_lahir.bln,p.data[i].tgl_lahir.thn);
		printf("\nGolongan Darah: %s",p.data[i].goldar);
		printf("\nAlamat: %s",p.data[i].alamat);
		printf("\nNo. KTP: %d",p.data[i].no_ktp);
		printf("\nNo. BPJS: %d",p.data[i].no_bpjs);
		printf("\nNo. Telp: %d",p.data[i].no_telp);
		printf("\nTgl Daftar: %d/%d/%d",p.data[i].tgl_daftar.tgl,p.data[i].tgl_daftar.bln,p.data[i].tgl_daftar.thn);
		printf("\nDokter Pribadi: %s",p.data[i].dokter);
		puts("\n\nRiwayat Pasien");
		for(j=0;j<MAX_R;j++){
			printf("\n\nTgl Periksa: %d/%d/%d",p.data[i].data_riwayat[j].tgl_periksa.tgl,p.data[i].data_riwayat[j].tgl_periksa.bln,p.data[i].data_riwayat[j].tgl_periksa.thn);
			printf("\nID Riwayat: %d",p.data[i].data_riwayat[j].id);
			puts("\n\nMedical Checkup");
			printf("Tinggi Badan: %f",p.data[i].data_riwayat[j].checkup.tinggi);
			printf("\nBerat Badan: %f",p.data[i].data_riwayat[j].checkup.berat);
			printf("\nUmur Badan: %d",p.data[i].data_riwayat[j].checkup.umur);
			printf("\nTekanan Darah: %d/%d",p.data[i].data_riwayat[j].checkup.systole,p.data[i].data_riwayat[j].checkup.diastole);
			printf("\nKeluhan: %s",p.data[i].data_riwayat[j].keluhan);
			printf("\nCatatan: %s",p.data[i].data_riwayat[j].catatan);
			printf("\nResep: %s",p.data[i].data_riwayat[j].resep);	
		}
	}
}

void insertRiwayat(Pasien *p, int id)
{
	int i, j, temp=0;
	for(i=0;i<MAX_P;i++){
		if((*p).data[i].id==id){
			for(j=0;j<MAX_R;j++){
				if((*p).data[i].data_riwayat[j].id==0){
					printf("Input ID: ");scanf("%d",&(*p).data[i].data_riwayat[j].id);
					printf("Input Tgl Periksa: ");scanf("%d",&(*p).data[i].data_riwayat[j].tgl_periksa.tgl);
					printf("Input Bln Periksa: ");scanf("%d",&(*p).data[i].data_riwayat[j].tgl_periksa.bln);
					printf("Input Thn Periksa: ");scanf("%d",&(*p).data[i].data_riwayat[j].tgl_periksa.thn);
					puts("\n\nMedical Checkup");
					printf("Tinggi Badan: ");scanf("%f",&(*p).data[i].data_riwayat[j].checkup.tinggi);
					printf("Berat Badan: ");scanf("%f",&(*p).data[i].data_riwayat[j].checkup.berat);
					printf("Umur Badan: ");scanf("%d",&(*p).data[i].data_riwayat[j].checkup.umur);
					printf("Tekanan Darah (Systole): ");scanf("%d",&(*p).data[i].data_riwayat[j].checkup.systole);
					printf("Tekanan Darah (Diastole): ");scanf("%d",&(*p).data[i].data_riwayat[j].checkup.diastole);
					printf("Keluhan: ");scanf("%s",&(*p).data[i].data_riwayat[j].keluhan);
					printf("Catatan: ");scanf("%s",&(*p).data[i].data_riwayat[j].catatan);
					printf("Resep: ");scanf("%s",&(*p).data[i].data_riwayat[j].resep);	
					puts("Data riwayat sudah disimpan!");
					temp=1;
					break;
				}
			}
			if(temp==1)
				break;
		}else{
			puts("Tidak ditemukan pasien dengan ID tersebut!");
		}
	}
}

void initRiwayat(Riwayat *r)
{
	strcpy((*r).catatan,"-");
	strcpy((*r).keluhan,"-");
	strcpy((*r).resep,"-");
	(*r).id=0;
	(*r).tgl_periksa.tgl=0;
	(*r).tgl_periksa.bln=0;
	(*r).tgl_periksa.thn=0;
	(*r).checkup.tinggi=0;
	(*r).checkup.berat=0;
	(*r).checkup.umur=0;
	(*r).checkup.systole=0;
	(*r).checkup.diastole=0;
}

void updateRiwayatByIDPasienIDRiwayat(Pasien *p, int idpas, int idrw)
{
	int i, j, temp=0;
	for(i=0;i<MAX_P;i++){
		if((*p).data[i].id==idpas){
			for(j=0;j<MAX_R;j++){
				if((*p).data[i].data_riwayat[j].id==idrw){
					puts("Update Data Riwayat");
					printf("Input Tgl Periksa: ");scanf("%d",&(*p).data[i].data_riwayat[j].tgl_periksa.tgl);
					printf("Input Bln Periksa: ");scanf("%d",&(*p).data[i].data_riwayat[j].tgl_periksa.bln);
					printf("Input Thn Periksa: ");scanf("%d",&(*p).data[i].data_riwayat[j].tgl_periksa.thn);
					puts("\n\nMedical Checkup");
					printf("Tinggi Badan: ");scanf("%f",&(*p).data[i].data_riwayat[j].checkup.tinggi);
					printf("Berat Badan: ");scanf("%f",&(*p).data[i].data_riwayat[j].checkup.berat);
					printf("Umur Badan: ");scanf("%d",&(*p).data[i].data_riwayat[j].checkup.umur);
					printf("Tekanan Darah (Systole): ");scanf("%d",&(*p).data[i].data_riwayat[j].checkup.systole);
					printf("Tekanan Darah (Diastole): ");scanf("%d",&(*p).data[i].data_riwayat[j].checkup.diastole);
					printf("Keluhan: ");scanf("%s",&(*p).data[i].data_riwayat[j].keluhan);
					printf("Catatan: ");scanf("%s",&(*p).data[i].data_riwayat[j].catatan);
					printf("Resep: ");scanf("%s",&(*p).data[i].data_riwayat[j].resep);	
					puts("Data riwayat sudah diupdate!");
					temp=1;
					break;
				}else{
					puts("Tidak ditemukan riwayat pasien dengan ID tersebut!");
				}
			}
			if(temp==1)
				break;
		}else{
			puts("Tidak ditemukan pasien dengan ID tersebut!");
		}
	}
}


void deleteRiwayatTerakhirByIDPasien(Pasien *p, int id)
{
	int i, j, temp=0;
	for(i=0;i<MAX_P;i++){
		if((*p).data[i].id==id){
			for(j=0;j<MAX_R;j++){
				if((*p).data[i].data_riwayat[0].id==0){
					puts("Tidak ada data riwayat!");
					temp=1;
					break;
				}else if((*p).data[i].data_riwayat[MAX_R-1].id!=0){
					initRiwayat(&(*p).data[i].data_riwayat[MAX_R-1]);		
					temp=1;
					break;
				}else{
					if((*p).data[i].data_riwayat[j].id==0){
						initRiwayat(&(*p).data[i].data_riwayat[j-1]);			
						temp=1;
						break;
					}					
				}
			}
			if(temp==1)
				break;
		}else{
			puts("Tidak ditemukan pasien dengan ID tersebut!");
		}
	}
}

int main()
{
	Pasien p;
	int id, idr, pilihan;
	init(&p);
	do
	{
		//system("clear");
		puts("Menu <nama program anda>");
		puts("1. Input Data Pasien");
		puts("2. Update Data Pasien By ID");
		puts("4. Input Riwayat Pasien By ID Pasien");
		puts("5. Update Riwayat By ID Pasien & ID Riwayat");
		puts("6. Delete Riwayat Terakhir Pasien By ID");
		puts("7. Menampilkan Data Member Pasien");
		puts("8. Menampilkan Data dan Riwayat Pasien");
		puts("0. Exit");
		printf("Pilih menu: ");
            scanf("%d",&pilihan);
        getchar();
		switch(pilihan)
		{
		case 1 :	createDataPasien(&p);
					break;
		case 2 :	printf("Input ID Pasien yang akan diupdate: ");scanf("%d",&id);
					updateDataPasienByID(&p, id);
					break;
		case 4 :	printf("Input ID Pasien: ");scanf("%d",&id);
					insertRiwayat(&p, id);
					break;
		case 5 :	printf("Input ID Pasien yang akan diubah riwayatnya: ");scanf("%d",&id);
					printf("Input ID Riwayat yang akan diubah: ");scanf("%d",&idr);
					updateRiwayatByIDPasienIDRiwayat(&p, id, idr);
					break;
		case 6 :	printf("Input ID Pasien yang akan dihapus riwayatnya: ");scanf("%d",&id);
					deleteRiwayatTerakhirByIDPasien(&p, id);
					break;
		case 7 :	displayMember(p);
					break;
		case 8 :	displayDataWithRiwayat(p);
					break;
		}
	}while(pilihan!=0);
}