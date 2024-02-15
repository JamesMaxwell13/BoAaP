#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"
#include <math.h>

void intToFile()
{
	FILE *f;
	f=fopen("name.bin", "w+b");

	int amount;
	printf("Enter amount of numbers: ");
	amount = inputPosInt();

	int num;
	printf("Enter numbers:\n");
	for(int i = 0; i < amount; i++)
	{
		num=inputInt();
		fwrite(&num, sizeof(int), 1, f);
	}

	int *test;
	test = (int*)malloc(sizeof(int));
	fseek(f, 0, SEEK_SET);
	fread(test, sizeof(int), amount, f);
	
	printf("FILE:\n");
	for(int i = 0; i < amount; i++)
		printf("%d\n", test[i]);
	getch();
}

int simpleNum(int num)
{
	for(int i = 2; i <= sqrt(num); i++)
	{
		if(num%i == 0 || num <= 0)
			return 0;
	}
	return 1;
}

void task_2()
{
	intToFile();
	FILE *f;
	f = fopen("name.bin", "rb");
	int num;
		int size = 0, amnt = 0;
		while(!feof(f))
		{

			size += fread(&num, sizeof(int), 1, f);
			amnt += simpleNum(num);
			printf("%d - %d\n",num, simpleNum(num));
		}	
		fclose(f);

		printf("Amount of simple numbers: %d\n",amnt);
}

int main(int argc,char *argv[])
{
	char *name = argv[1];
	// if(!argv[1])
	// 	printf("You didn't enter the name of file, run the program again");
	// else
	{
		task_2(name);
	}
	getch();
	return 0;
}