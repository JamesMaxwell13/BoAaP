#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* getStr(char *string)
{ 
	rewind(stdin);
    int i=0;
    while( (string[i++] = getchar())!= '\n')
		string=(char*)realloc(string,i+1);
    string[i] = '\0';
    return string;    
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

// Дано целое число N (> 0) и строка S. Преобразовать строку S в строку длины N
// следующим образом: если длина строки S больше N, то отбросить первые
// символы, если длина строки S меньше N, то в ее начало добавить символы «.».
int main()
{
	system("chcp 1251");
	int stop=0;
	while(stop!=-1)
	{
		scanf("%d",&stop);
		char *str;
		int size=1;
		str=(char*)calloc(size,1);
		str=getStr(str);
		size=strLen(str);

		int n;
		n=inputPosInt();

		if(size>n)
		{
			while(size!=n)
			{
				for(int i=0;i<=size;i++)
					str[i]=str[i+1];
				size--;
				str=(char*)realloc(str,size+1);
			}
		}

		if(size<n)
		{
			while(size!=n)
			{
				size++;
				str=(char*)realloc(str,size+1);
				for(int i=size;i>0;i--)
					str[i]=str[i-1];
				str[0]='.';
			}
		}
		printf("%s",str);
	}
	return 0;
}