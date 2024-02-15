#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcs.h"

typedef struct List
{
	struct List *next;
	int data;
} list;


list *push(list **head)
{
	list *temp = (list*)malloc(sizeof(list));
	temp->data = inputInt();
	temp->next = NULL;

	if(*head == NULL) 
		(*head) = temp;
	else
	{
		temp->next = (*head);
		(*head) = temp;
	}
	return *head;
}

list *pop(list **head)
{
	if((*head) != NULL)
	{
		list *out = (*head);
		(*head) = (*head)->next;
		return out;
	}
	else
		return NULL;
}

list *getNth(list *head, int N)
{
	int count = 0;
	while(count < N && head)
	{
		head = head->next;
		count++;
	}
	return head;
}

void delNth(list **head, int N)
{
	if(N == 0)
		pop(head);
	else
	{
		list *prev = getNth(*head, N-1);
		list *del = prev->next;
		prev->next = del->next;
		free(del);
	}
}


int main()
{
	list *head;
	list *tail;
	list *out;

	tail = push(&head);

	for(int i = 0; i < 7; i++)
		tail = push(&tail);

	printf("\n");
	for(int i = 0; i < 8; i++)
	{
		printf("%d  ", getNth(tail, i)->data);	
	}

	getch();
	return 0;
}

// typedef union Info
// {
// 	char genre[255];
// 	long edition;
// 	int age;
// } info;


// int getUnionSwitch(info property)
// {
// 	int unio;
// 	printf("Which extra field do you want to fill?\n");
// 	printf("\t1 - genre of book\n\
// \t2 - edition\n\
// \t3 - recomendation age to read\n\
// \tyour choise:\t");

// 	do
// 	{
// 		unio = inputPosInt();
// 		switch(unio)
// 		{
// 			case 1:
// 			{
// 				printf("Enter the genre of book:        ");
// 				s_gets(property.genre, 255);
// 				break;
// 			}
// 			case 2:
// 			{
// 				printf("Enter edition of this book:     ");
// 				property.edition = inputPosLong();
// 				break;
// 			}
// 			case 3: 
// 			{
// 				printf("Enter the recomendation age:    ");
// 				property.age = inputPos_Null();
// 				break;
// 			}
// 			default: 
// 			{
// 				printf("Wrong input\n");
// 				break;
// 			}
// 		}
// 	}
// 	while(unio > 3);

// 	return unio;
// }


// info getUnion(info property, int *unio)
// {
// 	printf("Which extra field do you want to fill?\n");
// 	printf("\t1 - genre of book\n\
// \t2 - edition\n\
// \t3 - recomendation age to read\n\
// \tyour choise:\t");

// 	do
// 	{
// 		*unio = inputPosInt();
// 		switch(*unio)
// 		{
// 			case 1:
// 			{
// 				printf("Enter the genre of book:        ");
// 				s_gets(property.genre, 255);
// 				break;
// 			}
// 			case 2:
// 			{
// 				printf("Enter edition of this book:     ");
// 				property.edition = inputPosLong();
// 				break;
// 			}
// 			case 3: 
// 			{
// 				printf("Enter the recomendation age:    ");
// 				property.age = inputPos_Null();
// 				break;
// 			}
// 			default: 
// 			{
// 				printf("Wrong input\n");
// 				break;
// 			}
// 		}
// 	}
// 	while(*unio > 3);


// 	return property;
// }


// void printUnion(info property, int uni)
// {
// 	switch(uni)
// 	{
// 		case 1: 
// 		{
// 			printf("genre:");
// 			print25(property.genre);
// 			break;
// 		}
// 		case 2:
// 		{
// 			printf("    edition: ");
// 			printf("%6ld    |\n", property.edition);
// 			break;
// 		}
// 		case 3: 
// 		{
// 			printf(" recomend. age: ");
// 			printf("%6d |\n", property.age);
// 			break;
// 		}
// 	}
// }
