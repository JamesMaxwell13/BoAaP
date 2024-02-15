#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int inputPosInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);

		if(scn!=1 || num<=0)
		{
            printf("Wrong input\n");
			scn=0;
			continue;
		}

        while ((temp=getchar())!='\n')
        if(temp>'9' || temp<'0')
		{
            printf("Wrong input\n");
			scn=0;
			break;
		}
    }
    while(num<=0 || scn!=1);
    return num;
}

int inputInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);
        while ((temp=getchar())!='\n')
        if(scn!=1 || temp>'9' || temp<'0')
		{
            printf("Wrong input");
			scn=0;
			break;
		}
    }
    while(scn!=1);
    return num;
}

char *getStr()
{ 
	char *string;
	string = (char*)malloc(1);
	do
    {
	rewind(stdin);
    int i=0;
    while( (string[i++] = getchar())!= '\n')
		string=(char*)realloc(string,i+1);
    string[i-1] = '\0';  
    if(string[0]=='\0')
        printf("You entered empty string, try again\n");
    }
    while(string[0]=='\0');
	return string;
}

int strLen(char *s)
{
	int i=0;
	while (s[i]!='\0')
		i++;
	return i;
}

int	letterCheck(char symbol)
{
	if((symbol>='A' && symbol<='Z') || (symbol>='a' && symbol<='z') || (symbol>='À' && symbol<='ß') || (symbol>='à' && symbol<='ÿ'))
		return 1;
	return 0;
}  

char *strCopy(char *first, char *scnd)
{
    int size1 = strLen(first);
    int size2 = strLen(scnd);
    char *str = (char*)malloc(size1 + size2 + 1);
    for(int i = 0; i < size1; i++)
        {str[i] = first[i];}
	for(int i = size1; i < size1 + size2; i++)
		{str[i] = scnd[i - size1];}
    str[size1 + size2] = '\0';
	return str;
}
