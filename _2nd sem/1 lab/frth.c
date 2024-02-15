#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

void intToFile()
{
	FILE *f;
	f=fopen("name", "w+b");

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
	
	// printf("FILE:\n");
	// for(int i = 0; i < amount; i++)
	// 	printf("%d\n", test[i]);
	// getch();
}

int intSizeOfFile(FILE *f)
{
	int amount = 0;
	int buff;
	while(!feof(f))
		amount += fread(&buff, (int)sizeof(int), 1, f);
	fseek(f, 0, SEEK_SET);
	return amount;
}

void sort(FILE *f,int size)
{
    int buf;
    int min;
	int num_min, num_j;
    for(int i=0;i<size-1; i++) 
    { 
        min=i;
		fseek(f, min*(int)sizeof(int), SEEK_SET);
		fread(&num_min, (int)sizeof(int), 1, f); 
		if(num_min < 0)
			for(int j=i+1; j<size; j++)
			{
				fseek(f, j*(int)sizeof(int), SEEK_SET);
				fread(&num_j, (int)sizeof(int), 1, f);
				if(num_j < 0)
					if(num_min < num_j) 
					{
						min = j;
						buf = num_j;
						num_j = num_min;
						num_min = buf;
						fseek(f, i*(int)sizeof(int), SEEK_SET);
						fwrite(&num_min, (int)sizeof(int), 1, f);
						fseek(f, min*(int)sizeof(int), SEEK_SET);
						fwrite(&num_j, (int)sizeof(int), 1, f);
					}
			}
    }
}

void task()
{
	intToFile();

	FILE *f;
	f = fopen("name", "rb+");

	int amount;
	amount = intSizeOfFile(f);
	sort(f,amount);

	int *test;
	test = (int*)malloc(amount*sizeof(int));
	fseek(f, 0, SEEK_SET);
	fread(test, sizeof(int), amount, f);

	printf("AFTER SORTING\n");
	for(int i = 0; i < amount; i++)
			printf("%d\n", test[i]);
	fclose(f);
}

int main(int argc,char *argv[])
{
	task();
	getchar();
	return 0;
}