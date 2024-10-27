#include <stdio.h>
#include <string.h>

typedef char string[255];

int main (void)
{
    
    string names[] = {"Anto", "Budi", "Citra"};
    string numbers[] = {"081-111", "081-222", "081-333"};
    string name;
    string number;

    printf("Input Name : ");
        scanf("%s",name);

    for (int i = 0; i<3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found! %s \n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found!\n");
}