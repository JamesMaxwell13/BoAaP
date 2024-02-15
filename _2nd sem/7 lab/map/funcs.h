#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

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

bool endArr(char str[], int i)
{
	while(str[i] != '\0' && str[i] != '\n')
	{
		if(str[i] > '0' && str[i] < '9')
			return false;
		i++;
	}
	return true;
}

int getArr(int *arr)
{
	char str[256];
	bool in;
	do
	{
		in = true;
		int i = 0;
		fgets(str, 256, stdin);
		while(str[i] != '\n')
		{
			if((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			{
				in = false;
				printf("wrong input\n");
				break;
			}
			i++;
		}
	} 
	while (in == false);

	char buff[256];
	int size = 0, i = 0, bgn;
	bool num = false;
	while(1)
	{
		if(str[i] >= '0' && str[i] <= '9' && num == false)
		{	
			num = true;
			bgn = i;
		}
		else
			if(num == true && (str[i] < '0' || str[i] > '9'))
			{
				int k = 0;
				for(int j = bgn; j < i; j++, k++)
					buff[k] = str[j];
				buff[k] = '\0';
				arr[size] = atoi(buff);
				size++;
				num = false;
				if(endArr(str, i) == false)
					arr = (int*)realloc(arr, (size + 1)*sizeof(int));
			}
		if(str[i] == '\0')
			break;
		i++;
	}
	return size;
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

int inputBool()
{
    
	int scn = 0;
    int num = 0;
	char temp;
    do
    {
		rewind(stdin);
        scn = scanf("%d",&num);
        while ((temp=getchar()) != '\n')
        if(scn != 1 || temp > '2' || temp < '0')
		{
            printf("Wrong input");
			scn = 0;
			break;
		}
    }
    while(scn != 1);
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

void file_gets(FILE *fp, char *str, int n)
{
    int i = 0;
    fgets(str, n, fp);
    while(str[i] != '\n' && str[i] != '\0')
        i++;
    if(str[i] == '\n')
        str[i] = '\0';
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

bool prime(int num)
{
    for(int i = 2; i*i <= num; i++)
        if(num % i == 0 || num == 0)
            return false;
    return true;
}

bool even(int num)
{
    if(num % 2 == 1 || num == 0)
        return false;
    else
        return true;
}

int max(int *arr, int strt, int end)
{
    int i, max = arr[strt], mi = strt;
    for(i = strt + 1; i <= end; i++)
        if(arr[i] > max)
        {
            max = arr[i];
            mi = i;
        }
    return mi;
}

void ShellSort(int *arr, int size) 
{
    int flg, temp;
    for(int gap = size/2; gap > 0; gap /= 2) 
    {
        do 
        { 
            flg=0;
            for(int i = 0, j = gap; j < size; i++, j++) 
                if(arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    flg=1; }
                } 
        while(flg!=0);
    } 
}