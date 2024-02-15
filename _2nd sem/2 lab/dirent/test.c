#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <dir.h>
// char *strCopy(char *first, char *scnd)
// {
//     int size1 = strLen(first);
//     int size2 = strLen(scnd);
//     char *str = (char*)malloc(size1 + size2 + 1);
//     for(int i = 0; i < size1; i++)
//         str[i] = first[i];
// 	for(int i = size1; i < size1 + size2; i++)
// 		str[i] = scnd[i - size1];
//     str[size1 + size2] = '\0';
// 	return str;
// }

int main()
{
	rmdir("D:/programming/labs/_2nd sem/dirent/foldertxt");
	getch();
	return 0;
}