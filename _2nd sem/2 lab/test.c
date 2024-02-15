#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

void getWord(char *string)
{ 
    do
    {
		rewind(stdin);
		int i=0;
		while( (string[i++] = getchar())!= '\n')
		{
			if(letterCheck(string[i-1]) == 0)
				{
					printf("You didn't enter word of letters, enter again\n");
					string[0] = '\0';
					break;
				}
			string=(char*)realloc(string,i+1);
		}
		string[i-1] = '\0';  
	}
    while(string[0]=='\0');
}

char *getStrN()
{ 
	char *string;
	string = (char*)malloc(1);
	rewind(stdin);
    int i=0;
    while( (string[i++] = getchar())!= '\n')
		string=(char*)realloc(string,i+1);
	if(string[0]=='\n')
	{
		string=(char*)realloc(string,2);
		string[1] = '\0';
	}
	else
    	string[i-1] = '\0';  
	return string;
}

void strToFile()
{
	FILE *f;
	f=fopen("name", "w+t");

	char *str;
	printf("Enter words:\n");
	do
	{
		str = getStrN();
		fprintf(f, "%s ", str);
	}
	while(str[0] != '\n');
	free(str);
	fclose(f);
}

void getFileStr(char *string, FILE *f)
{ 
    do
    {
		rewind(stdin);
		int i = 0;
		while( letterCheck(string[i++] = fgetc(f)) != 0)
			string = (char*)realloc(string, i+1);
		string[i-1] = '\0'; 
	} 
    while(string[0] == '\0');
}

int strSizeOfFile()
{
	FILE *f;
	f = fopen("name", "r");
	rewind(f);
	int i=0;
	char temp;
	while(!feof(f))
	{
		temp = fgetc(f);
		i++;
	}
	fclose(f);
	return i;
}

void printFile()
{
	FILE *f;
	f = fopen("name", "rt");
	printf("FILE:\n");
	char *word = (char*)malloc(1);
	int size = strSizeOfFile();
	rewind(f);
	for(int i = 0; i < size; i++)
	{
		word[i] = fgetc(f);
		word = (char*)realloc(word, i+1);
	}
	word[size]='\0';
	printf("%s", word);
	fclose(f);
}

void reverseFile(FILE *f, fpos_t begin, fpos_t end)
{	
		while(begin < end)
		{
			rewind(stdin);
			fsetpos(f, &begin);
			char left = fgetc(f);
			
			fsetpos(f, &end);
			char right = fgetc(f);
			
			fsetpos(f, &begin);
			fprintf(f, "%c", right);

			fsetpos(f, &end);
			fprintf(f, "%c", left);		

			begin++;
			end--;
		}
}

fpos_t shortWord()
{
	int size_file = strSizeOfFile();

	FILE *f;
	f = fopen("name", "rt");

	char temp;
	int size = 0; 
	fpos_t pos, begin;

	fgetpos(f, &pos);
	while(letterCheck(temp = fgetc(f)) != 0)
	{
		size++;
	}
	int min = size;

	for(int j = 1; j < size_file; j++)
	{
		size = 0;
		fgetpos(f, &begin);
		while(letterCheck(temp = fgetc(f)) != 0)
		{
			size++;
	  	}

		if(size < min)
		{
			pos = begin;
			min = size;
		}
	}

	fclose(f);
	return pos;
}

fpos_t longWord()
{
	
	int size_file = strSizeOfFile();

	FILE *f;
	f = fopen("name", "rt");

	char temp;
	int size = 0, max = 0; 
	fpos_t pos, begin;

	for(int j = 0; j < size_file; j++)
	{
		size = 0;
		fgetpos(f, &begin);
		while(letterCheck(temp = fgetc(f)) != 0)
		{
			size++;
	  	}

		if(size > max)
		{
			pos = begin;
			max = size;
		}
	}

	fclose(f);
	return pos;
}

void swapWords()
{
	fpos_t pos_s = shortWord();
	fpos_t pos_l = longWord();
	char *word = (char*)malloc(1);
	FILE *f;
	f = fopen("name", "r+t");
	fsetpos(f, &pos_s);
	getFileStr(word, f);
	int size_s = strLen(word);
	fsetpos(f, &pos_l);
	getFileStr(word, f);
	int size_l = strLen(word);
	if(pos_s < pos_l)
	{
	reverseFile(f, pos_s, pos_l + size_l-1);
	reverseFile(f, pos_s, pos_s + size_l-1);
	reverseFile(f, pos_l + size_l - size_s, pos_l + size_l - 1);
	reverseFile(f, pos_s + size_l + 1, pos_l + size_l - size_s - 2);
	}
	else
	{
		if(pos_l < pos_s)
		{
		reverseFile(f, pos_l, pos_s + size_s-1);
		reverseFile(f, pos_l, pos_l + size_s-1);
		reverseFile(f, pos_s + size_s - size_l, pos_s + size_s - 1);
		reverseFile(f, pos_l + size_s + 1, pos_s + size_s - size_l - 2);		
		}
		else
		{
			printf("All words in file are the same length, run task again\n");
			exit(0);
		}
	}
	fclose(f);
	printFile();
}

int main()
{
	system("chcp 1251");
	system("CLS");
	strToFile();
	//printFile();
	swapWords();
	printFile();
	getch();
	return 0;
}