#include <stdio.h>
#include <string.h>

typedef char string[255];

//creating data structure
typedef struct{
    string name;
    string number;
}
person;

int main (void)
{
    person people[3];
    //strcpy digunakan untuk "copy" value ke dalam array
    strcpy(people[0].name, "Andi");
    strcpy(people[0].number, "081-111");

    strcpy(people[1].name, "Budi");
    strcpy(people[1].number, "081-222");

    strcpy(people[2].name, "Citra");
    strcpy(people[2].number, "081-333");

    string name;

    printf("Input Name : ");
        scanf("%s",name);

    for (int i = 0; i<3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found! %s \n", people[i].number);
            return 0;
        }
    }
    printf("Not Found!\n");
}