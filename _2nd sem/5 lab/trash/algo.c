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
	char data[256];
	struct stack *next;
} 
node;

node *push(node **head, char data[])
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	strncpy(tmp->data, data, 256);

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
		if((exp[i] < '0' || exp[i] > '9') && (exp[i] < 'a' || exp[i] > 'z') && (exp[i] < 'A' || exp[i] > 'Z') && (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '=' && exp[i] != ' '))
			return true;
	return false;
}

bool foptr(char *exp)
{
	if(exp[0] != '+' && exp[0] != '-' && exp[0] != '*' && exp[0] != '/')
		return false;
	return true;
}

//считываем выражение с проверкой
void getExp(char exp[256])
{
	do
	{
		rewind(stdin);
		fgets(exp, 256, stdin);
		if(exp[expLen(exp)] != '=' || wasteExp(exp) == true || foptr(exp) == false)
			printf("wrong input\n");
	} 
	while(exp[expLen(exp)] != '=' || wasteExp(exp) == true || foptr(exp) == false);
}

//раскидываем выражение в двумерный массив символов
int separatChar(char *exp, char **snum, int len)
{
	int i = 0;
	int j = 0;
	
	while(i < len)
	{
		if(exp[i] != ' ')
		{
			snum[j][0] = exp[i];
			snum[j][1] = '\0';
			j++;
		}
		i++;
	}
	return j;
}

int separatInt(char *exp, char **snum, int len)
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
					put = true;					//запись числа
				}
			else								//если символ подряд, то в snum +символ и некст строка
				{
					snum[j][0] = exp[i];
					snum[j][1] = '\0';
					j++;
					put = false;				//нечисло
				}
		}
		else 
			if(put == true)						//если число закончилось, то записываем конец строки и идем на новую строку
			{
				snum[j][l++] = '\0';
				put = false;					//конец числа
				l = 0;
				j++;
			}
		i++;
	}
	return j;
}

//определяем что за символ: операнд или оператор
int detSymb(char *symb)
{
	if(symb[0] == '+' || symb[0] == '-' || symb[0] == '*' || symb[0] == '/')
		return 0;
	if(symb[0] >= 'a' && symb[0] <= 'z')
		return 1;
	if(symb[0] >= '0' && symb[0] <= '9')
		return 2;
}

//алгоритм перевода из префикса в постфикс
void PreToPost(char **snum, int slen, node *head)
{
	char opnd1[127], opnd2[127], exp[256], space[]=" ";
	node *out;
	for(int i = slen - 1; i >= 0; i--)
	{
		if(detSymb(snum[i]) == 1)
			head = push(&head, snum[i]);
		if(detSymb(snum[i]) == 2)
			head = push(&head, snum[i]);
		if(detSymb(snum[i]) == 0)
		{
			out = pop(&head);
			strncpy(exp, out->data, 127);
			strncat(exp, space, 1);
			out = pop(&head);
			strncat(exp, out->data, 127);
			strncat(exp, space, 1);
			strncat(exp, snum[i], 2);
			head = push(&head, exp);
		}
	}
	if(head == NULL)
	{
		printf("\nwrong input...");
		printf("\npress ENTER to continue...");
		getch();
		exit(1);
	}
	else
	{
		out = pop(&head);
		printf("postfix:\t%s", out->data);
	}
}

int main()
{
	printf("prefix: \t");				//запись выражения
	char exp[255];
	getExp(exp);
	int len = expLen(exp);

	node *head = (node*)malloc(sizeof(node));	//стек
	head = NULL;
	node *out;

	char **snum = (char**)malloc(len*sizeof(char*));
	for(int k = 0; k < len; k++)
		*(snum + k) = (char*)malloc(2);
	int slen = separatInt(exp, snum, len);		//запись выражения в массив
	
	PreToPost(snum, slen, head);
	printf("\npress ENTER to continue...");
	getch();
	return 0;
}