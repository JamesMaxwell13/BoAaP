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

void strToFile()
{
	FILE *f;
	f=fopen("name", "w+t");
	
	int size;
	printf("Enter amount of words: ");
	size = inputPosInt();

	char *word = (char*)malloc(255);;
	printf("Enter words:\n");
	for(int i = 0; i < size; i++)
	{
		getWord(word);
		//fgets(word,255,stdin); 
		//fputs(word, f);
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
		int i = 0;
		while( (string[i++] = fgetc(f)) != '\n')
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
		while((temp = fgetc(f)) != '\n') {}
		fgetc(f);
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
	char *word;
	int size = strSizeOfFile();
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

fpos_t shortWord()
{
	int size_file = strSizeOfFile();

	FILE *f;
	f = fopen("name", "rt");

	char temp;
	int size = 0; 
	fpos_t pos, begin;

	fgetpos(f, &pos);
	while((temp = fgetc(f) != '\n'))
	{
		size++;
	}
	int min = size;

	for(int j = 1; j < size_file; j++)
	{
		size = 0;
		fgetpos(f, &begin);
		while((temp = fgetc(f) != '\n'))
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
		while((temp = fgetc(f) != '\n'))
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
	printf("\nshortest %s pos %d\n", word, pos_s);
	fsetpos(f, &pos_l);
	getFileStr(word, f);
	int size_l = strLen(word);
	printf("\nlongest %s pos %d\n", word, pos_l);
	if(pos_s < pos_l)
	{
	reverseFile(f, pos_s, pos_l + size_l-1);
	reverseFile(f, pos_s, pos_s + size_l-1);
	reverseFile(f, pos_l + size_l - size_s, pos_l + size_l - 1);
	reverseFile(f, pos_s + size_l + 1, pos_l + size_l - size_s - 2);
	}
	fclose(f);
	printFile();
}

int main()
{
	system("chcp 1251");
	//system("CLS");
	strToFile();
	//printFile();
	swapWords();
	printFile();
	getch();
	return 0;
}