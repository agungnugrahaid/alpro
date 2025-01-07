#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 3

typedef int Element;
typedef struct Queue
{
    int head;
    int tail;
    Element data[MAX];
}Queue;

void initQ(Queue *q)
{
    (*q).head=(*q).tail=-1;
}

bool isEmpty(Queue q)
{
    if(q.head==-1 && q.tail==-1)
        return true;
    else
        return false;
}

bool isFull(Queue q)
{
    if ((q.head<q.tail && (q.tail-q.head==MAX-1)) ||
        (q.head>q.tail && (q.head-q.tail==1)))
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

void enQ(Queue *q, Element data)
{
    if(isFull(*q))
        printf("Queue is Full!\n");
    else
        if(isEmpty(*q))
        {
            (*q).head=(*q).tail=0;
            (*q).data[(*q).tail]=data;
        }
        else
        {
            if((*q).tail==MAX-1)
            {
                (*q).tail=0;
            }
            else
            {
                (*q).tail++;
            }
            (*q).data[(*q).tail]=data;
        }
}

int deQ(Queue *q)
{ 
    Element temp=(*q).data[(*q).head];
    if(isEmpty(*q))
        return 0;
    else
    {
        if(isOneElement(*q))
        {
            initQ(q);
        }
        else
        {
            if((*q).head==MAX-1)
            {
                (*q).head=0;
            }
            else
            {
                (*q).head++;
            }
        }
    }
    return temp;
}

void displayQ(Queue q)
{
    int i;
    if(isEmpty(q))
        printf("Queue is Empty!\n");
    else
    {
        if(q.head<=q.tail)
        {
            for(i=q.head;i<=q.tail;i++)
            {
                printf("%d  ", q.data[i]);
            }
            printf("\n");
        }
        else
        {
            for(i=q.head;i<=MAX-1;i++)
            {
                printf("%d  ", q.data[i]);
            }
            for(i=0;i<=q.tail;i++)
            {
                printf("%d  ", q.data[i]);
            }
        }
    }
}

int addSub(Queue *q, Queue *r)
{
    int counter=5, t1, t2, temp, t=0;
    do
    {
        t1=deQ(q);
        t2=deQ(r);
        printf("\ncounter ke %d ", counter);
        //printf("\nt = %d",t);
        if((t1+t2)%2==0)
        {
            temp=t1+t2;
            printf("\ntemp = t1+t2 = %d + %d = %d", t1, t2, temp);
            printf("\nt = %d + ",t);
            t+=temp;
            printf("%d = %d\n",temp, t);
        }
        else
        {
            temp=t1-t2;
            printf("\ntemp = t1-t2 = %d - %d = %d", t1, t2, temp);
            printf("\nt = %d - ",t);
            t-=temp;
            printf("%d = %d\n",temp, t);
        }
        counter--;
        getchar();
    } while (counter!=-0);
    return t;
}

int main()
{
    system("clear");
    Queue q,r;
    Element input, temp;
    initQ(&q);
    initQ(&r);

    enQ(&q,16);
    enQ(&q,18);
    enQ(&q,10);
    printf("Queue Q = ");
    displayQ(q);

    enQ(&r,12);
    enQ(&r,67);
    enQ(&r,32);
    printf("Queue R = ");
    displayQ(r);

    int t = addSub(&q,&r);

    printf("Nilai akhir t = %d\n",t);
    return 0;
}