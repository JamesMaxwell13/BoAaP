#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//считаем длину выражения
int expLen(char *exp)
{
	int i = 0;
	while(exp[i] != '=')
		i++;
	return i++;
}

// просматриваем на неправильные символы буквенную форму
bool wasteCharExp(char *exp)
{
	for(int i = 0; i < expLen(exp); i++)
		if((exp[i] < 'a' || exp[i] > 'z') && (exp[i] < 'A' || exp[i] > 'Z') && (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '=' && exp[i] != ' '))
			return true;
	return false;
}

// просматриваем на неправильные символы числовую форму
bool wasteExp(char *exp)
{
	for(int i = 0; i < expLen(exp); i++)
		if((exp[i] < '0' || exp[i] > '9') && (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '=' && exp[i] != ' '))
			return true;
	return false;
}

// проверяем на первый символ (должен быть знаком, иначе 100% неправильная префиксная запись)
bool foptr(char *exp)
{
	if(exp[0] != '+' && exp[0] != '-' && exp[0] != '*' && exp[0] != '/')
		return false;
	return true;
}

// считываем выражение в буквенной форме с проверкой
void getCharExp(char exp[256])
{
	do
	{
		rewind(stdin);
		fgets(exp, 256, stdin);
		if(exp[expLen(exp)] != '=' || wasteCharExp(exp) == true || foptr(exp) == false)
			printf("wrong input\n");
	} 
	while(exp[expLen(exp)] != '=' || wasteCharExp(exp) == true || foptr(exp) == false);
}

// считываем выражение в числовой форме с проверкой
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

// проверяем пробелы
void getSpaceExp(char exp[255])
{
	bool space = true;
	do
	{
		getCharExp(exp);
		int len = expLen(exp);
		for(int i = 0; i < len; i++)
			if(i%2 == 1)
				if(exp[i] != ' ')
				{
					space = false;
					printf("wrong input\n");
					break;
				}
	} 
	while (space == false);
}

int detSymb(char *symb);

// ищем количество операндов
int opndCount(char **snum, int j)
{
	int count = 0;
	for(int i = 0; i < j; i++)
		if(detSymb(snum[i]) == 1 || detSymb(snum[i]) == 2)
			count++;
	
	return count;
}

// считаем количество операторов
int optrCount(char **snum, int j)
{
	int count = 0;
	for(int i = 0; i < j; i++)
		if(detSymb(snum[i]) == 0)
			count++;
	
	return count;
}

// раскидываем выражение в двумерный массив символов
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

	// проверяем выржение на правильность записи
	if(detSymb(snum[j-1]) != 1 || detSymb(snum[j-2]) != 1 || opndCount(snum, j) != (optrCount(snum, j) + 1))
	{
		printf("wrong input\n");
		return 0;
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
			if(exp[i] >= '0' && exp[i] <= '9')	// если символ == цифра, то кидаем в одну строку массива строк
				{
					*(snum + j) = (char*)realloc(*(snum + j), (l + 2)*sizeof(char*));
					snum[j][l++] = exp[i];
					put = true;					// запись числа
				}
			else								// если символ подряд, то в snum +символ и некст строка
				{
					snum[j][0] = exp[i];
					snum[j][1] = '\0';
					j++;
					put = false;				// нечисло
				}
		}
		else 
			if(put == true)						// если число закончилось, то записываем конец строки и идем на новую строку
			{
				snum[j][l++] = '\0';
				put = false;					// конец числа
				l = 0;
				j++;
			}
		i++;
	}

	// проверяем выржение на правильность записи
	if(detSymb(snum[j-1]) != 2 || detSymb(snum[j-2]) != 2 || opndCount(snum, j) != (optrCount(snum, j) + 1))
	{
		printf("wrong input\n");
		return 0;
	}

	return j;
}

// определяем что за символ: операнд или оператор
int detSymb(char *symb)
{
	if(symb[0] == '+' || symb[0] == '-' || symb[0] == '*' || symb[0] == '/')
		return 0;
	if(symb[0] >= 'a' && symb[0] <= 'z')
		return 1;
	if(symb[0] >= '0' && symb[0] <= '9')
		return 2;
	return 0;
}
