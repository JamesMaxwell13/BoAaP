#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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

int strCmp(char *str1, char *str2)
{
	int i = 0;
	do
	{
		if(str1[i] - str2[i] != 0)
			return str1[i] - str2[i];
		i++;
	}
	while(str1[i] != '\0');
		return 0;
}

double inputDouble()
{
	int scn=0;
    double num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%lf",&num);
		while ((temp=getchar()) != '\n')
		{
			if(scn!=1 || ((temp>'9' || temp<'0') && temp!='.'))
			{
				printf("Wrong input\n");
				scn=0;
				break;
			}
		}
	}
    while(scn!=1);
    return num;
}

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

int inputPos_Null()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);

		if(scn!=1 || num<0)
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
    while(num<0 || scn!=1);
    return num;
}

long int inputPosLong()
{
	int scn=0;
    long int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%ld",&num);

		if(scn!=1 || num<0)
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
    while(num<0 || scn!=1);
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

void s_gets(char *str, int n)
{
    int i = 0;
    fgets(str, n, stdin);
    while(str[i] != '\n' && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        str[i] = '\0' ;
    // else // требуется наличие words[i] == '\0'
    //     while (getchar() != '\n')
    //         continue;
}

void print25(char *str)
{
	if(strLen(str) <= 25)
		printf(" %25s |", str);
	else
	{
		printf(" ");
		for(int i = 0; i < 23; i++)
			putchar(str[i]);
		printf("...|");
	}
}



// unused))))) 

void charToBin(char *name, char *str)
{
    FILE *f;
    f=fopen(name, "wb");
    //char text[255];
    //s_gets(text, 255);

    int i = 0;
    while(str[i] != '\0')
    {
        fwrite(&str[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&str[i], sizeof(char), 1, f);
    fclose(f);
}

void charFromBin(char *name, char *str)
{
    FILE *f;
    f = fopen(name, "rb");
    // char *text;
    // text = (char*)malloc(1);
    fseek(f, 0, SEEK_SET);
    int i = 0;

    while(str[i-1] != '\0') 
    {
        fread(&str[i], sizeof(char), 1, f);
        //text = (char*)realloc(text, i+2);
        i++;
    }
    // if(text[i-1]=='\0')
    //     printf("YEEEEES\n");
    //free(text);
    //printf("%s\n", text);
    fclose(f);
}

void intToFile(char *name, int num)
{
	FILE *f;
	f=fopen(name, "w+b");
	fwrite(&num, sizeof(int), 1, f);
	fclose(f);
}
