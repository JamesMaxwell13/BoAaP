#pragma once
#include "funcs.h"

typedef struct Leaf
{
	char word[128];
	char translate[128];
	struct Leaf *left;
	struct Leaf *right;
} leaf;

leaf *newLeaf(char *word)
{
	leaf *tmp = (leaf*)malloc(sizeof(leaf));
	tmp->left = tmp->right = NULL;
	strncpy(tmp->word, word, 128);
	return tmp;
}


leaf *makePre(char **pre, int first, int last)
{
	if(first > last)
		return NULL;

	leaf *head = newLeaf(pre[first]);

	int i;
	for(i = first; i <= last; i++)
		if(strcmp(pre[first], pre[i]) < 0)
			break;

	head->left = makePre(pre, first+1, i-1);
	head->right = makePre(pre, i, last);
	return head;
}

leaf *makeInf(char **data, int first, int last)
{
	if(first > last)
		return NULL;

	int mid = (first + last) / 2;
	leaf *head = newLeaf(data[mid]);

	head->left = makeInf(data, first, mid - 1);
	head->right = makeInf(data, mid + 1, last);
	return head;
}

int maxChar(char **str, int frst, int lst)
{
	char *max = str[frst],  index = frst;
	for(int i = frst + 1; i <= lst; i++)
		if(strcmp(str[i], max) > 0)
		{
			max = str[i];
			index = i;
		}
	return index;
}

// leaf *makeInfB(char **inord, int first, int last)
// {
// 	if(first > last)
// 		return NULL;

// 	int i = maxChar(inord, first, last);
// 	leaf *head = newLeaf(inord[i]);

// 	head->right = makeInfB(inord, first, i - 1);
// 	head->left = makeInfB(inord, i + 1, last);
// 	return head;
// }

leaf *makePost(char **post, int first, int last)
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


void infPrint(leaf *head)
{
	if (head != NULL) 
	{ 
		infPrint(head->left); 
		printf("%s  ", head->word);
		infPrint(head->right);
  	}
}

void prePrint(leaf *head)
{
	if (head != NULL) 
	{ 
		printf("%s  ", head->word);
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
		printf("%s  ", head->word);
  	}
}

leaf *search(leaf *head, char *key)
{
	if(head == NULL || strcmp(head->word, key) == 0)
		return head;
	if(strcmp(head->word, key) < 0)
		return search(head->right, key);

	return search(head->left, key);
}

leaf *insert(leaf *head, char *key)
{
	if(head == NULL)
		return newLeaf(key);
	if(key < head->word)
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

leaf *delLeaf(leaf *head, char *key)
{
	if(head == NULL)
		return head;
	
	if(key < head->word)
		head->left = delLeaf(head->left, key);
	else
		if(key > head->word)
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
			strncpy(head->word, tmp->word, 128);
			head->right = delLeaf(head->right, tmp->word);
		}
	return head;
}
