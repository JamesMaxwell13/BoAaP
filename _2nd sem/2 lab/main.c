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
	word = (char*)malloc(1);
	printf("Enter numbers:\n");
	for(int i = 0; i < size; i++)
	{
		getStr(word);
		fprintf(f, "%s", word);
		free(word);
	}
}

void getFileStr(char *string, FILE *f)
{ 
    do
    {
	rewind(stdin);
    int i = 0;
    while( (string[i++] = fgetc(f)) != '\n')
		string = (char*)realloc(string,i+1);
    string[i-1] = '\0'; 
	} 
    while(string[0] == '\0');
}

int strSizeOfFile(FILE *f)
{
	fseek(f, 0, SEEK_SET);
	int i = 0;
	while (fgetc(f) != '\0') {}
		i++;
	return i;
}

void printFile(char *name)
{
	FILE *f;
	f = fopen(name, "r");
	
}

int main(int argc, char *argv[])
{
	int task = 0;
	if(argc < 2)
		printf("You didn't enter name of bin file, run program again");
	else
	{
		char *name = argv[1];
		do
		{
			system("CLS");
			printf("Number of task(to exit enter -1): ");
			task=inputInt();
			switch (task)
			{
			case -1:
				exit(0);
			case 1:
				printf("Fill in the file with words from the keyboard.\nPrint the contents of the file to the screen.\n");
				strToFile(name);
				printf("\nFILE:\n");
				printFile(name);
				getch();
				break;
			case 2:
				printf("\nPrint the second and penultimate words.\nFill the file:\n");
				task_2(name);
				break;
			case 3:
				printf("\nSwap the longest word and the shortest word.\nFill the file:\n");
				task_3(name);
				break;
			default:
				printf("There is no this task");
				break;
			}
		}
		while(task != -1);
	}
	getch();
	return 0;
}