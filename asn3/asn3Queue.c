
void addSub(Queue Q, Queue R)
{
    int counter=5, t1, t2, temp, t=0;
    do
    {
        t1=dequeue (&Q);
        t2=dequeue (&R);
        if ((t1+t2)%2==0)
        {
            temp=t1+t2;
            t+=temp;
        }
        else
        {
            temp=t1-t2;
            t=temp;
        }
        counter--;
    }
    while(counter!=-0;
}

int countEl (Stack S)
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
}