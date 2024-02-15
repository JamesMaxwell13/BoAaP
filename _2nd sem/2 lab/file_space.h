#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int inputPosInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);

		if(scn!=1 || num<=0)
		{
            printf("Wrong input\n");
			scn=0;
			continue;
		}

        while ((temp=getchar())!='\n')
        if(temp>'9' || temp<'0')
		{
            printf("Wrong input\n");
			scn=0;
			break;
		}
    }
    while(num<=0 || scn!=1);
    return num;
}

int inputInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);
        while ((temp=getchar())!='\n')
        if(scn!=1 || temp>'9' || temp<'0')
		{
            printf("Wrong input");
			scn=0;
			break;
		}
    }
    while(scn!=1);
    return num;
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

int strLen(char *s)
{
	int i=0;
	while (s[i]!='\0')
		i++;
	return i;
}

int	letterCheck(char symbol)
{
	if((symbol>='A' && symbol<='Z') || (symbol>='a' && symbol<='z') || (symbol>='À' && symbol<='ß') || (symbol>='à' && symbol<='ÿ'))
		return 1;
	return 0;
}  

// void getWord(char *string)
// { 
//     do
//     {
// 		rewind(stdin);
// 		int i=0;
// 		while( (string[i++] = getchar())!= '\n')
// 		{
// 			if(letterCheck(string[i-1]) == 0)
// 				{
// 					printf("You didn't enter word of letters, enter again\n");
// 					string[0] = '\0';
// 					break;
// 				}
// 			string=(char*)realloc(string,i+1);
// 		}
// 		string[i-1] = '\0';  
// 	}
//     while(string[0]=='\0');
// }

void strToFile(char *name)
{
	FILE *f;
	f=fopen(name, "w+t");

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
		while( (string[i++] = fgetc(f)) != ' ')
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
		while((temp = fgetc(f)) != ' ') {}
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

fpos_t shortWord(char *name)
{
	int size_file = strSizeOfFile(name);

	FILE *f;
	f = fopen(name, "rt");

	char temp;
	int size = 0; 
	fpos_t pos, begin;

	fgetpos(f, &pos);
	while((temp = fgetc(f) != ' '))
	{
		size++;
	}
	int min = size;

	for(int j = 1; j < size_file; j++)
	{
		size = 0;
		fgetpos(f, &begin);
		while((temp = fgetc(f) != ' '))
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

int longWord(char *name)
{
	
	int size_file = strSizeOfFile(name);

	FILE *f;
	f = fopen(name, "rt");

	char temp;
	int size = 0, max = 0; 
	fpos_t pos, begin;

	for(int j = 0; j < size_file; j++)
	{
		size = 0;
		fgetpos(f, &begin);
		while((temp = fgetc(f) != ' '))
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

void swapWords(char *name)
{
	fpos_t pos_s = shortWord(name);
	fpos_t pos_l = longWord(name);
	char *word = (char*)malloc(1);
	FILE *f;
	f = fopen(name, "r+t");
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
		while((temp = fgetc(f)) != ' ') {}
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
	printf("\nsecond word: %s\n", word);
	fsetpos(f, &penult);
	getFileStr(word, f);
	printf("penultimate word: %s\n", word);
	fclose(f);
}
