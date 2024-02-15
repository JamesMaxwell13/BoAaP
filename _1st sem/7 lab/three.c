#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

        while (temp=getchar()!='\n')
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

int	punctCheck(char symbol)
{
	char punct[]={" ,.?!;:"};
	for(int j=0;j<strLen(punct)+1;j++)
		if(symbol==punct[j])
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

int	letterCheck(char symbol)
{
	char letter[]={"ЁЙФЯЦЫЧУВСКАМЕПИНРТГОЬШЛБЩДЮЗЖХЭЪёйфяцычувскамепинртгоьшлбщдюзжхQAZWSXEDCRFVTGBYHNUJMIKOLPqazwsxedcrfvtgbyhnujmikolp"};
	for(int j=0;j<strLen(letter)+1;j++)
		if(symbol==letter[j])
			return 1;
	return 0;
} 

int classicWords(char *str)
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

int inputInt()
{
	int scn=0;
    int num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%d",&num);
        while (temp=getchar()!='\n')
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

void wordsInsertionSort(char **str,int size)
{
	int choose;
	printf("Choose way of counting words: ");
	choose=inputInt();

    int i, j;
	char *key;
    for (i = 1; i < size; i++)
    {
        key = str[i];
        j = i - 1;
		if(choose==1)
		{
        	while (j >= 0 && classicWords(str[j]) > classicWords(key))
	        {
    	        str[j + 1] = str[j];
        	    j--;
        	}
		}
		else
		{
			while (j >= 0 && anyWords(str[j]) > anyWords(key))
	        {
    	        str[j + 1] = str[j];
        	    j--;
        	}
		}
        str[j + 1] = key;
    }
	if(choose==1)
		for(int i=0;i<size;i++)
			printf("%d: %s\n",classicWords(str[i]),str[i]);
	else
		for(int i=0;i<size;i++)
			printf("%d: %s\n",anyWords(str[i]),str[i]);
}

int main()
{
	system("chcp 1251");
	int stop=0;
	while(stop!=-1)
	{
		scanf("%d",&stop);
		char **str;
		int size;
		printf("Enter size of array: ");
		size=inputPosInt();
		str=(char**)malloc(size*1);
		for(int i=0;i<size;i++)
		{
			str[i]=(char*)malloc(1*1);
			printf("%d string: ",i+1);
			getStr(str[i]);
		}

		wordsInsertionSort(str, size);

		for(int i=0;i<size;i++)
			printf("%d: %s\n",classicWords(str[i]),str[i]);
		for(int i=0;i<size;i++)
			printf("%d: %s\n",anyWords(str[i]),str[i]);
	}
	return 0;
}