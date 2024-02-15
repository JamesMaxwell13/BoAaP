#pragma once
#include "funcs.h"
#define COUNT 5

typedef struct Leaf
{
	int data;
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
	if(head != NULL)
	{
		leaf *tmpl = (leaf*)malloc(sizeof(leaf));
		tmpl->left = tmpl->right = NULL;
		tmpl->data = dl;
		(*head)->left = tmpl;
	}
	return *head;
}

leaf *pushRight(leaf **head, int dr)
{
	if(head != NULL)
	{
		leaf *tmpr = (leaf*)malloc(sizeof(leaf));
		tmpr->left = tmpr->right = NULL;
		tmpr->data = dr;
		(*head)->right = tmpr;
	}
	return *head;
}

leaf *newLeaf(int data)
{
	leaf *tmp = (leaf*)malloc(sizeof(leaf));
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	return tmp;
}


leaf *makePre(int *pre, int first, int last)
{
	if(first > last)
		return NULL;

	leaf *head = newLeaf(pre[first]);

	int i;
	for(i = first; i <= last; i++)
		if(pre[first] < pre[i])
			break;

	head->left = makePre(pre, first+1, i-1);
	head->right = makePre(pre, i, last);
	return head;
}

leaf *makeInf(int *data, int first, int last)
{
	if(first > last)
		return NULL;

	int mid = (first + last) / 2;
	leaf *head = newLeaf(data[mid]);

	head->left = makeInf(data, first, mid - 1);
	head->right = makeInf(data, mid + 1, last);
	return head;
}

leaf *makeInfB(int *inord, int first, int last)
{
	if(first > last)
		return NULL;

	int i = max(inord, first, last);
	leaf *head = newLeaf(inord[i]);

	head->right = makeInfB(inord, first, i - 1);
	head->left = makeInfB(inord, i + 1, last);
	return head;
}

leaf *makePost(int *post, int first, int last)
{
	if(first > last)
		return NULL;

	leaf *head = newLeaf(post[last]);

	int i;
	for(i = last; i >= first; i--)
		if(post[last] > post[i])
			break;

	head->left = makePost(post, i+1, last-1);
	head->right = makePost(post, first, i);
	return head;
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

void infPrint(leaf *head)
{
	if (head != NULL) 
	{ 
		infPrint(head->left); 
		printf("%d  ", head->data);
		infPrint(head->right);
  	}
}

void prePrint(leaf *head)
{
	if (head != NULL) 
	{ 
		printf("%d  ", head->data);
		prePrint(head->left); 
		prePrint(head->right);
  	}
}

void postPrint(leaf *head)
{
	if (head != NULL) 
	{ 
		postPrint(head->left); 
		postPrint(head->right);
		printf("%d  ", head->data);
  	}
}

leaf *search(leaf *head, int key)
{
	if(head == NULL || head->data == key)
		return head;
	if(head->data < key)
		return search(head->right, key);

	return search(head->left, key);
}

leaf *insert(leaf *head, int key)
{
	if(head == NULL)
		return newLeaf(key);
	if(key < head->data)
		head->left = insert(head->left, key);
	else
		head->right = insert(head->right, key);
	return head;
}

leaf *minLeaf(leaf *head)
{
	leaf *buff = head;
	while(buff && buff->left != NULL)
		buff = buff->left;
	return buff;
}

leaf *delLeaf(leaf *head, int key)
{
	if(head == NULL)
		return head;
	
	if(key < head->data)
		head->left = delLeaf(head->left, key);
	else
		if(key > head->data)
			head->right = delLeaf(head->right, key);
		else
		{
			if(head->left == NULL)
			{
				leaf *tmp = head->right;
				free(head);
				return tmp;
			}
			else
			if(head->right == NULL)
			{
				leaf *tmp = head->left;
				free(head);
				return tmp;
			}

			leaf *tmp = minLeaf(head->right);
			head->data = tmp->data;
			head->right = delLeaf(head->right, tmp->data);
		}
	return head;
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