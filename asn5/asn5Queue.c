#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 3

typedef int Element;

typedef struct
{
    int head;
    int tail;
    Element data[MAX];
}Queue;

//The Default Queue Functions
void initQueue(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
bool isOneElement(Queue q);
void enQueue(Queue *q, Element data);
Element deQueue(Queue *q);
void displayQueue(Queue q);

//The Additional Functions
void addSub(Queue q, Queue r)
{
    int counter = 5, t1, t2, temp, t = 0;
    do {
        t1=deQueue(&q); // Mengeluarkan elemen dari Queue q
        t2=deQueue(&r); // Mengeluarkan elemen dari Queue r

        //if (t1 == -1 || t2 == -1) { // Cek jika terjadi error
        //    printf("Error: Salah satu queue kosong.\n");
        //    break;
        //}

        if ((t1 + t2) % 2 == 0) {
            temp = t1 + t2;
            t += temp;
        } else {
            temp = t1 - t2;
            t = temp;
        }
        counter--;
    } while (counter != 0);
    printf("\nNilai akhir variabel t = %d\n", t);
}

//The Main Action
int main()
{
    Queue q,r;
    Element input, temp;
    initQueue(&q);
    initQueue(&r);
    do
    {
        //system("clear");
        puts("\nMenu Antrian Ala-Ala");
        puts("1. enQueu Element q");
        puts("2. enQueu Element r");
        //puts("3. deQueu Element");
        puts("3. Display Queue q");
        puts("4. Display Queue q");
        puts("5. Jalankan Fungsi AddSub");
        puts("Esc. Exit");
        puts("Pilih Menu: ");
        switch(getchar()){
            case '1':
                if(isFull(q))
                    printf("Queu is Full!");
                else{
                    do{
                        printf("Input Integer: ");
                            scanf("%d", &input);
                    }
                    while (input==0);
                    enQueue(&q, input);
                }
                break;
            case '2':
                if(isFull(r))
                    printf("Queue is Full!");
                else{
                    do{
                        printf("Input Integer: ");
                            scanf("%d", &input);
                    }
                    while (input==0);
                    enQueue(&r, input);
                }
                break;
            //case '2':
            //    deQueue(&q);
            //    break;
            case '3':
                displayQueue(q);
                break;
            case '4':
                displayQueue(r);
                break;
            case '5':
                addSub(q, r);
                break;
        }
    } while(getchar()!=27);  
} 

//The Default Queue Functions
void initQueue(Queue *q)
{
    //set head dan tail =-1, tidak ada antrian/elemen nya kosong
    (*q).head=(*q).tail=-1;
}

bool isEmpty(Queue q)
{
    //kalau head dan tail nya =-1 berarti antrian/elemen nya kosong
    if(q.head==-1 && q.tail==-1)
        return true;
    else
        return false;
}

bool isFull(Queue q)
{
    if((q.head<q.tail && (q.tail-q.head)==MAX-1) ||
       (q.head>q.tail && (q.head-q.tail)==1)
    )
        return true;
    else
        return false;
}

bool isOneElement(Queue q)
{
    if(q.head==q.tail && q.head!=-1)
        return true;
    else
        return false;
}

void enQueue(Queue *q, Element data)
{
    //cek apakah antrian full
        //jika iya, tampilkan notifikasi penuh
    //cek apakah antrian empty
        //jika iya, set head dan tail menjadi 0
        //kemudian isi data pada antrian
    //cek apakah tail nya sudah di ujung (MAX)
        //jika iya, set pointer tail nya menjadi 0
        //jika no, set pointer tail nya menjadi tail++
        //kemudian isi data pada antrian
    if (isFull(*q))
        printf("\n Queu is Full!");
    else
    if (isEmpty(*q))
        {
            (*q).head=(*q).tail=0;
            (*q).data[(*q).tail]=data;
        }
    else
    if ((*q).tail==MAX-1)
        {
            (*q).tail=0;
        }
    else
        {
        (*q).tail++;
        }
    (*q).data[(*q).tail]=data;
            
}

Element deQueue(Queue *q) {
    Element temp;
    if (isEmpty(*q)) {
        printf("Queue is Empty!\n");
        return -1; // Asumsikan -1 sebagai nilai error jika queue kosong
    } else if (isOneElement(*q)) {
        temp = q->data[q->head];
        initQueue(q); // Reset queue jika hanya ada satu elemen
    } else {
        temp = q->data[q->head];
        if (q->head == MAX - 1) {
            q->head = 0; // Pindah ke awal jika sudah di ujung
        } else {
            q->head++;
        }
    }
    return temp;
}

void displayQueue(Queue q){
    int i;
    if(isEmpty(q))
        printf("Queue is empty!");
    else
    {
        if(q.head<=q.tail)
        {
            for(i=q.head;i<=MAX-1;i++)
            {
                printf("%d ",q.data[i]);
            }
        }
        else
        {
            for(i=q.head;i<=MAX-1;i++)
            {
                printf("%d ",q.data[i]);
            }
            for (i=0;i<=q.tail;i++)
            {
                printf("%d ",q.data[i]);
            }
        }
    }
}