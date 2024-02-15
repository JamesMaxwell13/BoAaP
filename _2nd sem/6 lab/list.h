#pragma once

#include "funcs.h"
#include "conio.h"


typedef struct list
{
	struct list *next;
	int data;
} node;


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
	if(N < 0)
		return NULL;
	else
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

node *popNth(node *tail, int data, int N)
{
	node *prev = getNth(tail, N-1);
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	if(N > 0)
	{
		temp->next = prev->next;
		prev->next = temp;
	}
	else
	{
		temp->next = tail;
		tail = temp;
	}
	return tail; 
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


node *sort(node *tail, int *size)
{
	printf("sorting list...\n");
	node *tmp1, *tmp2;
	for(int j = 1; j < *size; j++)
		for(int i = 0; i < *size - 1; i++)
		{
			tmp1 = getNth(tail, i);
			tmp2 = getNth(tail, j);
			if(tmp1->data > tmp2->data)
				swap(&tail, i, j);
		}
	return tail;
}