#include "funcs.h"

// Необходимо выбрать любую функцию хеширования. 
// Далее найти базу данных с строками, желательно именами. 
// Сохранить себе часть или полную версию в файл. 
// Стоит ограничить максимальный размер хеш-таблицы 
// и учитывать это при хешировании для увеличения скорости доступа. 

// Каждой строке назначить случайный ір адрес и порт. 
// В программе изначально данные не подгружены. 

// Пользователю предлагать:

//  - загрузить N следующих строк (N вводит пользователь) 
//  - добавить свою строку
//  - удалить строку по ее содержимому 
//  - найти ір адрес по введенной строке

// В некоторых случаях могут произойти коллизии, 
// их обработка часть лабораторной и также обязательна. 
// Метод обработки выбирается самостоятельно. 
// Примером может служить метод цепочек/списков.

typedef struct Node 
{
	char key[256];
	char value[256];
	struct Node* next;
} node;

void setNode(node *node, char* key, char* value)
{
	strncpy(node->key, key, 256);
	strncpy(node->value, value, 256);
	node->next = NULL;
	return;
}

typedef struct hashMap 
{
	int numOfElements, capacity;
	node **arr;
} hashmap;

void initializeHashMap(hashmap *map)
{
	map->capacity = 256;
	map->numOfElements = 0;
	map->arr = (node**)malloc(map->capacity * sizeof(node*));
	for(int i = 0; i < map->capacity; i++)
		map->arr[i] = NULL;
	return;
}

int hashFunction(hashmap* map, char* key)
{
	int bucketIndex;
	int sum = 0, factor = 31;
	for (int i = 0; i < (int)strlen(key); i++) 
	{
		// sum = sum + (ASCII value of char * (primeNumber ^ x))... where x = 1, 2, 3....n
		sum = ((sum % map->capacity) + (((int)key[i]) * factor) % map->capacity) % map->capacity;
		// factor = factor * prime number....(prime number) ^ x
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
	}

	bucketIndex = sum;
	return bucketIndex;
}

void insert(hashmap* mp, char* key, char* value)
{
	int bucketIndex = hashFunction(mp, key);
	node *newNode = (node*)malloc(sizeof(node));
	setNode(newNode, key, value);
	printf("index - %d, key - %s , value - %s\n", bucketIndex, key, value);
	if (mp->arr[bucketIndex] == NULL) 
		mp->arr[bucketIndex] = newNode;
	else 
	{
		newNode->next = mp->arr[bucketIndex];
		mp->arr[bucketIndex] = newNode;
	}
	return;
}

void delete(hashmap* mp, char* key)
{
	int bucketIndex = hashFunction(mp, key);
	node* prevNode = NULL;
	node* currNode = mp->arr[bucketIndex];

	while (currNode != NULL) 
	{
		if (strcmp(key, currNode->key) == 0) 
		{
			if (currNode == mp->arr[bucketIndex]) 
				mp->arr[bucketIndex] = currNode->next;
			else 
				prevNode->next = currNode->next;
			free(currNode);
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	return;
}

char* search(hashmap* mp, char* key)
{
	int bucketIndex = hashFunction(mp, key);
	node *bucketHead = mp->arr[bucketIndex];
	
	// printf("bucketHead: index - %d, key - %s, value - %s\n", bucketIndex, bucketHead->key, bucketHead->value);
	while (bucketHead != NULL) 
	{
		if (strcmp(bucketHead->key, key) == 0)
			return bucketHead->value;

		bucketHead = bucketHead->next;
	}
	
	char* errorMssg = (char*)malloc(sizeof(char) * 23);
	errorMssg = "ERROR! No data found.\n";
	return errorMssg;
}

void loadValue(hashmap *map, FILE *fp, int size)
{
	char key[256], value[256];
	for(int i = 0; i < size && !feof(fp); i++)
	{
		fscanf(fp, "%s%s", key, value);
		printf("key - %s, value - %s\n", key, value);
		insert(map, key, value);
	}
}

enum choose
{
	stop = 0,
	database = 1,
	uinsert,
	del,
	IPsearch,
};

int main()
{
	FILE *fp;
	if((fp = fopen("base.txt", "r")) == NULL) {
        printf("ERROR... Something gets wrong\nPress ENTER to continue...\n");
        getch();
        exit(0);
    }
	hashmap* map = (hashmap*)malloc(sizeof(hashmap));
	initializeHashMap(map);
	
	printf(	"Create your own hash table using any hash function.\n"
			"Load from file site names with coresponding IP adresses.\n"
			"By the user request do next operations...\n");
	while(1)
	{
		printf( "\n\t1 - Load N strings from database\n"
				"\t2 - Add users own string\n"
				"\t3 - Delete string from table by its value\n"
				"\t4 - Find IP adress by entered string\n"
				"\t0 - Stop exicute program\n\n");
		enum choose chs = inputPos_Null();
		printf("\n");
		switch(chs)
		{
			case database:
			{
				printf("Enter amount of loaded strings (max - 256)\n");
				int size = inputPosInt();
				loadValue(map, fp, size);

				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case uinsert:
			{
				printf("Enter your site name with IP to insert it into table:\n");
				char value[256], key[256];
				printf("Enter name:\n");
				s_gets(key, 256);
				printf("Enter IP:\n");
				s_gets(value, 256);
				insert(map, key, value);

				printf("Search check:\n");
				printf("IP adress from key %s:  %s\n", key, search(map, key));

				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case del:
			{
				printf("Enter the key (sitename) to delete string from table:\n");
				char key[256];
				printf("Enter name:\n");
				s_gets(key, 256);
				delete(map, key);

				printf("Search check:\n");
				printf("IP adress from key %s:  %s\n", key, search(map, key));

				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case IPsearch:
			{
				printf("Enter the key (sitename) to find string in table:\n");
				char key[256];
				printf("Enter name:\n");
				s_gets(key, 256);
				printf("IP adress from key %s:  %s\n", key, search(map, key));
				printf("\nPress ENTER to continue...\n");
				getch();
				break;
			}
			case stop:
			{
				printf("Stoping program...\n");
				printf("\nPress ENTER to continue...\n");
				getch();
				exit(0);
				break;
			}
			default:
			{
				printf("\nERROR... Something gets wrong...\nPress ENTER to continue...\n");
				getch();
				break;
			}
		}
	}
	return 0;
}


	// insert(map, "Yogaholic", "Anjali");
	// insert(map, "pluto14", "Vartika");
	// insert(map, "elite_Programmer", "Manish");
	// insert(map, "GFG", "GeeksforGeeks");
	// insert(map, "decentBoy", "Mayank");

	// printf("%s\n", search(map, "elite_Programmer"));
	// printf("%s\n", search(map, "Yogaholic"));
	// printf("%s\n", search(map, "pluto14"));
	// printf("%s\n", search(map, "decentBoy"));
	// printf("%s\n", search(map, "GFG"));

	// // Key is not inserted
	// printf("%s\n", search(map, "randomKey"));

	// printf("\nAfter deletion : \n");

	// // Deletion of key
	// delete (map, "decentBoy");
	// printf("%s\n", search(map, "decentBoy"));