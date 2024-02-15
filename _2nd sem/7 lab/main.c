#include "funcs.h"
#include "tree.h"

// Реализовать все необходимые методы для работы с бинарными деревьями — поиск,
// удаление, добавление, изменение, просмотр элементов помимо основной задачи. Обход границ бинарного дерева.

// Выполнение двух любых доп заданий.
// 1) Реализовать словарь в бинарном дереве. В словаре храниться слово на английском и его
// перевод. Ввод происходит из файла со строками следующего типа: «cat=кот».
// 2) Дана матрица MxN с нулями и единицами. Нули — вода, единицы — суша. Найти и
// раскрасить в разные цвета острова.
// 3) Дан массив строк. Найти максимальную подстроку присутствующую в каждой строке.

// Обход границ бинарного дерева.

void changeLeaf(leaf *root, int key)
{
	delLeaf(root, key);
	insert(root, key);
}

void borderLeft(leaf *head)
{
	if(head == NULL)
		return;
	if(head->left != NULL)
	{
		printf("%d ", head->data);
		borderLeft(head->left); 
	}
	else
		if(head->right != NULL)
		{
			printf("%d ", head->data);
			borderLeft(head->right); 
		}
}

void borderRight(leaf *head)
{
	if(head == NULL)
		return;
	if(head->right != NULL)
	{
		borderRight(head->right); 
		printf("%d ", head->data);
	}
	else
		if(head->left != NULL)
		{
			borderRight(head->left); 
			printf("%d ", head->data);
		}
}

void borderLeaf(leaf *head)
{
	if(head == NULL)
		return;
	
	borderLeaf(head->left);

	if(head->left == NULL && head->right == NULL)
		printf("%d ", head->data);

	borderLeaf(head->right);
}

void printBorder(leaf *root)
{
	if(root == NULL)
		return;
	
	printf("%d ", root->data);
	borderLeft(root->left);
	borderLeaf(root->left);
	borderLeaf(root->right);
	borderRight(root->right);
}

leaf *buildTree()
{
	printf("Enter the verticises of tree:\n");
	int *vertex = (int*)malloc(sizeof(int));
	int size = getArr(vertex);
	leaf *root = makePre(vertex, 0, size-1);
	free(vertex);
	return root;
}

enum task
{
	build = 1,
	print,
	find,
	delete,
	add,
	change,
	border,
	stop,
};

int main()
{
	printf("Implement all the necessary methods for working with binary trees:\n\
search, deleting, adding, changing, viewing elements in addition\n\
to the main task. Bypassing the boundaries of a binary tree.\n\n");
	leaf *root = NULL;
	while(1)
	{
		printf("Choose what you would like to do:\n\
1 - create new binary tree\n\
2 - print existing tree\n\
3 - search in BST\n\
4 - delete element in BST\n\
5 - add element to BST\n\
6 - change data in BST\n\
7 - boundary traversal in BST\n\
8 - stop executing program\n\n");
		enum task chs = inputPosInt();
		switch(chs)
		{
			case build: 
			{
				printf("\nChoose the traversal for creating BST:\n\
1 - pre-order traversal\n\
2 - in-order\n\
3 - post-order traversal\n\n");
				int trvrsl = inputPosInt();
				int *vertex = (int*)malloc(sizeof(int));
				int size = getArr(vertex);
				switch(trvrsl)
				{
					case 1:
					{
						root = makePre(vertex, 0, size - 1);
						break;
					}
					case 2:
					{
						root = makeInf(vertex, 0, size - 1);
						break;
					}
					case 3:
					{
						root = makePost(vertex, 0, size - 1);
						break;
					}
					default:
					{
						printf("Something gets wrong...\nPress ENTER to continue...\n");
						getch();
						break;
					}
				}
				free(vertex);
				printf("\n");
				print2D(root, 1);
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case print:
			{
				if(root == NULL)
				{
					printf("\nThe BST is empty, create new tree\n");
					printf("Press ENTER to continue...\n");
					getch();
					break;
				}
				printf("\nChoose the traversal for printing BST:\n\
1 - pre-order traversal\n\
2 - in-order\n\
3 - post-order traversal\n\n");
				int trvrsl = inputPosInt();
				switch(trvrsl)
				{
					case 1:
					{
						prePrint(root);
						break;
					}
					case 2:
					{
						infPrint(root);
						break;
					}
					case 3:
					{
						postPrint(root);
						break;
					}
					default:
					{
						printf("Something gets wrong...\nPress ENTER to continue...\n");
						getch();
						break;
					}
				}
				printf("\n");
				print2D(root, 1);
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case find:
			{
				if(root == NULL)
				{
					printf("\nThe BST is empty, create new tree\n");
					printf("Press ENTER to continue...\n");
					getch();
					break;
				}

				printf("\nEnter data to find it in BST:\n");
				int key = inputInt();
				leaf *answer = search(root, key);
				if(answer == NULL)
					printf("There is no such element\n");
				else
				{
					printf("\nsearching leaf - %d\n", answer->data);
					if(answer->left != NULL)
						printf("left leaf - %d\n", answer->left->data);
					if(answer->right != NULL)
						printf("right leaf - %d\n", answer->right->data);
				}
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case delete:
			{
				if(root == NULL)
				{
					printf("\nThe BST is empty, create new tree\n");
					printf("Press ENTER to continue...\n");
					getch();
					break;
				}

				printf("\nEnter data to delete node in BST:\n");
				int key = inputInt();
				leaf *answer = delLeaf(root, key);
				if(answer == NULL)
					printf("There is no such element\n");
				else
				{
					printf("\nBST after deleting:\n\n");
					print2D(root, 1);
				}
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case add:
			{
				if(root == NULL)
				{
					printf("\nThe BST is empty, create new tree\n");
					printf("Press ENTER to continue...\n");
					getch();
					break;
				}
				printf("\nEnter data to insert new node in BST:\n");
				int key = inputInt();
				insert(root, key);
				printf("BST after inserting:\n");
				print2D(root, 1);
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case change:
			{
				if(root == NULL)
				{
					printf("The BST is empty, create new tree\n");
					printf("Press ENTER to continue...\n");
					getch();
					break;
				}
				printf("\nEnter data to find changing node in BST:\n");
				int chkey = inputInt();
				delLeaf(root, chkey);
				printf("Enter new data to change:\n");
				int ikey = inputInt();
				insert(root, ikey);
				printf("\nBST after changing:\n");
				print2D(root, 1);
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case border:
			{
				if(root == NULL)
				{
					printf("\nThe BST is empty, create new tree\n");
					printf("Press ENTER to continue...\n");
					getch();
					break;
				}
				printf("\nBoundary traversal of BST:\n");
				printBorder(root);
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case stop:
			{
				printf("\nPress ENTER to continue...\n");
				getch();
				exit(0);
				break;
			}
			default:
			{
				printf("\nSomething gets wrong...\nPress ENTER to continue...\n");
				getch();
				break;
			}
		}

	}

	getch();
	return 0;
}