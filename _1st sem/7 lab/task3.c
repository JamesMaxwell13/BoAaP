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

// int i, key, j;
// for (i = 1; i < size; i++)
// {
//     key = arr[i];
//     j = i - 1;
//     while (j >= 0 && arr[j] > key)
//     {
//         arr[j + 1] = arr[j];
//         j--;
//     }
//     arr[j + 1] = key;
// }

int	letterCheck(char symbol)
{
	char letter[]={"¨ÉÔßÖÛ×ÓÂÑÊÀÌÅÏÈÍĞÒÃÎÜØËÁÙÄŞÇÆÕİÚ¸éôÿöû÷óâñêàìåïèíğòãîüøëáùäşçæõQAZWSXEDCRFVTGBYHNUJMIKOLPqazwsxedcrfvtgbyhnujmikolp"};
	for(int j=0;j<strLen(letter)+1;j++)
		if(symbol==letter[j])
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
void wordsInsertionSort(char **str,int size)
{
    int i, j;
	char *key;
    for (i = 1; i < size; i++)
    {
        key = str[i];
        j = i - 1;
        while (j >= 0 && words(str[j]) > words(key))
        {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
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
			printf("%d: %s\n",words(str[i]),str[i]);
	}
	return 0;
}


// char** getArrStr(char **string, int size)
// { 
//     int i=0;
// 	for(int j=0;j<size;j++)
// 	{
// 		printf("%d ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½: ",j+1);
// 		rewind(stdin);
// 		while( (string[j][i++] = getchar())!= '\n')
// 			string[j]=(char*)realloc(string[j],i+1);
// 		string[j][i] = '\0';
// 	}
//     return string;    
// }


		// int *words;
		// words=(int*)calloc(size,sizeof(int));
		// for(int i=0;i<size;i++)
		// {
		// 	int j=0;
		// 	while(str[i][j]!='\0')
		// 	{
		// 		if(str[i][j]==' ' || str[i][j]=='.' || str[i][j]==',' || str[i][j]==';')
		// 			words[i]++;
		// 		j++;
		// 	}
		// }
		// int *newwords;
		// newwords=(int*)calloc(size,sizeof(int));
		// for(int i=0;i<size;i++)
		// 	newwords[i]=words[i];