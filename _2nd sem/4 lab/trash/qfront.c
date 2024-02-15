#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcs.h"

typedef struct list
{
	struct list *next;
	int data;
} node;

typedef struct Queue
{
	int size;
	struct list *tail;
	struct list *head;
} queue;

node *pushQ(node **head)
{
	node *temp = (node*)malloc(sizeof(node*));
	temp->data = inputInt();
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


void swappingNear(node **Nth1, node **Nth2, node **prev1)
{
	(*Nth1)->next = (*Nth2)->next;
	(*Nth2)->next = *Nth1;
	(*prev1)->next = *Nth2;
}

void swappingAny(node **Nth1, node **Nth2, node **prev1, node **prev2)
{
	node *temp;
	temp = (*Nth1)->next;
	(*Nth1)->next = (*Nth2)->next;
	(*Nth2)->next = temp;

	(*prev1)->next = *Nth2;
	(*prev2)->next = *Nth1;
}

void swap(node **tail, int N1, int N2)
{
	if(N1 > N2)
	{
		int tmp = N1;
		N1 = N2;
		N2 = tmp;
	}

	if(N1 == N2)
		return; //*tail;

	node *Nth1, *Nth2, *temp;
	node *prev1, *prev2;
	Nth1 = getNth(*tail, N1);
	Nth2 = getNth(*tail, N2);
	if(Nth1 == NULL || Nth2 == NULL)
		return; //*tail;

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
	//return *tail;
}


node *getNums(queue *info, node *tail, node *head)
{
	printf("amount: ");
	info->size = inputPosInt();

	tail = pushQ(&head);

	for(int i = 1; i < info->size; i++)
		head = pushQ(&head);
	printf("nums are added...\n");
	return tail;
}

node *printNums(queue *info, node *tail)
{
	printf("print...\n");
	node *tmp;
	for(int i = 0; i < info->size; i++)
	{
		tmp = getNth(tail, i);
		printf("%d   ", tmp->data);
	}
	printf("nums are printed\n");
	return tail;
}

node *sort(queue *info, node *tail)
{
	node *tmp1, *tmp2;
	for(int j = 1; j < info->size; j++)
		for(int i = 0; i < info->size - 1; i++)
		{
			tmp1 = getNth(tail, i);
			tmp2 = getNth(tail, j);
			if(tmp1->data > tmp2->data)
				swap(&tail, i, j);
			//printNums(info, tail);
		}
	return tail;
}

int main()
{
	node *head = NULL, *tail = NULL;
	queue *info = (queue*)malloc(sizeof(queue));
	tail = getNums(info, tail, head);

	tail = printNums(info, tail);
	tail = sort(info, tail);
	//tail = swap(&tail, 0, 2);
	// tail = printNums(info, tail);
	// tail = swap(&tail, 3, 4);
	tail = printNums(info, tail);
		
	getch();
	return 0;
}