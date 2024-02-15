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
                            printf("%d   ",arr[i]);
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
    printf("\n");
    for(int i=0;i<size;i++)
        printf("%4d",arr[i]);
}

void printMatrix(int **arr,int size1,int size2)
{
    printf("\n");
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
            printf("%4d",arr[i][j]); 
        printf("\n");
    }
}

// В одномерном массиве выполнить сортировку четных элементов методом выбора

void selectionSort(int *arr,int size)
{
    int buff;
    int min;
    for(int i=0;i<size-1; i++) // выбор исходного элемента к сравнению
    { 
        min=i; 
        for(int j=i+1; j<size; j++) // просмотр массива ”снизу вверх”
            if(arr[min]>arr[j]) 
                min=j; // фиксируем координату элемента в массиве
                buff=arr[i]; // замена min и i элементов
                arr[i]=arr[min];
                arr[min]=buff;
    }
}

void task_1()
{
	int size;
	int *arr;
    printf("Enter the size of array: ");
	size=inputPosInt();

    arr=(int*)malloc(size*sizeof(int));

    fillArr(arr,size);

    selectionSort(arr,size);

    printArr(arr,size);
    free(arr);
}

// В матрице размером NxM выполнить сортировку строк по возрастанию суммы четных элементов методом слияния

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

void task_2()
{
    int size1,size2;
    int **arr;

    printf("Enter the height of square matrix: ");
	size1=inputPosInt();

    printf("Enter the width of square matrix: ");
	size2=inputPosInt();

    //making and filling array
    arr=(int**)malloc(size1*sizeof(int*));
    for(int i=0;i<size1;i++)
        arr[i]=(int*)malloc(size2*sizeof(int));
    fillMatrix(arr,size1,size2);

    int *sum;
	sum=(int*)malloc(size1*sizeof(int));
    for(int i=0;i<size1;i++)
    {
        sum[i]=0;
        for(int j=0;j<size2;j++)
            if(arr[i][j]%2==0)
                sum[i]+=arr[i][j];
    }

    int *prime_sum;
	prime_sum=(int*)malloc(size1*sizeof(int));
    for(int i=0;i<size1;i++)
            prime_sum[i]=sum[i];

    printf("Sums of even elements in every row: \n");
    for(int i=0;i<size1;i++)
        printf("prime sum[%d]: %4d\n",i+1,prime_sum[i]);

    mergeSort(sum,0,size1-1);   

    printf("\n");
    for(int i=0;i<size1;i++)
        printf("sum[%d]: %4d\n",i+1,sum[i]);
    
    int *temp;
    int buff;
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size1;j++)
            if(sum[i]==prime_sum[j] && j!=i)
            {
                buff=prime_sum[i];
                prime_sum[i]=prime_sum[j];
                prime_sum[j]=buff;

                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    }
    
    printMatrix(arr,size1,size2);
}

int main()
{
    int task=0;
    while(task!=-1)
    {
    printf("Choose number of task(enter -1 for exit): ");
    scanf("%d",&task);
    {
        switch (task)
        {
        case 1:
        {
            printf("\nIn a one-dimensional array, sort the even elements using the selection method\n\n");
            task_1();
            break;
        }
        case 2:
        {
            printf("\nIn an NxM matrix, sort the rows in ascending order by the sum of even elements\n\
using the merge method\n\n");
            task_2();
            break;
        }
        case -1:
        {
            exit(0);
        }
        default:
        printf("Incorrect input number of task, try again");
        }
        getch();
        system("cls");
    }
    }
    getch();
    return 0;
}
