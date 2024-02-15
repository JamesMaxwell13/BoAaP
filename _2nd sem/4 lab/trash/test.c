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

typedef struct Queue
{
	int size;
	struct list *tail;
	struct list *head;
} queue;

node *pushQ(node **head)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = getBook();
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

node *popQ(node *tail)
{
	if(tail != NULL)
	{
		node *out;
		out = tail;
		tail = tail->next;
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

node *delNth(node *tail, int N)
{
	if(N == 0)
		return popQ(tail);
	else
	{
		node *prev = getNth(tail, N-1);
		node *Nth = prev->next;
		prev->next = Nth->next;
		return Nth;
	}
}

void swap(node **tail, int N1, int N2)
{
	if(N1 > N2)
	{
		int tmp = N1;
		N1 = N2;
		N2 = tmp;
	}

	if(N1== N2)
		return;

	node *Nth1, *Nth2;
	node *prev1, *prev2;
	node *temp;

	Nth1 = getNth(*tail, N1);
	Nth2 = getNth(*tail, N2);
	prev1 = getNth(*tail, N1-1);
	prev2 = getNth(*tail, N2-1);

	if(N2-N1 == 1)
	{
		Nth1->next = Nth2->next;
		Nth2->next = Nth1;
		prev1->next = Nth2;
	}
	else
	{
		temp = Nth1->next;
		Nth1->next = Nth2->next;
		Nth2->next = temp;

		prev1->next = Nth2;
		prev2->next = Nth1;
	}
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
				property.age = inputPos_Null();
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
	s_gets(exemplar.author, 255);

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

void printUnion(info property, int uni)
{
	switch(uni)
	{
		case 1: 
		{
			printf("genre: ");
			print25(property.genre);
			printf("\n");
			break;
		}
		case 2:
		{
			printf("    edition: ");
			printf("%.6ld    |\n", property.edition);
			break;
		}
		case 3: 
		{
			printf(" recomend. age: ");
			printf("%6d |\n", property.age);
			break;
		}
	}
}

void printBook(books exemplar)
{
	printf("__________________________________________________________________________________________________________________________\n");
	printf("| %.8ld |", exemplar.id);
	print25(exemplar.name);
	printf(" %.2d.%.2d.%.4d |", exemplar.creation.day, exemplar.creation.month, exemplar.creation.year);
	print25(exemplar.author);
	printf(" %6ld |", exemplar.popular);
	printUnion(exemplar.property, exemplar.uni);
}

node *printCatalog(queue *inf, node *tail)
{
	node *temp;
	if(inf->size == 0)
		printf("At first fill the catalog\n");
	else
	{	
		printf("%d\n\n", inf->size);
		printf("__________________________________________________________________________________________________________________________\n");
		printf("|    ID    |         BOOK NAME         |  CR. DATE  |       AUTHOR OF BOOK      |POPULAR.|       EXTRA INFORMATION       |\n");
		for(int i = 0; i < inf->size; i++)
		{
			temp = getNth(tail, i);
			printBook(temp->data);
		}
	printf("__________________________________________________________________________________________________________________________\n");
	}
	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

node *getCatalog(queue *inf, node *tail, node *head)
{
	printf("Choose number of records:      ");
	inf->size = inputPosInt();

	printf("_______________________________\n");
	printf("BOOK #%d\n", 1);
	tail = pushQ(&head);
	// printf("tail %p\n", &tail);
	// node *temp;
	// temp = getNth(tail, 0);
	// printBook(temp->data);

	for(int i = 1; i < inf->size; i++)
	{
		printf("_______________________________\n");
		printf("BOOK #%d\n", i+1);
		head = pushQ(&head);
		// printf("h %p\n", &head);
		// temp = getNth(tail, i);
		// printBook(temp->data);
	}
	printf("\nPress ENTER to continue...\n");
	getch();
	return tail;
}

int main()
{
	queue *inf = (queue*)malloc(sizeof(queue));
	node *head = NULL, *tail = NULL;
	tail = getCatalog(inf, tail, head);
	tail = printCatalog(inf, tail);

	// printf("id - %ld", tail->data.id);
	// printBook(tail->data);
	// for(int i = 0; i < inf->size; i++)
	// {
	// 	temp = getNth(&tail, i);
	// 	printBook(tail->data);
	// }
	// printf("tail after get %p\n", &tail);
	// printCatalog(inf, tail);
	getch();
	return 0;
}