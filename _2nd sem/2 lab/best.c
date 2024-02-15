#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

char *getStrN()
{ 
	char *string;
	string = (char*)malloc(1);
	rewind(stdin);
    int i=0;
    while( (string[i++] = getchar())!= '\n')
		string=(char*)realloc(string, i+1);

	if(string[0]=='\n')
	{
		string = (char*)realloc(string,2);
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
	while(1)
	{
		str = getStrN();
		if(str[0] == '\n')
			break;
		fprintf(f, "%s", str);
	}
	free(str);
	fclose(f);
}

void getFileWord(char *string, FILE *f)
{ 
    do
    {
		rewind(stdin);
		int i = 0;
		while(letterCheck(string[i++] = fgetc(f)) != 0)
			string = (char*)realloc(string, i+1);
		string[i-1] = '\0'; 
	} 
    while(string[0] == '\0');
}

int strSizeOfFile()
{
	FILE *f;
	f = fopen("name", "rt");
	rewind(f);
	int i = 0;
	char temp;
	while(!feof(f))
	{
		temp = fgetc(f);
		i++;
	}
	i--;
	fclose(f);
	return i;
}

void printFile()
{
	printf("FILE:\n");
	int size = strSizeOfFile();
	FILE *f;
	f = fopen("name", "rt");
	char *word = (char*)malloc(size+1);
	for(int i = 0; i < size; i++)
		word[i] = fgetc(f);
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
	int size = 0, i = 0 ; 
	fpos_t pos, begin;

	while(letterCheck(temp = fgetc(f)) != 1) 
		i++;
	fgetpos(f, &pos);
	while(letterCheck(temp = fgetc(f)) != 0)
	{
		size++;
		i++;
	}
	int min = size;

	while(i < size_file)
	{
		size = 0;
		while(letterCheck(temp = fgetc(f)) != 1) 
			i++;
		fgetpos(f, &begin);
		while(letterCheck(temp = fgetc(f)) != 0)
		{
			size++;
			i++;
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
	int size = 0, max = 0, i = 0; 
	fpos_t pos, begin;

	while(i < size_file)
	{
		size = 0;
		while(letterCheck(temp = fgetc(f)) != 1) 
			i++;
		fgetpos(f, &begin);
		while(letterCheck(temp = fgetc(f)) != 0)
		{
			size++;
			i++;
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
	getFileWord(word, f);
	int size_s = strLen(word);
	fsetpos(f, &pos_l);
	getFileWord(word, f);
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
	printFile();
	swapWords();
	//printFile();
	getch();
	return 0;
}