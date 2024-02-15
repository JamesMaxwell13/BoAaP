#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

void strToFile(char *name)
{
	FILE *f;
	f=fopen(name, "w+t");
	
	int size;
	printf("Enter amount of words: ");
	size = inputPosInt();

	char *word;
	printf("Enter words:\n");
	for(int i = 0; i < size; i++)
	{
		word = (char*)malloc(1);
		getStr(word);
		fprintf(f, "%s\n", word);
		word = (char*)realloc(word, 1);
	}
	free(word);
	fclose(f);
}

void getFileStr(char *string, FILE *f)
{ 
    do
    {
		rewind(stdin);
		int i = 0;
		while( (string[i++] = fgetc(f)) != '\n')
			string = (char*)realloc(string, i+1);
		string[i-1] = '\0'; 
	} 
    while(string[0] == '\0');
}

int strSizeOfFile(char *name)
{
	FILE *f;
	f = fopen(name, "r");
	rewind(f);
	int i=0;
	char temp;
	while(!feof(f))
	{
		while((temp = fgetc(f)) != '\n') {}
		fgetc(f);
		i++;
	}
	fclose(f);
	return i;
}

void printFile(char *name)
{
	FILE *f;
	f = fopen(name, "rt");
	printf("FILE:\n");
	char *word;
	int size = strSizeOfFile(name);
	rewind(f);
	for(int i = 0; i < size; i++)
	{
		word = (char*)malloc(1);
		getFileStr(word, f);
		printf("%s\n", word);
		word = (char*)realloc(word, 1);
	}
	fclose(f);
}

fpos_t findWord(char *name, int num)
{
	FILE *f;
	f = fopen(name, "rt");
	fpos_t pos;
	int i=0;
	char temp;
	while(i != (num - 1))
	{
		while((temp = fgetc(f)) != '\n') {}
		i++;
	}
	fgetpos(f, &pos);
	fclose(f);
	return pos;
}

void printWords(char *name)
{
	int size = strSizeOfFile(name);
	fpos_t second = findWord(name, 2);
	fpos_t penult = findWord(name, size-1);
	FILE *f;
	f = fopen(name, "rt");
	char *word = (char*)malloc(1);
	fsetpos(f, &second);
	getFileStr(word, f);
	printf("second word: %s\n", word);
	fsetpos(f, &penult);
	getFileStr(word, f);
	printf("penultimate word: %s\n", word);
	fclose(f);
}

int main(int argv, char *argc[])
{
	char *name = argc[1];
	strToFile(name);
	printWords(name);
	getch();
	return 0;
}