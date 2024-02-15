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

void readStruct(books *catalog, int i, FILE *f)
{
	fread(&((catalog + i)->id), sizeof(long int), 1, f);
	fread(&((catalog + i)->name), sizeof(char), 255, f);
	fread(&((catalog + i)->creation.day), sizeof(int), 1, f);
	fread(&((catalog + i)->creation.month), sizeof(int), 1, f);
	fread(&((catalog + i)->creation.year), sizeof(int), 1, f);
	fread(&((catalog + i)->author), sizeof(char), 255, f);
	fread(&((catalog + i)->pop), sizeof(long int), 1, f);
}

void readFromFile(books *catalog, int *size, char *name)
{
	FILE *f;
	f = fopen(name, "rb");
	fread(size, sizeof(int), 1, f);
	catalog = (books*)realloc(catalog, (*size)*sizeof(books));
	for(int i = 0; i < *size; i++)
	{
		printf("Read %d book...\n", i+1);
		readStruct(catalog, i, f);
	}
	fclose(f);
}

void saveStruct(books *catalog, int i, FILE *f)
{
	fwrite(&((catalog + i)->id), sizeof(long int), 1, f);
	fwrite(&((catalog + i)->name), sizeof(char), 255, f);
	fwrite(&((catalog + i)->creation.day), sizeof(int), 1, f);
	fwrite(&((catalog + i)->creation.month), sizeof(int), 1, f);
	fwrite(&((catalog + i)->creation.year), sizeof(int), 1, f);
	fwrite(&((catalog + i)->author), sizeof(char), 255, f);
	fwrite(&((catalog + i)->pop), sizeof(long int), 1, f);
}

void saveToFile(books *catalog, int *size, char *name)
{
	FILE *f;
	f = fopen(name, "w+b");
	fwrite(size, sizeof(int), 1, f);
	for(int i = 0; i < *size; i++)
	{
		printf("Save %d book...", i+1);
		saveStruct(catalog, i, f);
	}
	printf("\n");
	fclose(f);
}

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
				readFromFile(catalog, size, binname);
				break;
			}
			case add_record:
			{
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
				break;
			}
			case change:
			{
				break;
			}
			case sort:
			{
				break;
			}
			case stop:
			{
				//saving
				//system("CLS");
				printf("Enter the name of bin file: ");
				s_gets(binname, 25); 
				saveToFile(catalog, size, binname);
				readFromFile(catalog, size, binname);
				printStruct(catalog, size);
				free(catalog);
				//exit(0);
				break;
			}
			case 9:
				exit(0);
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