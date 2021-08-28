# ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#define MAX 100
#define LenName 15
#define LenSurname 30
#define Tel 18
#define file_size 100
typedef struct
{
    /* data */
    int Day;
    int Month;
    int Year;
} B_Date;

typedef struct
{
    /* data */
    char    Name[15]; /* Length of the name - max 15 char*/
    char    Surname[30]; /* Length of the surname - max 15 char*/
    char    Sex; /*male or female*/
    B_Date  DateOfBirth;
    char    Phone[18]; /*max length of phonenumber - 18. Use char as there can be '+' sign in phonenumber*/
    char    None[0];
} Friend;
void    GetStr(char *str, int MaxLen);
void    ReadFriend(Friend *F);
void    PrintFriend(Friend F);
int     Save_DB(char *File_name, Friend *Base, int Size_DB);
int     LoadDB(char *FileName, Friend *Base, int MaxNum);
void    Sort_Surname(Friend *Base, int  N);
void    Sort_Birthday(Friend *Base, int  N);
int     IsDateLess(Friend A, Friend B);
# endif