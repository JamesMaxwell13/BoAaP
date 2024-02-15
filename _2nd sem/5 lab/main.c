#include <stdio.h>
#include <stdlib.h>
#include "num.h"
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

//пушим строки
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

//попим строки, возвращаем структуру out (не  значение)
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


//алгоритм перевода из префикса в постфикс
void PreToPost(char **snum, int slen, node *head)
{
	char exp[256], space[]=" ";
	node *out;
	for(int i = slen - 1; i >= 0; i--)
	{
		// смотрим с конца выражения что за символ:
		// оператор или операнд: если операнд, то пушим в стек
		if(detSymb(snum[i]) == 1)
			head = push(&head, snum[i]);
		if(detSymb(snum[i]) == 2)
			head = push(&head, snum[i]);
		if(detSymb(snum[i]) == 0)
		{
			// когда находим оператор, то попим из стека два
			// операнда и записываем в постфикс
			if((out = pop(&head))== NULL)
			{
				printf("wrong input\n"); 
				return;
			}
			strncpy(exp, out->data, 127);
			strncat(exp, space, 1);
			free(out);

			if((out = pop(&head))== NULL)
			{
				printf("wrong input\n"); 
				return;
			}
			strncat(exp, out->data, 127);
			strncat(exp, space, 1);
			strncat(exp, snum[i], 2);
			free(out);

			// пушим выражение в стек
			head = push(&head, exp);
		}
	}

	if(head == NULL)
	{
		printf("\nsomething gets wrong...");
		printf("\npress ENTER to continue...");
		getch();
		exit(1);
	}
	else
	{
		out = pop(&head);
		printf("postfix:\t\t%s", out->data);
		free(out);
	}
}

// функция определяет вид оператора и считает выражение
int calcExp(int opnd1, int opnd2, char oprt)
{
	switch(oprt)
	{
		case '+':
			return opnd1 + opnd2;
		case '-':
			return opnd1 - opnd2;
		case '*':
			return opnd1 * opnd2;
		case '/':
			return opnd1 / opnd2;
	}
	return 0;
}

// алгоритм подсчета такой же как и алгортим перевода выражения
// только при встрече оператора, выражение с двумя операндами вычисляется сразу
int calcPrefix(char **snum, int slen, node *head)
{
	int answer, opnd1, opnd2;
	char exp[256];
	node *out;
	for(int i = slen - 1; i >= 0; i--)
	{
		if(detSymb(snum[i]) == 2)
			head = push(&head, snum[i]);
		if(detSymb(snum[i]) == 0)
		{
			out = pop(&head);
			opnd1 = atoi(out->data);
			free(out);

			out = pop(&head);
			opnd2 = atoi(out->data);
			free(out);
			
			itoa(calcExp(opnd1, opnd2, snum[i][0]), exp, 10);
			head = push(&head, exp);
		}
	}
	if(head == NULL)
	{
		printf("\nsomething gets wrong...");
		printf("\npress ENTER to continue...");
		getch();
		exit(1);
	}
	else
	{
		out = pop(&head);
		answer = atoi(out->data);
		free(out);
		return answer;
	}
}

int main()
{
	node *head = (node*)malloc(sizeof(node));	//стек

	while(1)
	{
		head = NULL;
		printf("\tchoose the form of expression:\n\
\t1 - letter entry\n\
\t2 - numetric entry\n\
\t3 - exit the program\n\
	your choise: ");
		int choise = inputPosInt();
		printf("\nenter the expression:\t");				//запись выражения
		char exp[255];

		switch(choise)
		{
			case 1:
			{
				getSpaceExp(exp);								// считывам выражение
				int len = expLen(exp);
				char **snum = (char**)malloc(len*sizeof(char*));
				for(int k = 0; k < len; k++)
					*(snum + k) = (char*)malloc(2);

				int slen;
				if((slen = separatChar(exp, snum, len)) == 0)	// запись выражения в массив
				{
					printf("\npress ENTER to continue...");
					getch();
					break;
				}
				PreToPost(snum, slen, head);					// меняем форму записи
				printf("\npress ENTER to continue...");
				getch();
				break;
			}
			case 2:
			{
				getExp(exp);									// считываем выражение
				int len = expLen(exp);
				char **snum = (char**)malloc(len*sizeof(char*));
				for(int k = 0; k < len; k++)
					*(snum + k) = (char*)malloc(2);

				int slen;
				if((slen = separatInt(exp, snum, len)) == 0)	// запись выражения в массив
				{
					printf("\npress ENTER to continue...");
					getch();
					break;
				}
				PreToPost(snum, slen, head);					// меняем форму записи
				printf(" = %d\n", calcPrefix(snum, slen, head));	// считаем
				printf("\npress ENTER to continue...");
				getch();
				break;
			}
			case 3: 
			{
				printf("\npress ENTER to exit program...");
				getch();
				exit(0);
			}
			default:
			{
				printf("wrong input\n");
				break;
			}
		}
		system("CLS");
	}
	return 0;
}