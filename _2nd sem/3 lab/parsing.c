#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcs.h"

// Реализовать все необходимые функции для использования типа данных —
// добавление новой записи, вывод информации, изменение существующей записи,
// удаление существующей записи, сортировка по каждому из полей структуры.
// Добавить перечисление и одновременную сортировку по нескольким параметрам

// Использовать бинарный файл для сохранения данных перед закрытием
// программы. Реализовать функцию для дополнения текущей базы из существующего файла

// Библиотека. Содержатся данные о книгах — id, название, дата создания, автор,
// популярность(сколько раз читали). Найти N самых популярных книг. Найти все книги
// выбранного автора.

struct Date
{
	int day;
	int month;
	int year;
};
typedef struct Date date;

struct Book
{
	long int id;
	char name[255];
	date creation;
	char author[255];
	long int pop;
};
typedef struct Book books;

date getDate()
{
	date D;
		//DAY
	do
	{	
		printf("Enter the day of month:        ");
		D.day = inputPosInt();
		if(D.day > 31)
			printf("There are only 31 day a month, try again\n");
	}
	while(D.day > 31);
		//MONTH
	do
	{	
		printf("Enter the month:               ");
		D.month = inputPosInt();
		if(D.month > 12)
			printf("There are only 12 months, try again\n");
	}
	while(D.month > 12);
		//YEAR
	do
	{	
		printf("Enter the year:                ");
		D.year = inputPosInt();
		if(D.year > 2023)
			printf("It's 2023 year now, try again\n");
	}
	while(D.year > 2023);
	return D;
}

void getStruct(books *catalog, int i)
{
	printf("Enter ID of %d book:            ", i+1);
	(catalog + i)->id = inputPosLong();
	printf("Enter the name of this book:   ");
	s_gets((catalog + i)->name, 255);
	printf("\nChoose the date of creation this book:\n");
	(catalog + i)->creation = getDate();
	printf("\nEnter the name of author:      ");
	s_gets((catalog + i)->author, 255);
	printf("Enter the popularity of book:  ");
	(catalog + i)->pop = inputPosLong();
}

void newArrStruct(books *catalog, int *size)
{
	printf("Choose number of records:      ");
	*size = inputPosInt();
	catalog = (books*)realloc(catalog, (*size)*sizeof(books));
	for(int i = 0; i < *size; i++)
	{
		printf("_______________________________\n");
		printf("BOOK #%d\n", i+1);
		getStruct(catalog, i);
	}
	printf("\nPress ENTER to continue...");
	getch();
}

void addStruct(books *catalog, int *size)
{ 
	printf("How many books do you want to add? ");
	int add = inputPosInt();
	catalog = (books*)realloc(catalog, (*size + add)*sizeof(books));	
	for(int i = *size; i < *size + add; i++)
	{
		printf("_______________________________\n");
		printf("BOOK #%d\n", i+1);
		getStruct(catalog, i);
	}
	*size += add;
	printf("\nPress ENTER to continue...");
	getch();
}

void printStruct(books *catalog, int *size)
{
	if(*size == 0)
		printf("At first fill the catalog\n");
	else
	{		
		printf("__________________________________________________________________________________________\n");
		printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|\n");
		for(int i = 0; i < *size; i++)
		{
			printf("__________________________________________________________________________________________\n");
			printf("| %.8ld |", (catalog + i)->id);
			printf(" %25s |", (catalog + i)->name);
			printf(" %.2d.%.2d.%.4d |", (catalog + i)->creation.day, (catalog + i)->creation.month, (catalog + i)->creation.year);
			printf(" %25s |", (catalog + i)->author);
			printf(" %6ld |\n",(catalog + i)->pop);
		}
	printf("__________________________________________________________________________________________\n");
	}
	printf("\nPress ENTER to continue...");
	getch();
}

