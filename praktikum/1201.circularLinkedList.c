#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char string[255];

typedef struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
    char jk;
} Mahasiswa;

typedef struct tNode *address;

typedef struct tNode {
    Mahasiswa value;
    address Next;
} Node;

typedef struct List {
    address First;
} List;

void createEmpty(List *L) {
    (*L).First = NULL;
}

bool isEmpty(List L) {
    return L.First == NULL;
}

bool isOneElement(List L) {
    return L.First != NULL && L.First->Next == L.First;
}

address alokasi(Mahasiswa x) {
    address P = (Node *)malloc(sizeof(Node));
    if (P != NULL) {
        P->value = x;
        P->Next = NULL;
    }
    return P;
}

void dealokasi(address P) {
    free(P);
}

address findLast(List L) {
    address P = L.First;
    if (!isEmpty(L)) {
        while (P->Next != L.First) {
            P = P->Next;
        }
    }
    return P;
}

void insertFirst(List *L, address P) {
    if (isEmpty(*L)) {
        (*L).First = P;
        P->Next = (*L).First;
    } else {
        address Last = findLast(*L);
        P->Next = (*L).First;
        (*L).First = P;
        Last->Next = (*L).First;
    }
}

void insertValueFirst(List *L, Mahasiswa x) {
    address P = alokasi(x);
    insertFirst(L, P);
    printf("Data berhasil dimasukkan!\n");
}

void delFirst(List *L) {
    if (!isEmpty(*L)) {
        address P = (*L).First;
        address Last = findLast(*L);
        if (isOneElement(*L)) {
            (*L).First = NULL;
        } else {
            (*L).First = P->Next;
            Last->Next = (*L).First;
        }
        dealokasi(P);
    } else {
        printf("List Empty!\n");
    }
}

void insertLast(List *L, Mahasiswa x) {
    address P = alokasi(x);
    if (isEmpty(*L)) {
        insertFirst(L, P);
    } else {
        address Last = findLast(*L);
        P->Next = Last->Next;
        Last->Next = P;
    }
    printf("Berhasil memasukkan data!\n");
}

void delLast(List *L) {
    if (!isEmpty(*L)) {
        address Last = findLast(*L);
        if (isOneElement(*L)) {
            delFirst(L);
        } else {
            address P = (*L).First;
            while (P->Next != Last) {
                P = P->Next;
            }
            P->Next = Last->Next;
            dealokasi(Last);
        }
    } else {
        printf("List Empty!\n");
    }
}

void delAfter(List *L, int after) {
    if (!isEmpty(*L)) {
        address P = (*L).First;
        bool found = false;
        do {
            if (P->Next->value.nim == after) {
                found = true;
                break;
            }
            P = P->Next;
        } while (P->Next != (*L).First);

        if (found) {
            address Q = P->Next;
            P->Next = Q->Next;
            dealokasi(Q);
            printf("Data dengan NIM %d berhasil dihapus!\n", after);
        } else {
            printf("Data dengan NIM %d tidak ditemukan!\n", after);
        }
    } else {
        printf("List Empty!\n");
    }
}

void insertAfter(List *L, Mahasiswa a, string after) {
    if (!isEmpty(*L)) {
        address P = (*L).First;
        bool found = false;
        do {
            if (strcmp(P->value.nama, after) == 0) {
                found = true;
                break;
            }
            P = P->Next;
        } while (P != (*L).First);

        if (found) {
            address Ptr = alokasi(a);
            Ptr->Next = P->Next;
            P->Next = Ptr;
            printf("Berhasil memasukkan data!\n");
        } else {
            printf("Data dengan nama %s tidak ditemukan!\n", after);
        }
    } else {
        printf("List Empty!\n");
    }
}

void showList(List L) {
    if (!isEmpty(L)) {
        address P = L.First;
        do {
            printf("\nNama: %s\n", P->value.nama);
            printf("Jenis Kelamin: %c\n", P->value.jk);
            printf("NIM: %d\n", P->value.nim);
            printf("IPK: %.2f\n", P->value.ipk);
            P = P->Next;
        } while (P != L.First);
    } else {
        printf("List Empty!\n");
    }
}

void cariByNIM(List L, int nim) {
    if (!isEmpty(L)) {
        address P = L.First;
        bool found = false;
        do {
            if (P->value.nim == nim) {
                printf("\nNama: %s\n", P->value.nama);
                printf("Jenis Kelamin: %c\n", P->value.jk);
                printf("NIM: %d\n", P->value.nim);
                printf("IPK: %.2f\n", P->value.ipk);
                found = true;
                break;
            }
            P = P->Next;
        } while (P != L.First);

        if (!found) {
            printf("Tidak ada data mahasiswa dengan NIM %d!\n", nim);
        }
    } else {
        printf("List Empty!\n");
    }
}

