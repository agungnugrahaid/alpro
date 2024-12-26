#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

typedef int Element;

typedef struct
{
    int top;
    Element array[MAX];
}Stack;

//The Default Stack Functions
void initStack(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push (Stack *s, Element var);
Element pop(Stack *s);
void displayStack(Stack s);

//The Additional Functions
int countEl(Stack S)
{
    int temp, t=0;
    do
    {
        temp=pop(&S);
        if(temp%2==0)
        {
            t+=temp;
        }
        else
        {
            t-=temp;
        }
    }while(S.top!=1);
    printf("Nilai akhir variabel t=%d\n",t);
}

//The Main Action
int main()
{
    system("clear");
    Stack s;
    Element input, temp;
    initStack(&s);
    do
    {
        //system("clear");
        puts("\nMenu Stack With You!");
        puts("1. Push Element");
        puts("2. Pop Element");
        puts("3. Display Stack");
        puts("4. Execute Order ASN!");
        puts("0. Exit");
        puts("Pilih Menu: ");
        switch(getchar())
        {
            case '1':
                if(!isFull(s))
                {
                    do{
                        printf("Input Integer: ");
                            scanf("%d", &input);
                    }while(input==0);
                    push(&s, input);
                }
                else
                {
                    printf("Stack is Full Yo!");
                }
                break;
            case '2':
                temp=pop(&s);
                if(temp!=0)
                {
                    printf("Popped Element: %d", temp);
                }
                break;
            case '3':
                displayStack(s);
                break;
            case '4':
                countEl(s);
                break;
            case '0':
                return 0;
                break;
        }
    } while (getchar()!=27);
    getchar();
    return 0;
}

//The Default Stack Functions
void initStack(Stack *s)
{
    (*s).top=-1;
}

bool isEmpty(Stack s)
{
    if(s.top == -1)
        return true;
    else
        return false;
}

bool isFull(Stack s)
{
    if(s.top == MAX-1)
        return true;
    else
        return false;
}

void push (Stack *s, Element var)
{
    if(!isFull(*s))
    {
        (*s).top++;
        (*s).array[(*s).top]=var;
    }
    else
    {
        printf("Stack is full\n");
    }
}

Element pop(Stack *s)
{
    Element var=0;
    if(!isEmpty(*s))
    {
        var=(*s).array[(*s).top];
        (*s).top--;
        return var;
    }
    else
    {
        printf("Can't Pop! Stack is Empty!\n");
        return var;
    }
}

void displayStack(Stack s)
{
    Element e;
    if(!isEmpty(s))
    {
        do
        {
            e=pop(&s);
            printf("\n\n%d",e);
        } while (!isEmpty(s));
    }
    else
    {
        printf("Stack is Empty!");
    }
}