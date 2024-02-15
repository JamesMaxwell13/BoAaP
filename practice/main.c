#include "tree.h"
#include <math.h>

// нумерация "змейкой"
void numLevel(leaf *head, int level, bool ltr, int *data)
{
    if (head == NULL)
        return;
    if (level == 1)
	{		
		// если уровень нужный, нумеруем вершину
		head->data = (*data)++;
	}
    else 
	if (level > 1) 
	{
		// рекурсивный обход слева направо или справа налево
        if (ltr) 
		{
            numLevel(head->left, level - 1, ltr, data);
            numLevel(head->right, level - 1, ltr, data);
        }
        else 
		{
            numLevel(head->right, level - 1, ltr, data);
            numLevel(head->left, level - 1, ltr, data);
        }
    }
}

// итерирует нумерацию спиралью
void numSpiral(leaf *root, int height)
{
	// вначале слева напрвао
    bool ltr = false;
	int data = 0, *p = &data;
	// обход по уровням с первого (узловой корень)
    for (int i = 1; i <= height; i++) 
	{
        numLevel(root, i, ltr, p);
        ltr = !ltr;
    }
}

// удаление лишних по значению вершин
void delLevel(leaf *head, int level, int size)
{
    if (head == NULL)
        return;
    if (level == 1)
	{		
		// если левый или правый лист от данного узла больше либо равен размеру, то удаляем
		if(head->left->data >= size)
		{
			leaf *tmp = head->left;
			head->left = NULL;
			free(tmp);
		}		
		if(head->right->data >= size)
		{
			leaf *tmp = head->right;
			head->right = NULL;
			free(tmp);
		}
	}
    else 
	if (level > 1) 
	{
		// обход на левый и правый лист
        delLevel(head->left, level - 1, size);
        delLevel(head->right, level - 1, size);
    }
}

// инициализируем дерево: пушим вершины, нумеруем их и удаляем ненужные узлы
leaf *fillTree(leaf *root, int size)
{
	int height = 1, buf = size;
	while(buf > 0)
		buf -= pow(2, height++);
	recPush(root, height);
	numSpiral(root, height);
	delLevel(root, height-1, size);
	return root;
}

// рекурсивный обход для заполнения матрицы
void fillOrder(leaf *head, int **adjacy)
{
	if (head != NULL) 
	{ 
		// обход слева
		fillOrder(head->left, adjacy); 
		// проверка на смежность с левым листом
		if(head->left != NULL)
			adjacy[head->data][head->left->data] = adjacy[head->left->data][head->data] = 1;
		// проверка на смежность с правым листом
		if(head->right != NULL)
			adjacy[head->data][head->right->data] = adjacy[head->right->data][head->data] = 1;
		// обход справа
		fillOrder(head->right, adjacy);
  	}
}

// выводим матрицу
void printMatrix(int size, int **adjacy, int *peak)
{
	printf("\n      ");
	for(int i = 0; i < size; i++)
		printf("%4d", peak[i]);

	printf("\n  ____");
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

// заполняем массив вершин, 
void fillMatrix(leaf *root, int size, int **adjacy, int *peak)
{
	for(int i = 0;	i < size; i++)
		peak[i] = i;

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			adjacy[i][j] = 0;

	fillOrder(root, adjacy);
}


int main()
{
	leaf *root = (leaf*)malloc(sizeof(leaf));
	//root->head = NULL;

	printf("Graceful labeling of graphs (game by Solomon Golomb).\n\
You need to build a graph and sign its vertices with\n\
various positive integers (or zero). The vertices must be\n\
numbered so that the differences in the numbers assigned\n\
to neighboring vertices do not coincide, and at the same\n\
time the largest vertex number is as small as possible.\n\n");
	printf("Enter amount of graph vertices:\t");
	int size = inputPosInt();
	int *peak = (int*)malloc(size*sizeof(int));
	int **adjacy = (int**)malloc(size*sizeof(int*));
	for(int i = 0; i < size; i++)
		*(adjacy + i) = (int*)malloc(size*sizeof(int));

	root = fillTree(root, size);
	//printTree(root);	
	printf("\n");
	fillMatrix(root, size, adjacy, peak);
	printMatrix(size, adjacy, peak);
	printf("\n\n");
	print2D(root, 0);
	getch();
	return 0;
}
