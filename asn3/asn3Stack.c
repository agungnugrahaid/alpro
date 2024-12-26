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