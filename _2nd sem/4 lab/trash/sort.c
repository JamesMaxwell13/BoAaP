#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcs.h"

// Реализовать операцию взятия остатка от деления на число используя битовые поля.
// Число передается через командную строку. Реализовать функции поиска и
// сортировки информации по одному из новых свойств.

// Использование встроенных/самописных динамических структур данных. Включая
// функции сортировки, поиска и тд.

// Обосновать выбор динамической структуры данных. Создание .log файлов

// Библиотека. Содержаться данные о книгах — id, название, год издания, автор,
// популярность(сколько раз читали).
// + Информация о книге дополнительно может содержать одно из трех свойств: жанр, тираж,
// рекомендуемый возраст. При входе запрашивать возраст пользователя. Создать функцию,
// которая будет рекомендовать к прочтению книги(возраст не должен совпадать полностью).


typedef struct Date
{
	int day;
	int month;
	int year;
} date;

typedef union Info
{
	char genre[255];
	long edition;
	int age;
} info;

typedef struct Book
{
	long int id;
	char name[255];
	date creation;
	char author[255];
	long int popular;
	int uni;
	info property;
} books;

typedef struct list
{
	struct list *next;
	books data;
} node;

books getBook();


node *pushQ(node **head, books newdata)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = newdata;
	temp->next = NULL;

	if(*head == NULL)
		*head = temp;
	else
	{
		(*head)->next = temp;
		*head = temp;
	}
	return *head;
}

node *popQ(node **tail)
{
	if(*tail != NULL)
	{
		node *out;
		out = *tail;
		*tail = (*tail)->next;
		return out;
	}
	else
		return NULL;
}

node *getNth(node *tail, int N)
{
	node *Nth;
	int i = 0;
	Nth = tail;
	while((i < N) && (Nth != NULL))
	{
		Nth = Nth->next;
		i++;
	}
	return Nth;
}

node *delNth(node **tail, int N)
{
	if(N == 0)
		return popQ(tail);
	else
	{
		node *prev = getNth(*tail, N-1);
		node *Nth = prev->next;
			prev->next = Nth->next;
		return Nth;
	}
}

node *swap(node **tail, int N1, int N2)
{
	if(N1 > N2)
	{
		int tmp = N1;
		N1 = N2;
		N2 = tmp;
	}

	if(N1 == N2)
		return *tail;

	node *Nth1, *Nth2, *temp;
	node *prev1, *prev2;
	Nth1 = getNth(*tail, N1);
	Nth2 = getNth(*tail, N2);
	if(Nth1 == NULL || Nth2 == NULL)
		return *tail;

	if(N2-N1 == 1)
	{
		if(N1 == 0)
		{
			Nth1->next = Nth2->next;
			Nth2->next = Nth1;
			(*tail) = Nth2;
		}
		else
		{
			prev1 = getNth(*tail, N1-1);
			Nth1->next = Nth2->next;
			Nth2->next = Nth1;
			prev1->next = Nth2;
		}
	}
	else
	{
		prev2 = getNth(*tail, N2-1);
		temp = Nth1->next;
		Nth1->next = Nth2->next;
		Nth2->next = temp;
		prev2->next = Nth1;
	
		if(N1 != 0)
		{
			prev1 = getNth(*tail, N1-1);
			prev1->next = Nth2;
		}
		else
			(*tail) = Nth2;
	}
	return *tail;
}



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

info getUnion(int *unio)
{
	info property;
	printf("Which extra field do you want to fill?\n");
	printf("\t1 - genre of book\n\
\t2 - edition\n\
\t3 - recomendation age to read\n\
\tyour choise:\t");

	do
	{
		*unio = inputPosInt();
		switch(*unio)
		{
			case 1:
			{
				printf("Enter the genre of book:        ");
				s_gets(property.genre, 255);
				break;
			}
			case 2:
			{
				printf("Enter edition of this book:     ");
				property.edition = inputPosLong();
				break;
			}
			case 3: 
			{
				printf("Enter the recomendation age:    ");
				do
				{
					property.age = inputPos_Null();
					if(property.age > 18)
						printf("Usually max age is 18, enter age again\n");
				} 
				while(property.age > 18);
				break;
			}
			default: printf("Wrong input\n");
		}
	}
	while(*unio > 3);

	return property;
}