void delStruct(books *catalog, int *size)
{
	printf("Enter the ID of deleting book:     ");
	long int ID = inputPosLong();

	int del;
	for(int i = 0; i < *size; i++)
		if(ID == (catalog + i)->id)
		{
			del = i;
			break;
		}

	for(int j = del; j < *size-1; j++)
		*(catalog + j) = *(catalog + j + 1);

	(*size)--;
	catalog = (books*)realloc(catalog, (*size)*sizeof(books));
	printf("\nPress ENTER to continue...");
	getch();
}

void toBin(char *str, FILE *f)
{
    //char text[255];
    //s_gets(text, 255);
    int i = 0;
    while(str[i] != '\0')
    {
        fwrite(&str[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&str[i], sizeof(char), 1, f);
}

void fromBin(char *str, FILE *f)
{
    // char *text;
    // text = (char*)malloc(1);
    //fseek(f, 0, SEEK_SET);
    int i = 0;
    while(str[i-1] != '\0') 
    {
        fread(&str[i], sizeof(char), 1, f);
        //text = (char*)realloc(text, i+2);
        i++;
    }
    // if(text[i-1]=='\0')
    //     printf("YEEEEES\n");
    //free(text);
    //printf("%s\n", text);
}

int saveToFile(books *catalog, int *size, char *name)
{
	FILE *f;
	f = fopen(name, "w+t");

	if(f == NULL)	return 0;

	if(fwrite(size, sizeof(int), 1, f) != 1)	return 0;

	for(int i = 0; i < *size; i++)
	{
		printf("Save %d book...\n", i+1);
		if(fwrite(catalog+i, sizeof(books), 1, f) != 1)	return 0;
	}
	if(fclose(f) != 0)	return 0;
	printf("Press ENTER to exit...\n");
	getch();
	return 1;
}

void saveError(books *catalog, int *size, char *name)
{
	if(saveToFile(catalog, size, name) == 0)	printf("Somthing gets wrong\n");
}

int readFromFile(books *catalog, int *size, char *name)
{
	FILE *f;
	f = fopen(name, "rt");
	int file;

	if(f == NULL)	return 0;

	if(fread(&file, sizeof(int), 1, f) != 1)	return 0;

	catalog = (books*)realloc(catalog, (*size + file)*sizeof(books));
	
	for(int i = 0; i < file; i++)
	{
		printf("Read %d book...\n", i+1);
		if(fread((catalog + *size + i), sizeof(books), 1, f) != 1)	return 0;
	}
	if(fclose(f) != 0)	return 0;
	*size += file; 
	printf("Press ENTER to exit...\n");
	getch();
	return 1;
}

void readError(books *catalog, int *size, char *name)
{
	if(readFromFile(catalog, size, name) == 0)	printf("Somthing gets wrong\n");
}

// void readStruct(books *catalog, int i, FILE *f)
// {
// 	printf("struct %d - %d\n", i+1, fread(catalog+i, sizeof(books), 1, f));
// 	// printf("id %d\n", fread(&((catalog + i)->id), sizeof(long int), 1, f));
// 	// printf("name %d\n", fread(&((catalog + i)->name), sizeof(char), 255, f));
// 	// // fromBin((catalog + i)->name, f);
// 	// printf("day %d\n", fread(&((catalog + i)->creation.day), sizeof(int), 1, f));
// 	// printf("month %d\n", (&((catalog + i)->creation.month), sizeof(int), 1, f));
// 	// printf("year %d\n", fread(&((catalog + i)->creation.year), sizeof(int), 1, f));
// 	// printf("author %d\n", fread(&((catalog + i)->author), sizeof(char), 255, f));
// 	// // fromBin((catalog + i)->author, f);
// 	// printf("pop %d\n", fread(&((catalog + i)->pop), sizeof(long int), 1, f));
// }

// void readFromFile(books *catalog, int *size, char *name)
// {
// 	FILE *f;
// 	f = fopen(name, "rb");
// 	int file;
// 	printf("size %d\n",fread(&file, sizeof(int), 1, f));
// 	catalog = (books*)realloc(catalog, (*size+file)*sizeof(books));
// 	for(int i = 0; i < file; i++)
// 	{
// 		printf("\nRead %d book...\n", i+1);
// 		readStruct(catalog, *size+i, f);
// 	}
// 	printf("close %d\n", fclose(f));
// 	*size += file;
// 	printf("Press ENTER to continue...");
// 	getch();
// }

// void saveStruct(books *catalog, int i, FILE *f)
// {
// 	printf("struct %d - %d\n", i+1, fwrite(catalog+i, sizeof(books), 1, f));
// 	// printf("id %d\n", fwrite(&((catalog + i)->id), sizeof(long int), 1, f));
// 	// printf("name %d\n", fwrite(&((catalog + i)->name), sizeof(char), 255, f));
// 	// //toBin((catalog + i)->name, f);
// 	// printf("day %d\n", fwrite(&((catalog + i)->creation.day), sizeof(int), 1, f));
// 	// printf("month %d\n", fwrite(&((catalog + i)->creation.month), sizeof(int), 1, f));
// 	// printf("year %d\n", fwrite(&((catalog + i)->creation.year), sizeof(int), 1, f));
// 	// printf("author %d\n", fwrite(&((catalog + i)->author), sizeof(char), 255, f));
// 	// //toBin((catalog + i)->author, f);
// 	// printf("pop %d\n",fwrite(&((catalog + i)->pop), sizeof(long int), 1, f));
// }

// void saveToFile(books *catalog, int *size, char *name)
// {
// 	FILE *f;
// 	f = fopen(name, "r+b");
// 	printf("size %d\n", fwrite(size, sizeof(int), 1, f));
// 	for(int i = 0; i < *size; i++)
// 	{
// 		printf("Save %d book...\n", i+1);
// 		saveStruct(catalog, i, f);
// 	}
// 	printf("close %d\n", fclose(f));
// 	printf("Press ENTER to exit...");
// 	getch();
// }

enum Choose 
{
	new_arr = 1,
	from_file,
	add_record,
	print,
	delete,
	change,
	sort,
	stop,
};
typedef enum Choose choosing;

int main()
{
	choosing command;
	books *catalog;
	int defolt_size = 0;
	int *size = &defolt_size;
	catalog = (books*)malloc(1*sizeof(books));

	char binname[25];
	while(1)
	{
		//system("CLS");
		printf("\tWhat do you want to do?\n\
\t1 - make new catalog of books\n\
\t2 - read new catalog or add books from binary file\n\
\t3 - add new book\n\
\t4 - print existing catalog\n\
\t5 - delete book\n\
\t6 - change information about book\n\
\t7 - sort catalog by author or popularity\n\
\t8 - save catalog to file and exit the program\n\n\
\tyour choose: ");
		command = inputPosInt();
		switch(command)
		{
			case new_arr:
			{
				//system("CLS");
				newArrStruct(catalog, size);
				break;
			}
			case from_file:
			{	
				printf("Enter the name of bin file: ");
				s_gets(binname, 25); 
				readError(catalog, size, binname);
				//readFromFile(catalog, size, binname);
				break;
			}
			case add_record:
			{
				//system("CLS");
				addStruct(catalog, size);
				break;
			}
			case print:
			{
				//system("CLS");
				printStruct(catalog, size);
				break;
			}
			case delete:
			{
				delStruct(catalog, size);
				break;
			}
			case change:
			{
				break;
			}
			case sort:
			{
				exit(0);
				break;
			}
			case stop:
			{
				//saving
				//system("CLS");
				
				printf("Enter the name of bin file: ");
				s_gets(binname, 25); 
				//saveToFile(catalog, size, binname);
				saveError(catalog, size, binname);
				*size = 0;
				books *newcat = (books*)malloc(sizeof(books));
				//readFromFile(catalog, size, binname);
				readError(newcat, size, binname);
				printStruct(newcat, size);
				//exit(0);
				break;
			}
			default: 
			{
				printf("Something gets wrong, try again");
				break;
			}
		} 
	}
	getch();
	return 0;
}