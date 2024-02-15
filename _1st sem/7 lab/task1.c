#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void getStr(char *string)
{ 
	do
	{
		rewind(stdin);
	    int i=0;
    	while( (string[i++] = getchar())!= '\n')
			string=(char*)realloc(string,i+1);
    	string[i-1] = '\0';
		if (string[0]=='\0')
			printf("Please, enter normal string\n");
		  
	}
	while(string[0]=='\0');
}

int strLen(char *s)
{
	int i=0;
	while (s[i]!='\0')
		i++;
	return i;
}


int main()
{
	system("chcp 1251");
	int stop=0;
	while(stop!=-1)
	{
		scanf("%d",&stop);
		char *str;
		int n=1;
		str=(char*)calloc(n,1);
		getStr(str);
		n=strLen(str);
		for(int i=0;i<=n;i++)
		{
			if((str[i]>='A' && str[i]<='Z') || (str[i]>='À' && str[i]<='ß'))
			{
				str[i]+=32;
				continue;
			}
			if((str[i]>='a' && str[i]<='z') || (str[i]>='à' && str[i]<='ÿ'))
				str[i]-=32;
		}
		printf("%s",str);
		//printf("%d\n",n);
	}
	return 0;
}