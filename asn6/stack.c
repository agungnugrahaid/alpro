#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef int Element;
typedef struct Stack
{
    int top;
    Element array[MAX];
}Stack;


//Default Stack Process
void initStack(Stack *s)
{
    (*s).top=-1;
}

bool isEmpty(Stack s)
{
    if(s.top==-1)
        return true;
    else
        return false;
}

bool isFull(Stack s)
{
    if(s.top==MAX-1)
        return true;
    else
        return false;
}

void push(Stack *s, Element var)
{
    if(!isFull(*s))
    {
        (*s).top++;
        (*s).array[(*s).top]=var;
    }
    else
    {
        printf("Stack is Full!\n");
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
        printf("Can't pop, stack is Empty!\n");
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
        printf("\n");
    }
    else
    {
        printf("Can't display, stack is Empty!\n");
    }
}

int countEl(Stack S)
{
    int temp, t=0;
    do
    {
        temp=pop(&S);
        //printf("t value before = %d\n",t);
        //printf("temp value before = %d\n",temp);
        displayStack(S);
        if(temp%2==0)
        {
            printf("temp genap = %d\n", temp);
            printf("t = %d + ",t);
            t+=temp;
            printf("%d = %d", temp, t);
        }
        else
        {    
            printf("temp ganjil = %d\n", temp);
            printf("t = %d - ",t);
            t-=temp;
            printf("%d = %d", temp, t);
        }
        getchar();
    } while (S.top!=-1);
    return t;
}

int main()
{
    Stack s;
    Element input, temp;
    initStack(&s);

    push(&s,3);
    push(&s,11);
    push(&s,2);
    push(&s,5);
    push(&s,4);
    
    int t = countEl(s);
    printf("Nilai akhir t = %d\n",t);
    return 0;
}