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


leaf *newNode(char *key, char *value)
{
	leaf *tmp = (leaf*)malloc(sizeof(leaf));
	tmp->left = NULL;
	tmp->right = NULL;
	strncpy(tmp->word, key, 128);
	strncpy(tmp->translate, value, 128);
	printf("key - %s value - %s\n", tmp->word, tmp->translate);
	return tmp;
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

word strSep(char str[256], char app[128])
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

	word prot;
	strncpy(prot.key, str, 128);
	strncpy(prot.value, buff, 128);
	return prot;	
}

word *getData(FILE *fp, int size)
{
	char key[256], value[128];
	word *dictionary = (word*)malloc(size*sizeof(word));
	printf("Reading...\n");
	for(int i = 0; i < size; i++)
	{
		file_gets(fp, key, 256);
		dictionary[i] = strSep(key, value);
		printf("%d) key - %s value - %s\n", i, key, value);
	}
	return dictionary;
}

leaf *makeInf(word *warr, int first, int last)
{
	if (first > last)
		return NULL;

	int mid = (first + last) / 2;
	leaf *head = newNode(warr[mid].key, warr[mid].value);

	head->left = makeInf(warr, first, mid - 1);
	head->right = makeInf(warr, mid + 1, last);
	return head;
}

word *ShellSortWord(word *arr, int size)
{   
    int flg;
    word buff;
    for(int gap = size/2; gap > 0; gap /= 2)
	{
        do 
        {
            flg = 0;
            for(int i = 0, j = gap; j < size; i++, j++)
                if(strcmp(arr[i].key, arr[j].key) > 0)         // ���������� ��������� �� gap 	��������
                { 
                    buff = arr[j];
                    arr[j] = arr[i];
                    arr[i]= buff;
                    flg = 1;                // ���� ��� �� ���������������� ������
                }
        } 
        while (flg!=0);      
	}
	return arr;               // ��������� ����� ����������
}

word *bubbleSortWord(word *arr,int size)
{
    word buff;
    for(int i = 0; i < size-1; i++)                 // ����� ������� ������� �������
    {
        for(int j = 0; j > size-i-1; j++)           // �������� ������� ������ �������
	    {
            if(strcmp(arr[j].key, arr[j+1].key) > 0)             // ������� ������ ���������
            {
                buff = arr[j-1];                  // ������ j-1 � j ���������
                arr[j-1] = arr[j];
                arr[j] = buff;
            }
        }
    }
	return arr;
}

leaf *search(leaf *head, word exemplr)
{
	if (head == NULL || strcmp(head->word, exemplr.key) == 0)
		return head;
	if (strcmp(head->word, exemplr.key) < 0)
		return search(head->right, exemplr);
	return search(head->left, exemplr);
}

void printWords(word *arr, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d) key - %s value - %s\n", i, arr[i].key, arr[i].value);
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
	word *dictionary = getData(fp, size);
	dictionary = bubbleSortWord(dictionary, size);
	printf("After sorting:\n");
	printWords(dictionary, size);

	printf("Build BST\n");
	leaf *root = makeInf(dictionary, 0, size-1);
	while (1)
	{
		word find;
		char key[128];
		printf("�����:\n");
		s_gets(key, 128);
		leaf *buff = search(root, find);
		printf("�������: %s\n", buff->translate);
		printf("����������? (0 - ����)\n");
		if (inputInt() == 0)
			break;
	}
	
	getch();
	return 0;
}

