#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

// Используя самописный стек, реализовать функции, решающие выданную задачу.
// Преобразование выражения из префиксной формы в постфиксную.

typedef struct stack
{
	int data;
	struct stack *next;
} 
node;

node *push(node **head, int num)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	tmp->data = num;

	if (head == NULL)
		head = tmp;
	else
	{
		tmp->next = head;
		head = tmp;
	}
	return head;
}

node *pop(node **head)
{
	if(head != NULL)
	{
		node *out = *head;
		*head = (*head)->next;
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
int separation(char *exp, char **snum, int len)
{
	int i = 0;
	int l = 0;
	int j = 0;
	bool put = false;

	while(i <= len)
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
					printf("%c ", snum[j][0]);
					j++;
					put = false;
				}
		}
		else 
			if(put == true)		//если число закончилось, то записываем конец строки и идем на новую строку
			{
				snum[j][l++] = '\0';
				printf("%s ", snum[j]);
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

	return j;
}



int main()
{
	int nums[255];
	char exp[255], sign[255];
	getExp(exp);
	int len = expLen(exp);

	char **snum = (char**)malloc(len*sizeof(char*));
	for(int k = 0; k < len; k++)
		*(snum + k) = (char*)malloc(1);

	int lens = separation(exp, snum, len);


	getch();
	return 0;
}




	// while(sign[i-1] != '=')
	// {		
	// 	if(scanf("%d", &nums[i]) == 0)
	// 		scanf("%c", &sign[i]);
	// 	//getchar();
	// 		scanf("%c", &sign[i]);
	// 	i++;
	// }

	// nums[i] = 0;
	// sign[i] = 0;


	// for(int j = 0; j < i; j++)
	// 	printf("%d ", nums[j]);
	// for(int j = 0; j < i; j++)
	// 	printf("%c ", sign[j]);