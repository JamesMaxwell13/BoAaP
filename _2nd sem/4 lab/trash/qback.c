#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcs.h"

typedef struct Queue
{
	int data;
	struct Queue *next;
} node;

struct info
{
	int size;
	struct Queue *tail;
	struct Queue *head;
};

node *push(node **head)
{
	node *temp = (node*)malloc(sizeof(node*));
	temp->data = inputInt();
	temp->next = NULL;

	if(*head == NULL)
		*head = temp;
	else
	{
		temp->next = *head;
		*head = temp;
	}
	return *head;
}

node *popHead(node **head)
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

node *popTail(node **tail, node **head)
{
	if(*tail != NULL)
	{
		node **temp, *out;
		*temp = *head;
		while(((*temp) != NULL) && ((*temp)->next != *tail))
			(*temp) = (*temp)->next;
		out = *tail;
		*tail = *temp;
		(*tail)->next = NULL;
		return out;
	}
	else
		return NULL;
}

node *getNth(node *head, int N)
{
	node *Nth;
	int i = 0;
	Nth = head;
	while((i < N) && (head != NULL))
	{
		Nth = Nth->next;
		i++;
	}
	return Nth;
}

node *delNth(node **head, int N)
{
	if(N == 0)
		return popHead(head);
	else
	{
		node *prev = getNth(*head, N-1);
		node *Nth = prev->next;
			prev->next = Nth->next;
		return Nth;
	}
}

int main()
{
	node *head = NULL, *tail;
	struct info queue;
	queue.size = 0;

	tail = push(&head);
	queue.size++;

	while(head->data != 0)
	{
		head = push(&head);
		queue.size++;
	}

	printf("\n");
	node *out;
	for(int i = queue.size-1; i >= 0; i--)
	{
		out = getNth(head, i);
		printf("%d\n", out->data);
	}

	getch();
	return 0;
}