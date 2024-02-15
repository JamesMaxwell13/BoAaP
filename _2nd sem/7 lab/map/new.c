#include "funcs.h"
#include "windows.h"

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

leaf *newLeaf(char *key, char *value)
{
	leaf *tmp = (leaf*)malloc(sizeof(leaf));
	tmp->left = NULL;
	tmp->right = NULL;
	printf("key - %s value - %s\n", key, value);
	strncpy(tmp->word, key, 128);
	strncpy(tmp->translate, value, 128);
	// tmp->word = key;
	// tmp->translate = value;
	return tmp;
}

leaf *makeInf(word *warr, int first, int last)
{
	if (first > last)
		return NULL;

	int mid = (first + last) / 2;
	printf("key - %s value - %s\n", warr[mid].key, warr[mid].value);
	leaf *head = newLeaf((warr+mid)->key, (warr+mid)->value);

	head->left = makeInf(warr, first, mid - 1);
	head->right = makeInf(warr, mid + 1, last);
	return head;
}

leaf *search(leaf *head, char *key)
{
	if (head == NULL || strcmp(head->word, key) == 0)
		return head;
	if (strcmp(head->word, key) < 0)
		return search(head->right, key);

	return search(head->left, key);
}

leaf *insert(leaf *head, word exempl)
{
	if (head == NULL)
		return newLeaf(exempl.key, exempl.value);
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

word *getData(FILE *fp, int size)
{
	printf("%d - size\n", size);
	word *warr = (word *)malloc(size * sizeof(word));
	for (int i = 0; i < size; i++)
	{
		warr[i] = getWord(fp);
	}   
	printf("key - %s value - %s\n", warr[1].key, warr[1].value);
	return warr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE *fp;
	if ((fp = fopen("dictionary.txt", "r")) == NULL)
	{
		printf("ERROR... Something gets wrong\nPress ENTER to continue...\n");
		getch();
		exit(0);
	}

	int size = fileSize(fp);
	// word exm;// = getWord(fp);
	// strncpy(exm.key, "абоба", 128);
	// strncpy(exm.value, "translate", 128);
	leaf *root = makeInf(getData(fp, size), 0, size-1);
	//word buf = getWord(fp);
	//root = newNode(buf);
	//printf("слово - %s, перевод - %s\n", root->word, root->translate);
	while (1)
	{
		char key[128];
		printf("Слово:\n");
		s_gets(key, 128);
		leaf *buff = search(root, key);
		printf("Перевод: %s\n", buff->translate);
		printf("Продолжить? (0 - стоп)\n");
		if (inputInt() == 0)
			break;
	}
	getch();
	return 0;
}