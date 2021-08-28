# include "phonebook.h"
#include <stdbool.h>

// Additional function that writes into array symbols from keybord (the function also checks whether array is overflowed)
void    GetStr(char *str, int MaxLen)
{
    int i;
    int c;

    i = 0;
    while ((c = getchar()) != '\n')
    {
        if (str != NULL && i < MaxLen)
            str[i++] = c;
    }
    if (str != NULL && i < MaxLen)
        str[i] = 0;
}

// Function for case '1' - read data about Friend from keyboard and write it into structure
void    ReadFriend(Friend *F)
{
    printf("Name: ");
    GetStr((*F).Name, LenName);
    printf("Surname: ");
    GetStr((*F).Surname, LenSurname);
    printf("Sex (m or f): ");
    F->Sex = getchar();
    printf("Birthday: \nDay: ");
    scanf("%i", &F->DateOfBirth.Day);
    printf("Month: ");
    scanf("%i", &F->DateOfBirth.Month);
    printf("Year: ");
    scanf("%i", &F->DateOfBirth.Year);
    printf("Phonenumber: ");
    GetStr((*F).Phone, 18);
    GetStr((*F).Phone, 18);
//    printf("Press Enter: ");
 //   GetStr((*F).None, 0);
    printf("\n");
}

// Function for case '2' - print data about Friend from structure
void    PrintFriend(Friend F)
{
    printf("%s %s, tel: %s, sex: %c, Birthday: %02i.%02i.%i",\
    F.Name, F.Surname, F.Phone, F.Sex, F.DateOfBirth.Day, F.DateOfBirth.Month, F.DateOfBirth.Year);
    printf("\n");   
}

// Function that opens the file and writes data in this file 
int Save_DB(char *File_name, Friend *Base, int Size_DB)
{
    FILE    *FD;

    FD = fopen(File_name, "wb");
    if (FD == 0)
    {
        printf(strerror(errno));
        return (0);
    }
    fwrite(Base, sizeof(Friend), Size_DB, FD);
    fclose(FD);
    return(1);
}

// Function that loads data from the file
int LoadDB(char *FileName, Friend *Base, int MaxNum)
{
    FILE    *FD;
    int     n;

    FD = fopen(FileName, "rb");
    if (FD == NULL)
    {
        printf(strerror(errno));
        printf("\n");
        return (0);
    }
    n = fread(Base, sizeof(Friend), MaxNum, FD);
    fclose(FD);
    return n;
}

// Sorting by Surname (alphabetically)
void    Sort_Surname(Friend *Base, int  N)
{
    int i;
    int j;
    Friend temp;

    i = 0;
    while (i < N - 1)
    {
        j = i + 1;
        while (j < N)
        {
            if (strcmp(Base[i].Surname, Base[j].Surname) > 0)
            {
                temp = Base[i];
                Base[i] = Base[j];
                Base[j] = temp;
            }
            j++;
        }
        i++;
    }
}
// Sorting by birthday (alphabetically)
void    Sort_Birthday(Friend *Base, int  N)
{
    int i;
    int j;
    Friend temp;
    i = 0;
    while (i < N)
    {
        j = i + 1;
        while (j < N)
        {
            if (IsDateLess(Base[i], Base[j]) > 0)
            {
                temp = Base[i];
                Base[i] = Base[j];
                Base[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int IsDateLess(Friend A, Friend B)
{
    if (A.DateOfBirth.Year == B.DateOfBirth.Year)
    {
        if (A.DateOfBirth.Month - B.DateOfBirth.Year)
            return (A.DateOfBirth.Day - B.DateOfBirth.Day);
        else
            return (A.DateOfBirth.Month - B.DateOfBirth.Month);
    }
    return (A.DateOfBirth.Year - B.DateOfBirth.Year);
}