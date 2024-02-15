#include "funcs.h"
#include <windows.h>

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

leaf *newNode(word exempl)
{
	leaf *tmp = (leaf *)malloc(sizeof(leaf));
	tmp->left = tmp->right = NULL;
	strncpy(tmp->word, exempl.key, 128);
	strncpy(tmp->translate, exempl.value, 128);
	printf("key - %s\nvalue - %s\n", tmp->word, tmp->translate);
	return tmp;
}

leaf *makeInf(word *warr, int first, int last)
{
	if (first > last)
		return NULL;

	int mid = (first + last) / 2;
	leaf *head = newNode(warr[mid]);

	head->left = makeInf(warr, first, mid - 1);
	head->right = makeInf(warr, mid + 1, last);
	return head;
}

leaf *search(leaf *head, word exemplr)
{
	if (head == NULL || strcmp(head->word, exemplr.key) == 0)
		return head;
	if (strcmp(head->word, exemplr.key) < 0)
		return search(head->right, exemplr);

	return search(head->left, exemplr);
}

leaf *insert(leaf *head, word exempl)
{
	if (head == NULL)
		return newNode(exempl);
	if (strcmp(exempl.key, head->word) < 0)
		head->left = insert(head->left, exempl);
	else
		head->right = insert(head->right, exempl);
	return head;
}

int fileSize(FILE *fp)
{
	fseek(fp, 0, SEEK_SET);
	int size = 0;
	char buff[256];
	while (!feof(fp))
	{
		fgets(buff, 256, fp);
		size++;
	}
	fseek(fp, 0, SEEK_SET);
	return size;
}

void strSep(char str[256], char app[128])
{
	char *buff;
	buff = strtok(str, "=");
	buff = strtok(NULL, "=");
	strcpy(app, buff);
	int i;
	for (i = 0; i < 256; i++)
		if (str[i] == '=')
			break;
	str[i] = '\0';
	printf("key - %s\nvalue - %s\n", str, app);
}

word getWord(FILE *fp)
{
	char key[256], value[128];
	file_gets(fp, key, 256);
	strSep(key, value);
	word temp;
	strncpy(temp.key, key, 128);
	strncpy(temp.value, value, 128);
	printf("key - %s\nvalue - %s\n", temp.key, temp.value);
	return temp;
}

word *getData(FILE *fp)
{
	int size = fileSize(fp);
	word *warr = (word *)malloc(size * sizeof(word));
	for (int i = 0; i < size; i++)
		warr[i] = getWord(fp);
	return warr;
}

int main()
{
	// system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE *fp;
	if ((fp = fopen("dictionary.txt", "r")) == NULL)
	{
		printf("ERROR... Something gets wrong\nPress ENTER to continue...\n");
		getch();
		exit(0);
	}

	leaf *root;
//	word *warr = getData(fp);
//    int size = fileSize(fp);
//    root = makeInf(warr, 0, size-1);


	word buf = getWord(fp);
	root = newNode(buf); // makeInf(warr, 0, size-1);

	printf("слово - %s, перевод - %s\n", root->word, root->translate);
	while (1)
	{
		word find;
		char key[128];
		printf("Слово:\n");
		s_gets(key, 128);
		leaf *buff = search(root, find);
		printf("Перевод: %s\n", buff->translate);
		printf("Продолжить? (0 - стоп)\n");
		if (inputInt() == 0)
			break;
	}
	getch();
	return 0;
}

// char key[256], value[128];
// file_gets(fp, key, 256);
// strSep(key, value);
// printf("%s = %s\n", key, value);
// printf("size = %d\n", fileSize(fp));
// leaf *root = NULL;
// int *arr = (int*)malloc(sizeof(int));
// int size = getArr(arr);
// root = makeInfB(arr, 0, size-1);
// print2D(root, 1);