#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
            {
				num++;
            }
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
	if((symbol>='A' && symbol<='Z') || (symbol>='a' && symbol<='z') || (symbol>='�' && symbol<='�') || (symbol>='�' && symbol<='�'))
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
            {
				num++;
            }
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

void reverse(char *str, int begin, int end)
{
	char temp;
	if(end>begin)
		{
			temp=str[begin];
			str[begin]=str[end];
			str[end]=temp;
			reverse(str,begin+1,end-1);
		}
}

void swapString(char *str,int begin1,int end1,int begin2,int end2)
{
	reverse(str,begin1,end2);
	reverse(str,begin1,end2-begin2);
	reverse(str,end2-end1,end2);
	reverse(str,end2-begin2+1,end2-end1-1);
}

int strCmp(char *str1, char *str2)
{
	int i=0;
	do
	{
		if(str1[i]-str2[i]!=0)
			return str1[i]-str2[i];
		i++;
	}
	while(str1[i]!='\0');
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

int** fillMatrix(int **arr,int size1,int size2)
{
    int choose=0;
    srand(time(NULL));
    while(1)
    {
            printf("Choose way of array filling(1-for user input, 2-for random filling): ");
            choose = inputPosInt();
                if (choose == 1) {
                    for(int i=0;i<size1;i++)
                    {
                        printf("Enter %d row of array: ",i+1);
                        for(int j=0;j<size2;j++)
                        {
                            arr[i][j]=inputInt();
                        }
                    }
                    break;
                }

                    if (choose == 2)
                    {
                        for(int i=0;i<size1;i++)
                        {
                            for(int j=0;j<size2;j++)
                            {
                                arr[i][j]=rand()%201-100;
                                printf("%4d",arr[i][j]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                        break;
                    }

                    else
                    {
                        printf("Wrong input\n");
                        system("cls");
                    }
    }
	return arr;
}

int* fillArr(int *arr,int size)
{
    int choose=0;
    srand(time(NULL));
    while(1)
    {
            printf("Choose way of array filling(1-for user input, 2-for random filling): ");
            choose = inputPosInt();
                if (choose == 1) {
                    printf("Enter array: \n");
                    for(int i=0;i<size;i++)
                    {
                            arr[i]=inputInt();
                    }
                    break;
                }

                    if (choose == 2)
                    {
                        for(int i=0;i<size;i++)
                        {
                            arr[i]=rand()%201-100;
                            printf("%4d",arr[i]);
                        }
                        printf("\n");
                        break;
                    }

                    else
                    {
                        printf("Wrong input\\n");
                        system("cls");
                    }
    }
	return arr;
}

void printArr(int *arr,int size)
{
    for(int i=0;i<size;i++)
        printf("%4d",arr[i]);
}

void printMatrix(int **arr,int size1,int size2)
{
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
            printf("%4d",arr[i][j]); 
        printf("\n");
    }
}

void bubbleSort(int *arr,int size)
{
    int buff=0;
    for(int i=0;i<size;i++) // выбор верхней границы маѝѝива
    {
        for(int j=size-1;j>i;--j) // проѝмотр маѝѝива ”ѝнизу” ”вверх”
	    {
            if(arr[j-1]>arr[j]) // уѝловие замены выполнено
            {
            buff=arr[j-1]; // замена j-1 и j ѝлементов
            arr[j-1]=arr[j];
            arr[j]=buff;
            }
        }
    }
}

void ShellSort(int *arr,int size)
{   
    int flg;
    int buff;
    for(int gap = size/2; gap > 0; gap /= 2)
        do 
        {
            flg = 0;
            for(int i = 0, j = gap; j < size; i++, j++)
                if(arr[i] > arr[j]) // ѝравниваем отѝтоѝщие на gap 	ѝлементы
                { 
                    buff = arr[j];
                    arr[j] = arr[i];
                    arr[i]= buff;
                    flg = 1; // еѝть еще не раѝѝортированные данные
                }
        } 
        while (flg!=0); // окончание ѝтапа ѝортировки
}

void insertionSort(int *arr,int size)
{
int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int *arr,int size)
{
    int buff;
    int min;
    for(int i=0;i<size-1; i++) // выбор иѝходного ѝлемента к ѝравнению
    { 
        min=i; 
        for(int j=i+1; j<size; j++) // проѝмотр маѝѝива ”ѝнизу” ”вверх”
            if(arr[min]>arr[j]) 
            {
                min=j; // фикѝируем координату ѝлемента в маѝѝиве
                buff=arr[i]; // замена min и i ѝлементов
                arr[i]=arr[min];
                arr[min]=buff;
            }
    }
}

void mergeSort(int *arr, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);   
        mergeSort(arr, m + 1, r);

		int i, j, k;

		int n1 = m - l + 1;
		int n2 = r - m;
		
		int *L, *R;
		L=(int*)malloc(n1*sizeof(int));
		R=(int*)malloc(n2*sizeof(int));
		
		for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
		for (j = 0; j < n2; j++)            
		R[j] = arr[m + 1 + j];           
		
		i = 0; 
		j = 0; 
		k = l; 
		while (i < n1 && j < n2) 
		{
			if (L[i] <= R[j]) 
			{
				arr[k] = L[i];
				i++;
			}
			else 
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}
	
		while (i < n1) 
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) 
		{
			arr[k] = R[j];
			j++;
			k++;
		}

		free(L);
		free(R);
    }
}

void HoarSort(int *arr, int l, int r) 
{
    int i, j, temp;
    int sr = arr[(l + r) / 2]; 
    i = l; 
    j = r; 
    
    do
    {
    	while (arr[i] < sr) 
        i++;                        // ищем слева элемент больше среднего
        	while (arr[j] > sr) 
            j--;                    // ищем справа элемент меньше среднего
            	if (i <= j)         // если левая граница не прошла за правую
            	{
        	    	temp = arr[i]; 
        		    arr[i] = arr[j];
        		    arr[j] = temp;
                    i++; 
                    j--; 
        	    }
    } 
    while (i <= j);                 // пока границы не совпали
        
        if (i < r) 
        	HoarSort(arr, i, r); 
        if (j>l)  
        	HoarSort(arr, l, j); 
}