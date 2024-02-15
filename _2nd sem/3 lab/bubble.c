#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// void print25(char *str)
// {
// 	if(strlen(str) <= 25)
// 		printf(" %25s |", str);
// 	else
// 	{
// 		printf(" ");
// 		for(int i = 0; i < 23; i++)
// 			putchar(str[i]);
// 		printf("...|");
// 	}
// }

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
			printf("| %8ld |", (catalog + i)->id);
			//printf(" %25s |", (catalog + i)->name);
			print25((catalog + i)->name);
			printf(" %.2d.%.2d.%.4d |", (catalog + i)->creation.day, (catalog + i)->creation.month, (catalog + i)->creation.year);
			print25((catalog + i)->author);
			printf(" %6ld |\n",(catalog + i)->pop);
		}
	printf("__________________________________________________________________________________________\n");
	}
	printf("\nPress ENTER to continue...");
	getch();
}

void initialization(books *cat, int *size)
{
	//1 book
	(cat)->id = 1;
	strncpy((cat)->name, "Harry Potter and The Philosophy Stone", 25);
	(cat)->creation.day = 26;
	(cat)->creation.month = 6;
	(cat)->creation.year = 1996;
	strncpy((cat)->author, "Joanne Rowling", 25);
	(cat)->pop = 120000;

	//2 book
	(cat+1)->id = 2;
	strncpy((cat+1)->name, "Harry Potter and The Chamber of Secret", 25);
	(cat+1)->creation.day = 2;
	(cat+1)->creation.month = 7;
	(cat+1)->creation.year = 1998;
	strncpy((cat+1)->author, "Joanne Rowling", 25);
	(cat+1)->pop = 130000;

	//3 book
	(cat+2)->id = 3;
	strncpy((cat+2)->name, "Harry Potter and The Prisoner of Azkaban", 25);
	(cat+2)->creation.day = 8;
	(cat+2)->creation.month = 7;
	(cat+2)->creation.year = 1999;
	strncpy((cat+2)->author, "Joanne Rowling", 25);
	(cat+2)->pop = 110000;
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
	books *newcat = malloc(10*sizeof(books));
	int news = 0, *nsize = &news;
	if(readError(newcat, nsize, name) == 0)
		printf("Something gets wrong...\n");
	else
		printf("Catalog readed successfully!\n");
	for(int i = 0; i < *nsize; i++)
		*(catalog + *size +i) = *(newcat + i);
	*size += *nsize; 
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
	//*min = j; 
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

//void selectionSort(int *arr,int size)
// {
//     int buff;
//     int min;
//     for(int i=0;i<size-1; i++) // выбор иѝходного ѝлемента к ѝравнению
//     { 
//         min=i; 
//         for(int j=i+1; j<size; j++) // проѝмотр маѝѝива ”ѝнизу” ”вверх”
//             if(arr[min]>arr[j]) 
//                 min=j; // фикѝируем координату ѝлемента в маѝѝиве
//                 buff=arr[i]; // замена min и i ѝлементов
//                 arr[i]=arr[min];
//                 arr[min]=buff;
//     }
// }

void sortStruct(books *catalog, int *size, int field[5])
{
	printf("Sorted now...\n");
	int k = 0;
	for(int j = 1; j < *size; j++)
		for(int i = 0; i < *size - 1; i++)
			comparison(catalog, field, k, i, j );
	printStruct(catalog, size);
	// printf("\nPress ENTER to continue...\n");
	// getch();
}

// int m, *min = &m;
	// int k = 0;
	// // m = 2;
	// // comparison(catalog, field, k, min, 2, 3 );
	// for(int i = 0; i < *size - 1; i++) 
    // { 
	// 	m = i; 
    //     for(int j = i + 1; j < *size; j++) 
	// 		comparison(catalog, field, k, min, i, j );		
    // }



int main()
{
	int defolt = 0, *size = &defolt;

	*size = 0;
	books *cat;
	cat = (books*)malloc(10*sizeof(books));

	//initialization(cat, size);
	//printStruct(cat, size);
	char name[25];
	printf("Enter name of file:\t");
	s_gets(name, 25);
	// readStruct(cat, size, name);
	// printStruct(cat, size);
	// printf("\n%d\n", *size);
	readStruct(cat, size, name);
	printStruct(cat, size);
	printf("\n%d\n", *size);

	printf("Enter the subsequence of sorting fields:\n\
\t1 - ID of book\n\
\t2 - name\n\
\t3 - date\n\
\t4 - author\n\
\t5 - popularity\n\
After last subsequence enter 0\n");
int field[5];
for(int i = 0; i < 5; i++)
{
	do
	{
		printf("...");
		if((field[i] = inputInt()) > 5 && field[i] < 0)
			printf("Wrong input\n");
	} while (field[i] > 5 && field[i] < 0);
	if(field[i] == 0)
		break;
}

sortStruct(cat, size, field);

	// loadStruct(cat, size, name);

	// books *newcat;
	// newcat = (books*)malloc((*size)*sizeof(books));

	// int new = 0, *num = &new;
	// readStruct(newcat, num, name);
	// printStruct(newcat, num);

	getch();
	return 0; 
}