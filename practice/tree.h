#pragma once
#include "funcs.h"
#define COUNT 5

typedef struct Leaf
{
	int data;
	//struct Leaf *head;
	struct Leaf *left;
	struct Leaf *right;
} leaf;

leaf *pushTwo(leaf **head, int dl, int dr)
{
	if(head != NULL)
	{
		leaf *tmpl = (leaf*)malloc(sizeof(leaf));
		leaf *tmpr = (leaf*)malloc(sizeof(leaf));
		tmpl->left = tmpl->right = NULL;
		tmpl->data = dl;
		tmpr->left = tmpr->right = NULL;
		tmpr->data = dr;
		(*head)->left = tmpl;
		(*head)->right = tmpr;
	}
	return *head;
}

leaf *pushLeft(leaf **head, int dl)
{
	leaf *tmpl = (leaf*)malloc(sizeof(leaf));
	tmpl->left = tmpl->right = NULL;
	tmpl->data = dl;
	if(head != NULL)
		(*head)->left = tmpl;
	return *head;
}

leaf *pushRight(leaf **head, int dr)
{
	leaf *tmpr = (leaf*)malloc(sizeof(leaf));
	tmpr->left = tmpr->right = NULL;
	tmpr->data = dr;
	if(head != NULL)
		(*head)->right = tmpr;
	return *head;
}

// рекурсивное создание дерева до определенного уровня
void recPush(leaf *head, int level)
{
	if(level > 1)
	{
		// пушим два листа (левый и правый)
		pushTwo(&head, 0, 0);
		level--;
		// идем в левый лист, потом в правый
		recPush(head->left, level);
		recPush(head->right, level);
	}
}

void printTree(leaf *head)
{
	if (head != NULL) 
	{ 
		printTree(head->left); 
		printf("%d  ", head->data);
		printTree(head->right);
  	}
}

// вывод с табуляцией
void print2D(leaf *head, int tab)
{
    if (head == NULL)
        return;

	// новая рекурсия - больше табуляция
    tab += COUNT;
 
	// идем влево
    print2D(head->right, tab);
 
	// табулируем на нужное количество пробелов
    for(int i = COUNT; i < tab; i++)
	{
        printf(" ");
	}
		
	// если после узла два листа не пустые, можем ввести "<"
	if(head->left != NULL && head->right != NULL)
    	printf("%d <\n", head->data);
	else
		printf("%d\n", head->data);
 
	// идем вправо
    print2D(head->left, tab);
}