books getBook()
{
	books exemplar;
	printf("Enter ID of the book:          ");
	exemplar.id = inputPosLong();

	printf("Enter the name of this book:   ");
	s_gets(exemplar.name, 255);

	printf("\nChoose the date of creation this book:\n");
	exemplar.creation = getDate();

	printf("\nEnter the name of author:      ");
	s_gets(exemplar.author, 255);

	printf("Enter the popularity of book:  ");
	exemplar.popular = inputPosLong();

	int *p = &(exemplar.uni);
	exemplar.property = getUnion(p);

	return exemplar;
}

node *getCatalog(int *size, node *tail, node *head)
{
	books buff;
	printf("Choose number of records:      ");
	*size = inputPosInt();

	printf("_______________________________\n");
	printf("BOOK #%d\n", 1);

	buff = getBook();
	tail = pushQ(&head, buff);

	for(int i = 1; i < *size; i++)
	{
		printf("_______________________________\n");
		printf("BOOK #%d\n", i+1);
		buff = getBook();
		head = pushQ(&head, buff);
	}
	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

void printUnion(info property, int uni)
{
	switch(uni)
	{
		case 1: 
		{
			printf("genre:");
			print25(property.genre);
			printf("\n");
			break;
		}
		case 2:
		{
			printf("        edition:     ");
			printf("%.6ld      |\n", property.edition);
			break;
		}
		case 3: 
		{
			printf("     recomend. age:   ");
			printf("%6d     |\n", property.age);
			break;
		}
	}
}

void printBook(books exemplar)
{
	printf("____________________________________________________________________________________________________________________________\n");
	printf("| %.8ld |", exemplar.id);
	print25(exemplar.name);
	printf(" %.2d.%.2d.%.4d |", exemplar.creation.day, exemplar.creation.month, exemplar.creation.year);
	print25(exemplar.author);
	printf(" %6ld |", exemplar.popular);
	printUnion(exemplar.property, exemplar.uni);
}

node *printCatalog(int *size, node *tail)
{
	node *temp;
	if(*size == 0)
		printf("At first fill the catalog\n");
	else
	{	
		printf("____________________________________________________________________________________________________________________________\n");
		printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|        EXTRA INFORMATION        |\n");
		for(int i = 0; i < *size; i++)
		{
			temp = getNth(tail, i);
			printBook(temp->data);
		}
	printf("____________________________________________________________________________________________________________________________\n");
	}
	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

node *delBook(int *size, node *tail)
{
	node *tmp;
	printf("Enter the ID of deleting book:     ");
	long int ID = inputPosLong();
	printf("Enter the popularity of deleting book: ");
	long int pop = inputPosLong();

	int del = -1;
	for(int i = 0; i < *size; i++)
	{
		tmp = getNth(tail, i); 
		if(ID == tmp->data.id && pop == tmp->data.popular)
		{
			del = i;
			break;
		}
	}

	if(del != -1 && (delNth(&tail, del) != NULL))
	{
		printf("Deleted succesfully!\n");
		(*size)--;
	}
	else
		printf("Something gets wrong\n");

	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}



typedef enum Field
{
	id = 1,
	name,
	datee,
	author,
	pop,
	genre,
	edition,
	age,
} poke;

int compDate(node *ti, node *tj)
{
	if((ti->data.creation.year == tj->data.creation.year) &&
	 (ti->data.creation.month == tj->data.creation.month) && 
	 (ti->data.creation.day == tj->data.creation.day))
			return 0;
	else
		if(ti->data.creation.year > tj->data.creation.year)
			return 1;
		else
			if(ti->data.creation.month > tj->data.creation.month)
				return 1;
			else
				if(ti->data.creation.day > tj->data.creation.day)
					return 1;
				else 
					return 2;
}

int condition(node *tail, int field[5], int k, int i, int j)
{
	node *ti, *tj;
	ti = getNth(tail, i);
	tj = getNth(tail, j);
	poke sortf = field[k];
	switch (sortf)
	{
	case id:
	{
		if(ti->data.id > tj->data.id)
			return 1;
		else
			if(ti->data.id == tj->data.id)
				return 0;
			else
				return 2;
	}
	case name:
	{
		if(strCmp(ti->data.name, tj->data.name) > 0)
			return 1;
		else
			if(strCmp(ti->data.name, tj->data.name) == 0)
				return 0;
			else
				return 2;
	}
	case datee:
	{
		return compDate(ti, tj);
	}
	case author:
	{
		if(strCmp(ti->data.author, tj->data.author) > 0)
			return 1;
		else
			if(strCmp(ti->data.author, tj->data.author) == 0)
				return 0;
			else
				return 2;
	}
	case pop:
	{
		if(ti->data.popular > tj->data.popular)
			return 1;
		else
			if(ti->data.popular == tj->data.popular)
				return 0;
			else
				return 2;
	}
	case genre:
	{
		if((tj->data.uni != 1 && ti->data.uni != 1) ||
		strCmp(ti->data.property.genre, tj->data.property.genre) == 0)
			return 0;
		else
			if((strCmp(ti->data.property.genre, tj->data.property.genre) > 0) || (ti->data.uni != 1 && tj->data.uni == 1))
				return 1;
			else
				return 2;
	}
	case edition:
	{
		if((tj->data.uni != 2 && ti->data.uni != 2) ||
		ti->data.property.edition == tj->data.property.edition)
			return 0;
		else
			if((ti->data.property.edition > tj->data.property.edition) || (ti->data.uni != 2 && tj->data.uni == 2))
				return 1;
			else
				return 2;
	}
	case age:
	{
		if((tj->data.uni != 3 && ti->data.uni != 3) ||
		ti->data.property.age == tj->data.property.age)
			return 0;
		else
			if((ti->data.property.age > tj->data.property.age) || (ti->data.uni != 3 && tj->data.uni == 3))
				return 1;
			else
				return 2;
	}
	default:
		printf("Something gets wrong...\n");
		break;
	}
	return 0;
}

node *comparison(node *tail, int field[5], int k, int i, int j)
{
	if(field[k] != 0 && k < 8)
	{
		if(condition(tail, field, k, i, j) == 1)
			tail = swap(&tail, i, j);
		else
			if(condition(tail, field, k, i, j) == 0 && field[k] != 0 && k < 8)
			{	
				k++;
				tail = comparison(tail, field, k, i, j);
			}
	}
	return tail;
}

node *sortStruct(int *size, node *tail, int field[5])
{
	int k = 0;
	for(int j = 1; j < *size; j++)
		for(int i = 0; i < *size - 1; i++)
			tail = comparison(tail, field, k, i, i+1);

	return tail;
}

node *sorting(int *size, node *tail)
{
	printf("Enter the subsequence of sorting fields:\n\
\t1 - ID of book\n\
\t2 - name\n\
\t3 - date\n\
\t4 - author\n\
\t5 - popularity\n\
\t6 - genre\n\
\t7 - edition\n\
\t8 - age\n\
After last subsequence enter 0\n");
	int field[6];
	for(int i = 0; i < 6; i++)
	{
		do
		{
			printf("...");
			field[i] = inputPos_Null();
			if(field[i] > 8)
				printf("Wrong input\n");
		} 
		while (field[i] > 8);

		if(field[i] == 0)
			break;
	}
	tail = sortStruct(size, tail, field);
	return tail;
}


int loadError(books *catalog, int *size, char name[])
{
	FILE *f;
	f = fopen(name, "wb");

	if(f == NULL)	return 0;

	if(fwrite(size, sizeof(int), 1, f) != 1)	return 0;

	if((int)fwrite(catalog, sizeof(books), *size, f) != *size)	return 0;

	if(fclose(f) != 0)	return 0;

	return 1;
}

node *loadStruct(node *tail, int *size, char name[])
{
	books *catalog = (books*)malloc((*size)*sizeof(books));
	for(int i = 0; i < *size; i++)
		*(catalog + i) = (getNth(tail, i))->data;  

	if(loadError(catalog, size, name) == 0)
		printf("Something gets wrong...\n");
	else
		printf("Catalog loaded successfully!\n");

	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

int readError(books *catalog, int *size, char name[])
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

node *readStruct(node *tail, int *size, node *head, char name[])
{
	books *newcat = (books*)malloc(20*sizeof(books));
	if(readError(newcat, size, name) == 0)
		printf("Something gets wrong...\n");
	else
		printf("Catalog readed successfully!\n");

	tail = pushQ(&head, *newcat);

	for(int i = 1; i < *size; i++)
		head = pushQ(&head, *(newcat + i));

	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

node *recomendBooks(node *tail, int *size, int age)
{
	int field[6];
	field[0] = 8;
	field[1] = 0;
	tail = sortStruct(size, tail, field);
	
	int Nage = -1, bufage = age;
	node *tmp;
	do
	{
		for(int i = 0; i < *size; i++)
		{
			tmp = getNth(tail, i); 
			if(tmp->data.uni == 3 && tmp->data.property.age == bufage)
			{
				Nage = i;
				break;
			}
		}
		bufage--;
	} 
	while(Nage == -1 && bufage >= 0);
	
	printf("There are some books recomended to you:\n");
	if(*size == 0)
		printf("At first fill the catalog\n");
	else
	{	
		printf("____________________________________________________________________________________________________________________________\n");
		printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|        EXTRA INFORMATION        |\n");
		for(int i = Nage - 1; i <= Nage + 1; i++)
		{
			tmp = getNth(tail, i);
			printBook(tmp->data);
		}
	printf("____________________________________________________________________________________________________________________________\n");
	}
	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

typedef enum Choose 
{
	new_queue = 1,
	from_file,
	print,
	delete,
	sort,
	recomend,
	stop,
} choosing;

int main()
{
	int command;
	int size = 0, *psize = &size;
	node *tail = NULL, *head = NULL;
	char binname[25];

	int age; 
	printf("\tEnter your age:\t");
	age = inputPos_Null();

	while(1)
	{
		//system("CLS");
		printf("\n\tWhat do you want to do?\n\
\t1 - make new catalog of books\n\
\t2 - read new catalog or add books from binary file\n\
\t3 - print existing catalog\n\
\t4 - delete book\n\
\t5 - sort catalog by some fields\n\
\t6 - take recomendation to read\n\
\t7 - save catalog to file and exit the program\n\n\
\tyour choose: ");
		command = inputPosInt();
		printf("\n");

		switch(command)
		{
			case new_queue:
			{
				tail = getCatalog(psize, tail, head);
				system("CLS");
				break;
			}
			case from_file:
			{	
				printf("Enter the name of bin file: ");
				s_gets(binname, 25); 
				tail = readStruct(tail, psize, head, binname);
				system("CLS");
				break;
			}
			case print:
			{
				tail = printCatalog(psize, tail);
				break;
			}
			case delete:
			{
				tail = delBook(psize, tail);
				system("CLS");
				break;
			}
			case sort:
			{
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

				printf("Sorted now...\n");
				tail = sortStruct(psize, tail, field);
				break;
			}
			case recomend:
			{
				tail = recomendBooks(tail, psize, age);
				system("CLS");
				break;
			}
			case stop:
			{
				printf("Enter the name of bin file: ");
				s_gets(binname, 25); 
				tail = loadStruct(tail, psize, binname);
				*psize = 0;
				free(tail);
				free(head);
				
				tail = NULL;
				head = NULL;
				int news = 0, *nsize = &news;
				tail = readStruct(tail, nsize, head, binname);
				free(tail);
				free(head);
				exit(0);
				break;
			}
			default: 
			{
				printf("Something gets wrong, try again");
				system("CLS");
				break;
			}
		} 
	}

	getch();
	return 0;
}