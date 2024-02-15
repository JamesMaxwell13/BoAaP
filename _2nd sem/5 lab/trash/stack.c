#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <string.h>
#include <conio.h>
#include <stdbool.h>

// Используя самописный стек, реализовать функции, решающие выданную задачу.
// Преобразование выражения из префиксной формы в постфиксную.

// typedef struct stack
// {
// 	int data;
// 	struct stack *next;
// } 
// node;


// node *push(node **head, int data)
// {
// 	node *tmp = (node*)malloc(sizeof(node));
// 	tmp->next = NULL;
// 	tmp->data = data;
// 	if(head == NULL)
// 		*head = tmp;
// 	else
// 	{
// 		tmp->next = *head;
// 		*head = tmp;
// 	}
// 	return *head;
// }


// node *pop(node **head)
// {
// 	if(head != NULL)
// 	{
// 		node *out;
// 		out = *head;
// 		*head = (*head) -> next;
// 		return out;
// 	}
// 	else
// 		return NULL;
// }

typedef struct stack
{
	char data[7];
	struct stack *next;
} 
node;

node *push(node **head, char data[])
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	strncpy(tmp->data, data, 7);

	if(head == NULL)
		*head = tmp;
	else
	{
		tmp->next = *head;
		*head = tmp;
	}
	return *head;
}

node *pop(node **head)
{
	if(head != NULL)
	{
		node *out;
		out = *head;
		*head = (*head) -> next;
		return out;
	}
	else
		return NULL;
}


int main()
{
	node *head = (node*)malloc(sizeof(node));
	head = NULL;
	node *out;

	printf("amount: ");
	int amount = inputPosInt();

	for(int i = 0; i < amount; i++)
	{
		// char symb;
		// scanf("%c", &symb);
		// char symb[7];
		// fgets(symb, 7, stdin);
		char *symb;
		symb = getStr();
		head = push(&head, symb);
		printf("pushed %s\n", head->data);
	}


	printf("\nprint\n");
	do
	{
		out = pop(&head);
		printf("poped %s\n", out->data);
	}
	while(head != NULL);

	getch();
	return 0;
}