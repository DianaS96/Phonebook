#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    /* data */
    char    Name[15]; /* Length of the name - max 15 char*/
    char    Surname[30]; /* Length of the surname - max 15 char*/
    char    Sex; /*male or female*/
    char    Phone[18]; /*max length of phonenumber - 18. Use char as there can be '+' sign in phonenumber*/
} Friend;

void    ReadFriend(Friend *F)
{
    printf("Name: ");
    gets((*F).Name);
    printf("Surname: ");
    gets((*F).Surname);
    printf("Sex (m or f): ");
    F->Sex = getchar();
    printf("Phonenumber: ");
    gets((*F).Phone);
    gets((*F).Phone);
    printf("\n");   
}

void    PrintFriend(Friend F)
{
    printf("%s %s, tel: %s, sex: %c", F.Name, F.Surname, F.Phone, F.Sex);
    printf("\n");   
}

int main(void)
{
    static Friend DB[MAX];
    int DBSize;
    int run;

    run = 1;
    DBSize = 0;
    while (run)
    {
        printf("0 - exit\n\
        1 - input for a new friend\n\
        2 - print all\n");
        switch(getch())
        {
            case '0':
                run = 0;
                printf("Buy!\n");
                break;
            case '1':
                if (DBSize < MAX)
                    ReadFriend(&DB[DBSize++]);
                else
                    printf("No space, sorry =(\n");
                break;
            case '2':
                for (int i = 0; i < DBSize; i++)
                {
                    printf("%i) ", i);
                    PrintFriend(DB[i]);
                }
                break;
            default:
                printf("Incorrect input\n");
        }
    }
    return (1);
}