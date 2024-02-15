#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

//Дана строка. Преобразовать в ней все строчные буквы в прописные, а прописные — в строчные.
void task_1()
{	
    char *str;
	int size=1;
    printf("Enter string:\n");
	str=(char*)calloc(size,1);
	getStr(str);
	size=strLen(str);
	for(int i=0;i<=size;i++)
	{
		if((str[i]>='A' && str[i]<='Z') || (str[i]>='А' && str[i]<='Я'))
		{
			str[i]+=32;
			continue;
		}
		if((str[i]>='a' && str[i]<='z') || (str[i]>='а' && str[i]<='я'))
			str[i]-=32;
	}
	printf("Final string: %s",str);
}

// Дано целое число N (> 0) и строка S. Преобразовать строку S в строку длины N
// следующим образом: если длина строки S больше N, то отбросить первые
// символы, если длина строки S меньше N, то в ее начало добавить символы «.».
void task_2()
{
    char *str;
	int size=1;
	str=(char*)calloc(size,1);
	printf("Enter string: ");
	getStr(str);
	size=strLen(str);

	int n;
	printf("Enter number N: ");
	n=inputPosInt();

	if(size>n)
	{
		while(size!=n)
		{
			for(int i=0;i<=size;i++)
				str[i]=str[i+1];
			size--;
			str=(char*)realloc(str,size+1);
		}
	}

	if(size<n)
	{
		while(size!=n)
		{
			size++;
			str=(char*)realloc(str,size+1);
			for(int i=size;i>0;i--)
				str[i]=str[i-1];
			str[0]='.';
		}
	}
	printf("Final string: %s",str);
}

//Отсортировать методом вставок массив строк по возрастанию количества слов
void wordsInsertionSort(char **str,int size)
{
	int choose;
	printf("Choose way of counting words(1 - words consists only of english and\n\
russian letters, any integer number - words are separeted by punctuation marks): ");
	choose=inputInt();

    int i, j;
	char *key;
    for (i = 1; i < size; i++)
    {
        key = str[i];
        j = i - 1;
		if(choose==1)
		{
        	while (j >= 0 && classicWords(str[j]) > classicWords(key))
	        {
    	        str[j + 1] = str[j];
        	    j--;
        	}
		}
		else
		{
			while (j >= 0 && anyWords(str[j]) > anyWords(key))
	        {
    	        str[j + 1] = str[j];
        	    j--;
        	}
		}
        str[j + 1] = key;
    }
	if(choose==1)
		for(int i=0;i<size;i++)
			printf("%d words: %s\n",classicWords(str[i]),str[i]);
	else
		for(int i=0;i<size;i++)
			printf("%d words: %s\n",anyWords(str[i]),str[i]);
}

void task_3()
{
		char **str;
		int size;
		printf("Enter size of array: ");
		size=inputPosInt();
		str=(char**)malloc(size*1);
		for(int i=0;i<size;i++)
		{
			str[i]=(char*)malloc(1*1);
			printf("%d string: ",i+1);
			getStr(str[i]);
		}

		wordsInsertionSort(str, size);

		// for(int i=0;i<size;i++)
		// 	printf("%d: %s\n",words(str[i]),str[i]);
}

int main()
{
	system("chcp 1251");
    int task=0;
    while(task!=-1)
    {
    printf("Choose number of task(enter -1 for exit): ");
    scanf("%d",&task);
    {
        switch (task)
        {
        case 1:
        {
            printf("\nGiven a string. Convert all lowercase letters to uppercase\n\
and uppercase letters to lowercase.\n\n");
            task_1();
            break;
        }
        case 2:
        {
            printf("\nGiven an integer N (> 0) and a string S. Convert string S\n\
to a string of length N as follows: if the length of string S is greater\n\
than N, then discard the first characters, if the length of string S is\n\
less than N, then add \".\".\n\n");
            task_2();
            break;
        }
        case 3:
        {
            printf("\nDo insertion sort array of strings in ascending order of\n\
word count\n\n");
            task_3();
            break;
        }
        case -1:
        {
            exit(0);
        }
        default:
        printf("Incorrect input number of task, try again");
        }
        getch();
        system("cls");
    }
    }
    getch();
    return 0;
}
