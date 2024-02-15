#include "list.h"

// Разбить список с числами на три части. В первой все простые числа. Во второй оставшиеся
// четные. В третьей оставшиеся нечетные. При переносе чисел, элемент исходного списка
// удалять сразу.


node *getNums(node *tail, node *head, int *size)
{
	printf("enter the amount of numbers in list: ");
	*size = inputPosInt();

	tail = pushQ(&head);
	for(int i = 1; i < *size; i++)
		head = pushQ(&head);
	printf("list is filled...\n");
	return tail;
}

node *printNums(node *tail, int *size)
{
	//printf("Printing numbers:\n");
	node *tmp;
	for(int i = 0; i < *size; i++)
	{
		tmp = getNth(tail, i);
		printf("%6d", tmp->data);
	}
	printf("\n");
	//printf("\nNumbers are printed\n");
	return tail;
}

node *threeParts(node *tail, int *size)
{
	node *temp;
	tail = popNth(tail, 0, 0);
	tail = popNth(tail, 0, *size+1);
	*size += 2;

	int check = *size-2;

	for(int i = 1; i < *size-1; i++)
	{
		temp = getNth(tail, check);
		if(prime(temp->data) == true)
		{
			temp = delNth(&tail, check);
			tail = popNth(tail, temp->data, 0);
			free(temp);
		}
		else
			if(even(temp->data) == false)
			{
				temp = delNth(&tail, check);
				tail = popNth(tail, temp->data, *size-1);
				check--;
				free(temp);
			}
			else
				check--;
	}
	return tail;
}

int main()
{
	int dsize = 0, *size = &dsize;
	node *tail = NULL, *head = NULL;

	printf("Split the list of numbers into three parts.\n\
The first one is all prime numbers.\n\
In the second, the remaining ones are even.\n\
In the third, the remaining odd. \n\
When transferring numbers, delete\n\
the element of the original list immediately.\n\n");
	tail = getNums(tail, head, size);
	tail = printNums(tail, size);
	tail = sort(tail, size);
	tail = threeParts(tail, size);
	printf("list after \n");
	tail = printNums(tail, size);

	getch();
	return 0;
}