void orderByNIM(List *L) {
    if (!isEmpty(*L)) {
        address P = (*L).First;
        do {
            address Q = P->Next;
            while (Q != (*L).First) {
                if (P->value.nim > Q->value.nim) {
                    Mahasiswa temp = P->value;
                    P->value = Q->value;
                    Q->value = temp;
                }
                Q = Q->Next;
            }
            P = P->Next;
        } while (P->Next != (*L).First);
        printf("List berhasil diurutkan berdasarkan NIM!\n");
    } else {
        printf("List Empty!\n");
    }
}

void showIPKTertinggi(List L) {
    if (!isEmpty(L)) {
        address P = L.First;
        address max = P;
        do {
            if (P->value.ipk > max->value.ipk) {
                max = P;
            }
            P = P->Next;
        } while (P != L.First);
        printf("\nMahasiswa dengan IPK Tertinggi:\n");
        printf("Nama: %s\n", max->value.nama);
        printf("Jenis Kelamin: %c\n", max->value.jk);
        printf("NIM: %d\n", max->value.nim);
        printf("IPK: %.2f\n", max->value.ipk);
    } else {
        printf("List Empty!\n");
    }
}

void showAvgIPK(List L) {
    if (!isEmpty(L)) {
        address P = L.First;
        float total = 0;
        int count = 0;
        do {
            total += P->value.ipk;
            count++;
            P = P->Next;
        } while (P != L.First);
        printf("\nRata-rata IPK: %.2f\n", total / count);
    } else {
        printf("List Empty!\n");
    }
}

int main() {
    char pilihan;
    List L;
    Mahasiswa a;
    string after;
    int nim;

    createEmpty(&L);

    do {
        puts("\nProgram Mahasiswa Gadungan");
        puts("[1] Insert First Mahasiswa");
        puts("[2] Delete First Mahasiswa");
        puts("[3] Insert Last Mahasiswa");
        puts("[4] Delete Last Mahasiswa");
        puts("[5] Insert After Nama Tertentu");
        puts("[6] Delete by NIM");
        puts("[7] Show List");
        puts("[8] Search Mahasiswa by NIM");
        puts("[9] Show Mahasiswa IPK Tertinggi");
        puts("[a] Show Average IPK");
        puts("[b] Order by NIM Ascending");
        puts("[0] Keluar Program");
        printf("Pilih Menu : ");
        scanf(" %c", &pilihan);  // Menggunakan spasi sebelum %c untuk membersihkan buffer

        switch (pilihan) {
            case '1':
                printf("Input Nama: "); scanf("%s", a.nama);
                printf("Input Jenis Kelamin (L/P): "); scanf(" %c", &a.jk);
                printf("Input NIM: "); scanf("%d", &a.nim);
                printf("Input IPK: "); scanf("%f", &a.ipk);
                insertValueFirst(&L, a);
                break;
            case '2':
                delFirst(&L);
                break;
            case '3':
                printf("Input Nama: "); scanf("%s", a.nama);
                printf("Input Jenis Kelamin (L/P): "); scanf(" %c", &a.jk);
                printf("Input NIM: "); scanf("%d", &a.nim);
                printf("Input IPK: "); scanf("%f", &a.ipk);
                insertLast(&L, a);
                break;
            case '4':
                delLast(&L);
                break;
            case '5':
                printf("Input Nama: "); scanf("%s", a.nama);
                printf("Input Jenis Kelamin (L/P): "); scanf(" %c", &a.jk);
                printf("Input NIM: "); scanf("%d", &a.nim);
                printf("Input IPK: "); scanf("%f", &a.ipk);
                printf("Insert setelah nama: "); scanf("%s", after);
                insertAfter(&L, a, after);
                break;
            case '6':
                printf("Delete By NIM: "); scanf("%d", &nim);
                delAfter(&L, nim);
                break;
            case '7':
                showList(L);
                break;
            case '8':
                printf("Masukkan NIM yang dicari: "); scanf("%d", &nim);
                cariByNIM(L, nim);
                break;
            case '9':
                showIPKTertinggi(L);
                break;
            case 'a':
                showAvgIPK(L);
                break;
            case 'b':
                orderByNIM(&L);
                break;
            case '0':
                printf("Keluar program.\n");
                break;
            default:
                printf("Menu tidak ditemukan!\n");
        }
    } while (pilihan != '0');

    return 0;
}