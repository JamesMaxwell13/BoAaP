#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "file_space.h"

void task_1(char *name)
{
	printf("\nFill in the file with words from the keyboard.\nPrint the contents of the file to the screen.\n");
	strToFile(name);
	printFile(name);
	getch();
}

void task_2(char *name)
{
	printf("\nPrint the second and penultimate words.\nFill the file:\n");
	strToFile(name);
	printWords(name);
	getch();
}

void task_3(char *name)
{
	printf("\nSwap the longest word and the shortest word.\nFill the file:\n");
	strToFile(name);
	swapWords(name);
	printFile(name);
	getch();
}

void (*functions[])(char *name)={task_1, task_2, task_3};

int main(int argc, char *argv[])
{
	int task = 0;
	if(argc < 2)
		printf("You didn't enter name of file, run program again");
	else
	{
		char *name = argv[1];
		do
		{
			system("chcp 1251");
			system("CLS");
			printf("Number of task(to exit enter -1): ");
			task = inputInt();
			if(task == -1)
				exit(0);
			(*functions[task-1])(name);
		}
		while(task != -1);
	}
	getch();
	return 0;
}