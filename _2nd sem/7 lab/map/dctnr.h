#pragma once
#include "funcs.h"

typedef struct Leaf
{
	char word[128];
	char translate[128];
	struct Leaf *left;
	struct Leaf *right;
} leaf;

typedef struct Word
{
	char key[128];
	char value[128];
} word;

leaf *newLeaf(word exempl)
{
	leaf *tmp = (leaf*)malloc(sizeof(leaf));
	tmp->left = tmp->right = NULL;
	strncpy(tmp->word, exempl.key, 128);
	strncpy(tmp->translate, exempl.value, 128);
	printf("key - %s\nvalue - %s\n", tmp->word, tmp->translate);
	return tmp;
}

leaf *makeInf(word *warr, int first, int last)
{
	if(first > last)
		return NULL;

	int mid = (first + last) / 2;
	leaf *head = newLeaf(warr[mid]);

	head->left = makeInf(warr, first, mid - 1);
	head->right = makeInf(warr, mid + 1, last);
	return head;
}

leaf *search(leaf *head, word exemplr)
{
	if(head == NULL || strcmp(head->word, exemplr.key) == 0)
		return head;
	if(strcmp(head->word, exemplr.key) < 0)
		return search(head->right, exemplr);

	return search(head->left, exemplr);
}

leaf *insert(leaf *head, word exempl)
{
	if(head == NULL)
		return newLeaf(exempl);
	if(strcmp(exempl.key, head->word) < 0)
		head->left = insert(head->left, exempl);
	else
		head->right = insert(head->right, exempl);
	return head;
}