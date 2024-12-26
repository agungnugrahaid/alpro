#include <stdio.h>

int main()
{
    int i;
    int a[7], *x, *y, sum=0;
    int pointersum;
    int pointersumx;
    for (i=0; i<5; i++)
        {
            a[i]=i-2;
            printf("a[%d] = %d\n", i, a[i]);
        }
    
    x=a;
    x++;
    *x=8;
    x--;

    y=x;
    y=&a[3];
    *y=*x+3;
    
    printf("x points to value: %d\n", *x);
    printf("y points to value: %d\n", *y);
    
    for (i=0; i<5;i++)
    {
        sum+=a[i];
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("x points to value: %d\n", *x);
    printf("y points to value: %d\n", *y);
    pointersum=*x+*y;
    //pointersumx=x+y;
    printf("\n nilai akhir sum =%d \n",sum);
    printf("\n nilai x +y =%d \n",pointersum);
    printf("\n nilai x =%d \n",*x);
    printf("\n nilai y =%d \n",*y);
    //printf("\n %d \n x",pointersumx);
}