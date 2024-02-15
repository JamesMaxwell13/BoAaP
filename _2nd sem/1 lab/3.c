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
	
	printf("FILE:\n");
	for(int i = 0; i < amount; i++)
		printf("%d\n", test[i]);
	getch();
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

void task()
{
	intToFile();

	FILE *f;
	f = fopen("name", "rb+");

	int num, amount;
	amount = intSizeOfFile(f);
	for(int i = 0; i < amount; i++)
	{	
		fseek(f, (int)sizeof(int)*i, SEEK_SET);	
		fread(&num, (int)sizeof(int), 1, f);			//считываем цифру
		fseek(f, (int)sizeof(int)*i, SEEK_SET);			//сдвигаем курсор на цифру влево
		printf("num %4d\n",num);
		num = -num;
		fwrite(&num, (int)sizeof(int), 1, f);			//выводим цифру с обратным знаком в файл
	}

	int *test;
	test = (int*)malloc(amount*sizeof(int));
	fseek(f, 0, SEEK_SET);
	int i=0;
	while(!feof(f))
	{
		fread(test+i, sizeof(int), 1, f);
		i++;
	}

	printf("AFTER CHANGING SIGN\n");
	for(int i = 0; i < amount; i++)
			printf("%d\n", test[i]);
	fclose(f);
}

int main()//int argc,char *argv[])
{
	task();
	getch();
	return 0;
}