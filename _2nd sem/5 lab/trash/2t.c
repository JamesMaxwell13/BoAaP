#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include <conio.h>
#include <string.h>
#include <stdbool.h>

// Используя самописный стек, реализовать функции, решающие выданную задачу.
// Преобразование выражения из префиксной формы в постфиксную.

typedef struct stack
{
	char data[10];
	struct stack *next;
} 
node;

node *push(node **head, char data[])
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	strncpy(tmp->data, data, 10);

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

//считаем длину выражения
int expLen(char *exp)
{
	int i = 0;
	while(exp[i] != '=')
		i++;
	return i++;
}

//просматриваем на неправильные символы
bool wasteExp(char *exp)
{
	for(int i = 0; i < expLen(exp); i++)
		if((exp[i] < '0' || exp[i] > '9') && (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '=' && exp[i] != ' '))
			return false;
	return true;
}

//считываем выражение с проверкой
void getExp(char exp[255])
{
	do
	{
		rewind(stdin);
		fgets(exp, 255, stdin);
		if(exp[expLen(exp)] != '=' || wasteExp(exp) == false)
			printf("Wrong input\n");
	} 
	while(exp[expLen(exp)] != '=' || wasteExp(exp) == false);
}

//раскидываем выражение в двумерный массив символов
node *separation(char *exp, char **snum, int len, node *head)
{
	int i = 0;
	int l = 0;
	int j = 0;
	bool put = false;

	while(i < len)
	{
		if(exp[i] != ' ')
		{
			if(exp[i] >= '0' && exp[i] <= '9')	//если символ == цифра, то кидаем в одну строку массива строк
				{
					*(snum + j) = (char*)realloc(*(snum + j), (l + 2)*sizeof(char*));
					snum[j][l++] = exp[i];
					put = true;
				}
			else	//если символ подряд, то в snum +символ и некст строка
				{
					snum[j][0] = exp[i];
					snum[j][1] = '\0';
					head = push(&head, snum[j]);
					printf("pushed %s\n", head->data);
					j++;
					put = false;
				}
		}
		else 
			if(put == true)		//если число закончилось, то записываем конец строки и идем на новую строку
			{
				snum[j][l++] = '\0';
				head = push(&head, snum[j]);
				printf("pushed %s\n", head->data);
				put = false;
				l = 0;
				j++;
			}
		i++;
	}

	//чистим память
	for(int k = 0; k < len; k++)	
		free(*(snum+k));
	free(snum);

	return head;
}


int main()
{
	// int nums[255];
	// char exp[255], sign[255];
	// getExp(exp);
	// int len = expLen(exp);

	// char **snum = (char**)malloc(len*sizeof(char*));
	// for(int k = 0; k < len; k++)
	// 	*(snum + k) = (char*)malloc(1);
	// int lens = separation(exp, snum, len);


	printf("Number: ");
	char exp[255];
	getExp(exp);
	int len = expLen(exp);

	node *head = (node*)malloc(sizeof(node));
	head = NULL;
	node *out;

	char **snum = (char**)malloc(len*sizeof(char*));
	for(int k = 0; k < len; k++)
		*(snum + k) = (char*)malloc(2);
	head = separation(exp, snum, len, head);
	

	printf("\nprint // %s\n", head->data);
	do
	{
		out = pop(&head);
		printf("aboba %s ", out->data);
		free(out);
	}
	while(head != NULL);

	getch();
	return 0;
}
