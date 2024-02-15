#include <stdio.h>
#include <stdlib.h>

void getStr(char *string)
{ 
	rewind(stdin);
    int i=0;
    while( (string[i++] = getchar())!= '\n')
		string=(char*)realloc(string,i+1);
    string[i-1] = '\0';   
}

int strLen(char *s)
{
	int i=0;
	while (s[i]!='\0')
		i++;
	return i;
}

int	punctCheck(char symbol)
{
	char punct[]={" ,.?!;:"};
	for(int j=0;j<strLen(punct)+1;j++)
		if(symbol==punct[j])
			return 1;
	return 0;
} 

int words(char *str)
{
	int num=0; 
	int i=0;
	int early=1;
	while(str[i]!='\0')
	{
		if(punctCheck(str[i])==1 || str[i]=='\0')
		{
			if(early==0)
				num++;
				early=1;
		}
		else
			early=0;

		i++;
	}
	if(punctCheck(str[i-1])==0)
		num++; 
	return num;
}

// int	letterCheck(char symbol)
// {
// 	char letter[]={"¨ÉÔßÖÛ×ÓÂÑÊÀÌÅÏÈÍÐÒÃÎÜØËÁÙÄÞÇÆÕÝÚ¸éôÿöû÷óâñêàìåïèíðòãîüøëáùäþçæõQAZWSXEDCRFVTGBYHNUJMIKOLPqazwsxedcrfvtgbyhnujmikolp"};
// 	for(int j=0;j<strLen(letter)+1;j++)
// 		if(symbol==letter[j])
// 			return 1;
// 	return 0;
// } 

int	letterCheck(char symbol)
{
	if((symbol>='A' && symbol<='Z') || (symbol>='a' && symbol<='z') || (symbol>='À' && symbol<='ß') || (symbol>='à' && symbol<='ÿ'))
		return 1;
	return 0;
}  

int anyWords(char *str)
{
	int num=0; 
	int i=0;
	int early=1;
	while(str[i]!='\0')
	{
		if(letterCheck(str[i])==0 || str[i]=='\0')
		{
			if(early==0)
				num++;
				early=1;
		}
		else
			early=0;

		i++;
	}
	if(letterCheck(str[i-1])==1)
		num++;
	return num;
}


int main()
{
	system("chcp 1251");
	int stop=0;
	while(stop!=-1)
	{
		scanf("%d",&stop);
		char *str;
		str=(char*)calloc(1,1);
		getStr(str);
		
		printf("%d: %s\n",words(str),str);
		printf("%d: %s\n",anyWords(str),str);
	}
	return 0;
}