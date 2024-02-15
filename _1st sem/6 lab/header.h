#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

double inputDouble()
{
	int scn=0;
    double num=0;
	char temp;
    do
    {
		rewind(stdin);
        scn=scanf("%lf",&num);
		while (temp=getchar() != '\n')
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

void fillMatrix(int **arr,int size1,int size2)
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
}

void fillArr(int *arr,int size)
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
    for(int i=0;i<size;i++) // выбор верхней границы массива
    {
        for(int j=size-1;j>i;--j) // просмотр массива ”снизу” ”вверх”
	    {
            if(arr[j-1]>arr[j]) // условие замены выполнено
            {
            buff=arr[j-1]; // замена j-1 и j элементов
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
                if(arr[i] > arr[j]) // сравниваем отстоящие на gap 	элементы
                { 
                    buff = arr[j];
                    arr[j] = arr[i];
                    arr[i]= buff;
                    flg = 1; // есть еще не рассортированные данные
                }
        } 
        while (flg!=0); // окончание этапа сортировки
}

void insertionSort(int *arr,int size)
{
    // int value;
    // for(int i = 1; i < size; i++) 
    // { 
    //     value = arr[i]; //значение предыдущего элемента
    //     for (int j = i - 1; j >= 0 && arr[j] > value; j--) 
    //     {
    //         arr[j + 1] = arr[j]; //сдвиг всех элементов направо
    //     }
    //     arr[i + 1] = value; //запись в освободившийся или в тот же элемент
    // }

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
    for(int i=0;i<size-1; i++) // выбор исходного элемента к сравнению
    { 
        min=i; 
        for(int j=i+1; j<size; j++) // просмотр массива ”снизу” ”вверх”
            if(arr[min]>arr[j]) 
                min=j; // фиксируем координату элемента в массиве
                buff=arr[i]; // замена min и i элементов
                arr[i]=arr[min];
                arr[min]=buff;
    }
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
 
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
}
 
void mergeSort(int *arr, int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


