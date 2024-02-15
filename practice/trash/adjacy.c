#include "funcs.h"

void printMatrix(int size, int **adjacy, int *peak)
{
	printf("      ");
	for(int i = 0; i < size; i++)
		printf("%4d", peak[i]);

	printf("\n______");
	for(int i = 0; i < size; i++)
		printf("____");

	printf("\n");
	for(int i = 0; i < size; i++)
	{
		printf("%4d |", peak[i]);
		for(int j = 0; j < size; j++)
			printf("%4d", adjacy[i][j]);
		printf("\n");
	}
}

int **fillMatrix(int size, int **adjacy, int *peak)
{
	for(int i = 0;	i < size; i++)
		peak[i] = i+1;
	
	for(int i = 0; i < size; i++)
	{
		printf("%d peak:\n", peak[i]);
		adjacy[i][i] = 0;
		for(int j = i+1; j < size; j++)
		{
			printf("%4d - ", peak[j]);
			adjacy[i][j] = inputBool();
			adjacy[j][i] = adjacy[i][j];
		}
	}
	return adjacy; 
}

bool compare(int *comp, int size)
{
	ShellSort(comp, size);
	return true;
}

bool verCheck(int *peak, int **adjacy, int v1, int v2)
{
	int *comp = (int*)malloc(sizeof(int));
	return true;
}

int **numMatrix(int size, int **adjacy, int *peaks)
{
	int pass = size;
	for(int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
		{
			//if(adjacy[i][j] == 1)

		}
	return adjacy;
}

int main()
{
	printf("Enter amaunt of graph vertices:\t");
	int size = inputPosInt();
	int *peak = (int*)malloc(size*sizeof(int));
	int **adjacy = (int**)malloc(size*sizeof(int*));
	for(int i = 0; i < size; i++)
		*(adjacy + i) = (int*)malloc(size*sizeof(int));

	adjacy = fillMatrix(size, adjacy, peak);
	printMatrix(size, adjacy, peak);
	getch();
	return 0;
}