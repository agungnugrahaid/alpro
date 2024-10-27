#include <stdio.h>

int main (void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n;

    printf("Input Numbers : ");
        scanf("%d",&n);
    
    for (int i =0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}