# include "phonebook.h"

int main(void)
{
    static Friend DB[MAX];
    int DBSize;
    int run;
    int i;
    char    fname[file_size];

    run = 1;
    DBSize = 0;
    i = 0;
    while (run)
    {
        printf("0 - exit\n\
        1 - input for a new friend\n\
        2 - print all\n\
        3 - delete data under specific number\n\
        4 - sort data by surname (alphabetically)\n\
        6 - save data in a file\n\
        7 - read data from a given file\n");
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
            case '3':
                if (DBSize == 0)
                {
                    printf("There is no data in the phonebook\n");
                    break;
                }
                printf("Enter number in phonebook to delete: ");
                scanf("%i", &i);
                GetStr(NULL, 0);
                if (i >= 0 && i < DBSize)
                {
                    int j;
                    for (j = i + 1; j < DBSize; j++)
                        DB[j - 1] = DB[j];
                    --DBSize;
                }
                else
                    printf("Number should be in [0...%i] range\n", DBSize - 1);
                break;
            case '4':
                Sort_Surname(DB, DBSize);
                break;
            case '6':
                printf("Save data in file: ");
                GetStr(fname, file_size);
                if (Save_DB(fname, DB, DBSize))
                    printf("OK, data was saved in file %s\n", fname);
                else
                    printf("Oooops, smth went wrong!\n");
                break;
            case '7':
                printf("Enter name of the file to load: ");
                GetStr(fname, file_size);
                if (LoadDB(fname, DB, MAX))
                {
                    DBSize = LoadDB(fname, DB, MAX);
                    printf("Read %i lines\n", DBSize);
                }
                break;
            default:
                printf("Incorrect input\n");
        }
    }
    return (1);
}