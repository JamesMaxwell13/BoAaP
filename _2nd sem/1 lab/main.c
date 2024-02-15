#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "header.h"

int intSizeOfFile(FILE *f);

void intToFile(char *name)
{
	FILE *f;
	f=fopen(name, "w+b");

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
	fclose(f);
}

void printFile(char *name)
{
	FILE *f;
	f = fopen(name, "rb");
	int amount = intSizeOfFile(f);
	int *test;
	test = (int*)malloc(sizeof(int));
	fseek(f, 0, SEEK_SET);
	fread(test, sizeof(int), amount, f);
	for(int i = 0; i < amount; i++)
		printf("%d\n", test[i]);
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

void task_2(char *name)
{
	intToFile(name);
	FILE *f;
	f = fopen(name, "rb");
	int num, size;
	int simple = 0;
	size = intSizeOfFile(f);
	for(int i = 0; i < size; i++)
	{
		fread(&num, sizeof(int), 1, f);
		simple += simpleNum(num);
		//printf("%d - %d\n",num, simpleNum(num));
	}	
	fclose(f);
	printf("\nFILE:\n");
	printFile(name);
		printf("\nAMOUNT OF PRIME NUMBERS: %d\n",simple);
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

void task_3(char *name)
{
	intToFile(name);

	FILE *f;
	f = fopen(name, "rb+");

	int num, amount;
	amount = intSizeOfFile(f);
	for(int i = 0; i < amount; i++)
	{	
		fseek(f, (int)sizeof(int)*i, SEEK_SET);	
		fread(&num, (int)sizeof(int), 1, f);			
		fseek(f, (int)sizeof(int)*i, SEEK_SET);			
		//printf("num %4d\n",num);
		num = -num;
		fwrite(&num, (int)sizeof(int), 1, f);			
	}
	fclose(f);
	printf("\nFILE AFTER CHANGING SIGN\n");
	printFile(name);
	getch();
}

// void sort(FILE *f, int size)
// {
// 	int buf, flg;
// 	int num_i, num_j;
// 	for(int gap = size/2; gap > 0; gap /= 2)
//         do 
//         {
//             flg = 0;
//             for(int i = 0, j = gap; j < size; i++, j++)
// 			{
// 				fseek(f, i*(int)sizeof(int), SEEK_SET);
// 				fread(&num_i, (int)sizeof(int), 1, f);
// 				fseek(f, j*(int)sizeof(int), SEEK_SET);
// 				fread(&num_j, (int)sizeof(int), 1, f);
//                 if(num_i > num_j)        
//                 { 
//                     buf = num_j;
//                     num_j = num_i;
//                     num_i= buf;
// 					fseek(f, i*(int)sizeof(int), SEEK_SET);
// 					fwrite(&num_i, (int)sizeof(int), 1, f);
// 					fseek(f, j*(int)sizeof(int), SEEK_SET);
// 					fwrite(&num_j, (int)sizeof(int), 1, f);
//                     flg = 1;                
// 				}
// 			}
//         } 
//         while (flg!=0);    
// }

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

void task_4(char *name)
{
	intToFile(name);

	FILE *f;
	f = fopen(name, "rb+");
	int amount;
	amount = intSizeOfFile(f);
	sort(f,amount);
	fclose(f);
	printf("\nFILE AFTER SORTING\n");
	printFile(name);
	getch();
}

int main(int argc, char *argv[])
{
	int task = 0;
	char *name = argv[1];
	if(!argv[1])
		printf("You didn't enter name of bin file, run program again");
	else
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
				printf("From the keyboard, fill the file with integers numbers:\n");
				intToFile(name);
				printf("\nFILE:\n");
				printFile(name);
				getch();
				break;
			case 2:
				printf("Count the number of prime numbers in the file:\nFill the file:\n");
				task_2(name);
				break;
			case 3:
				printf("Change the sign of each number to the opposite:\nFill the file:\n");
				task_3(name);
				break;
			case 4:
				printf("Sort all negative elements in descending order:\nFill the file:\n");
				task_4(name);
				break;
			default:
				printf("There is no this task");
				break;
			}
		}
		while(task != -1);
	getch();
	return 0;
}