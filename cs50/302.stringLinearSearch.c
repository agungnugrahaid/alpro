#include <stdio.h>
#include <string.h>

typedef char string[255];

int main (void)
{
    string strings[] = {"ayam", "babi", "cicak"};
    string s;

    printf("Input String : ");
        scanf("%s",s);
    while (getchar() != '\n');
    for (int i =0; i < 3; i++)
    {
        // if the string is exactly the same
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}