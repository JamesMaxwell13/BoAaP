#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <string.h>
#include "funcs.h"

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
		if(D.month == 2 && D.day > 28)
			printf("In February can't be more than 28 days\n");
	}
	while((D.month > 12) || (D.day > 28 && D.month == 2));
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
	printf("\nPress ENTER to continue...\n");
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
	printf("\nPress ENTER to continue...\n");
	getch();
}

void printBook(books *catalog, int i)
{
	printf("__________________________________________________________________________________________\n");
	printf("| %.8ld |", (catalog + i)->id);
	//printf(" %25s |", (catalog + i)->name);
	print25((catalog + i)->name);
	printf(" %.2d.%.2d.%.4d |", (catalog + i)->creation.day, (catalog + i)->creation.month, (catalog + i)->creation.year);
	//printf(" %25s |", (catalog + i)->author);
	print25((catalog + i)->author);
	printf(" %6ld |\n",(catalog + i)->pop);
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
			printBook(catalog, i);
	printf("__________________________________________________________________________________________\n");
	}
	printf("\nPress ENTER to continue...\n");
	getch();
}

void delStruct(books *catalog, int *size)
{
	printf("Enter the ID of deleting book:     ");
	long int ID = inputPosLong();
	printf("Enter the popularity of deleting book: ");
	long int pop = inputPosLong();

	int del = -1;
	for(int i = 0; i < *size; i++)
		if(ID == (catalog + i)->id && pop == (catalog + i)->pop)
		{
			del = i;
			break;
		}

	if(del != -1)
	{
		for(int j = del; j < *size-1; j++)
			*(catalog + j) = *(catalog + j + 1);

		(*size)--;
		catalog = (books*)realloc(catalog, (*size)*sizeof(books));
		printf("Deleted succesfully!\n");
	}
	else
		printf("There is no such book\n");
	printf("\nPress ENTER to continue...\n");
	getch();
}

void changeStruct(books *catalog, int *size)
{
	printf("Enter the ID of changing book: ");
	long int ID = inputPosLong();
	printf("Enter the popularity of changing book: ");
	long int pop = inputPosLong();


	int chg = -1;
	for(int i = 0; i < *size; i++)
		if(ID == (catalog + i)->id && pop == (catalog + i)->pop)
		{
			chg = i;
			break;
		}
	
	if(chg != -1)
	{
		printf("__________________________________________________________________________________________\n");
		printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|\n");
		printBook(catalog, chg);
		printf("__________________________________________________________________________________________\n");

		printf("\nEnter 1 to change the field or 2 for skip\n");
		printf("Change ID?                     ");
		int edit = 3;
		while(edit > 2)
		{
			edit = inputPosInt();
			if(edit == 2)
				break;
			if(edit == 1)
				{
					printf("Enter ID of %d book:            ", chg+1);
					(catalog + chg)->id = inputPosLong();
					break;
				}
			else
				printf("Wrong input\n");
		}

		printf("Change the book name?          ");
		edit = 3;
		while(edit > 2)
		{
			edit = inputPosInt();
			if(edit == 2)
				break;
			if(edit == 1)
				{
					printf("Enter the name of this book:   ");
					s_gets((catalog + chg)->name, 255);
					break;
				}
			else
				printf("Wrong input\n");
		}

		printf("Change the creation date?      ");
		edit = 3;
		while(edit > 2)
		{
			edit = inputPosInt();
			if(edit == 2)
				break;
			if(edit == 1)
				{
					printf("\nChoose the date of creation this book:\n");
					(catalog + chg)->creation = getDate();
					break;
				}
			else
				printf("Wrong input\n");
		}

		printf("Change the author name?        ");
		edit = 3;
		while(edit > 2)
		{
			edit = inputPosInt();
			if(edit == 2)
				break;
			if(edit == 1)
				{
					printf("\nEnter the name of author:      ");
					s_gets((catalog + chg)->author, 255);
					break;
				}
			else
				printf("Wrong input\n");
		}

		printf("Change the popularity of book? ");
		edit = 3;
		while(edit > 2)
		{
			edit = inputPosInt();
			if(edit == 2)
				break;
			if(edit == 1)
				{
					printf("Enter the popularity of book:  ");
					(catalog + chg)->pop = inputPosLong();
					break;
				}
			else
				printf("Wrong input\n");
		}
	}
	else
		printf("There is no such book\n");
	printf("\nPress ENTER to continue...\n");
	getch();
}


enum Field
{
	id = 1,
	name,
	datee,
	author,
	pop,
};
typedef enum Field poke;

int compDate(books *catalog, int l, int m)
{
	if(((catalog + l)->creation.year == (catalog + m)->creation.year) &&
	 ((catalog + l)->creation.month == (catalog + m)->creation.month) && 
	 ((catalog + l)->creation.day == (catalog + m)->creation.day))
			return 0;
	else
		if((catalog + l)->creation.year > (catalog + m)->creation.year)
			return 1;
		else
			if((catalog + l)->creation.month > (catalog + m)->creation.month)
				return 1;
			else
				if((catalog + l)->creation.day > (catalog + m)->creation.day)
					return 1;
				else 
					return 2;
}

