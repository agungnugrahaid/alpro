#include <stdio.h>

typedef char string[255];

//ADT Data_Mahasiswa
typedef struct 
{
    string nama[255];
    string prodi;
    float ipk;
}Data_Mahasiswa;


//Array untuk meng-encapsulate Data_Mahasiswa
typedef struct
{
    Data_Mahasiswa Data[5]
};