int condition(books *catalog, int field[5], int k, int i, int j)
{
	poke sortf = field[k];
	switch (sortf)
	{
	case id:
		if((catalog + i)->id > (catalog + j)->id)
			return 1;
		else
			if((catalog + i)->id == (catalog + j)->id)
				return 0;
			else
				return 2;
		break;

	case name:
		if(strCmp((catalog + i)->name, (catalog + j)->name) > 0)
			return 1;
		else
			if(strCmp((catalog + i)->name, (catalog + j)->name) == 0)
				return 0;
			else
				return 2;
		break;

	case datee:
		return compDate(catalog, i, j);
		break;

	case author:
		if(strCmp((catalog + i)->author, (catalog + j)->author) > 0)
			return 1;
		else
			if(strCmp((catalog + i)->author, (catalog + j)->author) == 0)
				return 0;
			else
				return 2;
		break;

	case pop:
		if((catalog + i)->pop > (catalog + j)->pop)
			return 1;
		else
			if((catalog + i)->pop == (catalog + j)->pop)
				return 0;
			else
				return 2;
		break;

	default:
		printf("Something gets wrong...\n");
		break;
	}
}

void swapStruct(books *catalog, int i, int j)
{
	books buff;
    buff = *(catalog + i);
    *(catalog + i) = *(catalog + j);
    *(catalog + j) = buff;
}

void comparison(books *catalog, int field[5], int k, int i, int j)
{
	if(field[k] != 0 && k < 5)
	{
		if(condition(catalog, field, k, i, j) == 1)
			swapStruct(catalog, i, j);
		else
			if(condition(catalog, field, k, i, j) == 0 && field[k] != 0 && k < 5)
			{	
				k++;
				comparison(catalog, field, k, i, j);
			}
	}
}

void sortStruct(books *catalog, int *size, int field[5])
{
	int k = 0;
	for(int j = 1; j < *size; j++)
		for(int i = 0; i < *size - 1; i++)
			comparison(catalog, field, k, i, j );
	// printf("\nPress ENTER to continue...\n");
	// getch();
}



void printPop(books *catalog, int *size)
{
	printf("Enter the number of most popular books:\t");
	int N = inputPosInt();
	int field[5] = {5, 0, 0, 0, 0};
	sortStruct(catalog, size, field);

	printf("__________________________________________________________________________________________\n");
	printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|\n");
	for(int i = 0; i < N; i++)
		printBook(catalog, i);
	printf("__________________________________________________________________________________________\n");	
	printf("\nPress ENTER to continue...\n");
	getch();
}

void printAuthor(books *catalog, int *size)
{
	printf("Enter the name of author which books you want to find:\t");
	char autor[255];
	s_gets(autor, 255);

	int field[5] = {4, 0, 0, 0, 0};
	sortStruct(catalog, size, field);

	int begin = -1;
	for(int i = 0; i < *size; i++)
		if(strCmp(autor, (catalog + i)->author) == 0)
			{
				begin = i;
				break;
			}

	if(begin != -1)
		{
			printf("__________________________________________________________________________________________\n");
			printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|\n");
			for(int j = begin; j < *size; j++)
				if(strCmp(autor, (catalog + j)->author) == 0)
					printBook(catalog, j);
				else
					break;
			printf("__________________________________________________________________________________________\n");
		}
	else
		printf("There is not this author and books\n");
	printf("\nPress ENTER to continue...\n");
	getch();
}

int loadError(books *catalog, int *size, char *name)
{
	FILE *f;
	f = fopen(name, "wb");

	if(f == NULL)	return 0;

	if(fwrite(size, sizeof(int), 1, f) != 1)	return 0;

	if(fwrite(catalog, sizeof(books), *size, f) != *size)	return 0;

	if(fclose(f) != 0)	return 0;

	return 1;
}

void loadStruct(books *catalog, int *size, char *name)
{
	if(loadError(catalog, size, name) == 0)
		printf("Something gets wrong...\n");
	else
		printf("Catalog loaded successfully!\n");

	printf("\nPress ENTER to continue...\n");
	getch();
}


int readError(books *catalog, int *size, char *name)
{
	FILE *f;
	f = fopen(name, "rb");

	if(f == NULL)	return 0;

	if((int)fread(size, sizeof(int), 1, f) != 1)	return 0;
	catalog = (books*)realloc(catalog, (*size)*sizeof(books));

	if((int)fread(catalog, sizeof(books), (long long unsigned int)*size, f) != *size)	return 0;

	if(fclose(f) != 0)	return 0;

	return 1;
}

void readStruct(books *catalog, int *size, char *name)
{
	books *newcat = (books*)malloc(20*sizeof(books));
	int news = 0, *nsize = &news;
	if(readError(newcat, nsize, name) == 0)
		printf("Something gets wrong...\n");
	else
		printf("Catalog readed successfully!\n");
	for(int i = 0; i < *nsize; i++)
		*(catalog + *size +i) = *(newcat + i);
	*size += *nsize; 
	printf("\nPress ENTER to continue...\n");
	getch();
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
	popular,
	authorrr,
	stop,
};
typedef enum Choose choosing;